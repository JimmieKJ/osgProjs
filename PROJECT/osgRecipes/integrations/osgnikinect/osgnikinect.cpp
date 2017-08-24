#include "KinectHandler.h"
#include <osg/Point>
#include <osg/Texture2D>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>

class KinectDataDrawer : public KinectHandler
{
public:
    KinectDataDrawer()
    {
        image = new osg::Image;
        image->setImage( KINECT_IMAGE_WIDTH, KINECT_IMAGE_HEIGHT, 1,
                         1, GL_LUMINANCE, GL_UNSIGNED_BYTE, _depthBuffer, osg::Image::NO_DELETE );
        
        skeletonGeom = new osg::Geometry;
        skeletonGeom->setUseDisplayList( false );
        skeletonGeom->setUseVertexBufferObjects( true );
        skeletonGeom->setVertexArray( _points.get() );
        
        osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
        (*colors)[0] = osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f);
        skeletonGeom->setColorArray( colors.get() );
        skeletonGeom->setColorBinding( osg::Geometry::BIND_OVERALL );
        
        osg::ref_ptr<osg::DrawElementsUInt> de = new osg::DrawElementsUInt(GL_LINES);
        // Backbone
        de->push_back( XN_SKEL_TORSO-1 ); de->push_back( XN_SKEL_NECK-1 );
        de->push_back( XN_SKEL_NECK-1 ); de->push_back( XN_SKEL_HEAD-1 );
        // Left arm
        de->push_back( XN_SKEL_LEFT_SHOULDER-1 ); de->push_back( XN_SKEL_LEFT_ELBOW-1 );
        de->push_back( XN_SKEL_LEFT_ELBOW-1 ); de->push_back( XN_SKEL_LEFT_HAND-1 );
        // Right arm
        de->push_back( XN_SKEL_RIGHT_SHOULDER-1 ); de->push_back( XN_SKEL_RIGHT_ELBOW-1 );
        de->push_back( XN_SKEL_RIGHT_ELBOW-1 ); de->push_back( XN_SKEL_RIGHT_HAND-1 );
        // Left leg
        de->push_back( XN_SKEL_LEFT_HIP-1 ); de->push_back( XN_SKEL_LEFT_KNEE-1 );
        de->push_back( XN_SKEL_LEFT_KNEE-1 ); de->push_back( XN_SKEL_LEFT_FOOT-1 );
        // Right leg
        de->push_back( XN_SKEL_RIGHT_HIP-1 ); de->push_back( XN_SKEL_RIGHT_KNEE-1 );
        de->push_back( XN_SKEL_RIGHT_KNEE-1 ); de->push_back( XN_SKEL_RIGHT_FOOT-1 );
        // Others
        de->push_back( XN_SKEL_NECK-1 ); de->push_back( XN_SKEL_LEFT_SHOULDER-1 );
        de->push_back( XN_SKEL_NECK-1 ); de->push_back( XN_SKEL_RIGHT_SHOULDER-1 );
        de->push_back( XN_SKEL_TORSO-1 ); de->push_back( XN_SKEL_LEFT_HIP-1 );
        de->push_back( XN_SKEL_TORSO-1 ); de->push_back( XN_SKEL_RIGHT_HIP-1 );
        
        skeletonGeom->addPrimitiveSet( de.get() );
        skeletonGeom->addPrimitiveSet( new osg::DrawArrays(GL_POINTS, 0, KINECT_SKELETON_COUNT) );
    }
    
    virtual void handleCurrentData()
    {
        image->dirty();
        skeletonGeom->dirtyBound();
    }
    
    osg::ref_ptr<osg::Image> image;
    osg::ref_ptr<osg::Geometry> skeletonGeom;
};

int main( int argc, char** argv )
{
    osg::ref_ptr<KinectDataDrawer> kinectHandler = new KinectDataDrawer;
    kinectHandler->initialize();
    
    // Display the depth image
    osg::ref_ptr<osg::Geode> imageQuad = new osg::Geode;
    imageQuad->addDrawable( osg::createTexturedQuadGeometry(
        osg::Vec3(), osg::Vec3(1.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 1.0f, 0.0f)) );
    
    osg::ref_ptr<osg::Texture2D> tex2D = new osg::Texture2D( kinectHandler->image.get() );
    tex2D->setResizeNonPowerOfTwoHint( false );
    imageQuad->getOrCreateStateSet()->setTextureAttributeAndModes( 0, tex2D.get() );
    
    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
    camera->setReferenceFrame( osg::Transform::ABSOLUTE_RF );
    camera->setRenderOrder( osg::Camera::POST_RENDER );
    camera->setAllowEventFocus( false );
    camera->setViewport( 0, 0, 320, 240 );
    camera->setProjectionMatrix( osg::Matrix::ortho2D(0.0, 1.0, 1.0, 0.0) );
    camera->addChild( imageQuad.get() );
    
    // Display the skeleton geometry
    osg::ref_ptr<osg::Geode> skeletonQuad = new osg::Geode;
    skeletonQuad->setInitialBound( osg::BoundingSphere(osg::Vec3(), 1.0f) );
    skeletonQuad->addDrawable( kinectHandler->skeletonGeom.get() );
    skeletonQuad->getOrCreateStateSet()->setAttributeAndModes( new osg::Point(5.0f) );
    
    // The scene graph and viewer
    osg::ref_ptr<osg::MatrixTransform> root = new osg::MatrixTransform;
    root->addChild( camera.get() );
    root->addChild( skeletonQuad.get() );
    root->getOrCreateStateSet()->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
    
    osg::ref_ptr<osgGA::TrackballManipulator> trackball = new osgGA::TrackballManipulator;
    trackball->setHomePosition( osg::Vec3(0.5f, 0.5f,-2.0f), osg::Vec3(0.5f, 0.5f, 0.5f), osg::Vec3(0.0f,-1.0f, 0.0f) );
    
    osgViewer::Viewer viewer;
    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );
    viewer.addEventHandler( new osgViewer::StatsHandler );
    viewer.addEventHandler( new osgViewer::WindowSizeHandler );
    viewer.addEventHandler( kinectHandler.get() );
    viewer.setCameraManipulator( trackball.get() );
    viewer.setSceneData( root.get() );
    viewer.run();
    
    kinectHandler->quit();
    return 0;
}

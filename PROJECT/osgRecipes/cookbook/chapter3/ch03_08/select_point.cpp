/* -*-c++-*- OpenSceneGraph Cookbook
 * Chapter 3 Recipe 8
 * Author: Wang Rui <wangray84 at gmail dot com>
*/

#include <osg/Geometry>
#include <osg/Geode>
#include <osg/MatrixTransform>
#include <osg/Point>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>

#include "CommonFunctions"

const osg::Vec4 normalColor(1.0f, 1.0f, 1.0f, 1.0f);
const osg::Vec4 selectedColor(1.0f, 0.0f, 0.0f, 1.0f);

class SelectModelHandler : public osgCookBook::PickHandler
{
public:
    SelectModelHandler( osg::Camera* camera )
    : _selector(0), _camera(camera) {}
    
    osg::Geode* createPointSelector()
    {
        osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
        (*colors)[0] = selectedColor;
        
        _selector = new osg::Geometry;
        _selector->setDataVariance( osg::Object::DYNAMIC );
        _selector->setUseDisplayList( false );
        _selector->setUseVertexBufferObjects( true );
        _selector->setVertexArray( new osg::Vec3Array(1) );
        _selector->setColorArray( colors.get() );
        _selector->setColorBinding( osg::Geometry::BIND_OVERALL );
        _selector->addPrimitiveSet( new osg::DrawArrays(GL_POINTS, 0, 1) );
        
        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
        geode->addDrawable( _selector.get() );
        geode->getOrCreateStateSet()->setAttributeAndModes( new osg::Point(10.0f) );
        geode->getOrCreateStateSet()->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
        return geode.release();
    }
    
    virtual void doUserOperations( osgUtil::LineSegmentIntersector::Intersection& result )
    {
        osg::Geometry* geom = dynamic_cast<osg::Geometry*>( result.drawable.get() );
        if ( !geom || !_selector || geom==_selector ) return;
        
        osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>( geom->getVertexArray() );
        osg::Vec3Array* selVertices = dynamic_cast<osg::Vec3Array*>( _selector->getVertexArray() );
        if ( !vertices || !selVertices ) return;
        
        osg::Vec3 point = result.getWorldIntersectPoint();
        osg::Matrix matrix = osg::computeLocalToWorld( result.nodePath );
        
        osg::Matrix vpMatrix;
        if ( _camera.valid() )
        {
            vpMatrix = _camera->getViewMatrix() * _camera->getProjectionMatrix();
            point = point * vpMatrix;
        }
        
        const std::vector<unsigned int>& selIndices = result.indexList;
        for ( unsigned int i=0; i<3 && i<selIndices.size(); ++i )
        {
            unsigned int pos = selIndices[i];
            osg::Vec3 vertex = (*vertices)[pos] * matrix;
            float distance = (vertex * vpMatrix - point).length();
            if ( distance<0.1f )
            {
                selVertices->front() = vertex;
            }
        }
        selVertices->dirty();
        _selector->dirtyBound();
    }
    
protected:
    osg::ref_ptr<osg::Geometry> _selector;
    osg::observer_ptr<osg::Camera> _camera;
};

osg::Geometry* createSimpleGeometry()
{
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
    (*vertices)[0].set(-0.5f,-0.5f,-0.5f);
    (*vertices)[1].set( 0.5f,-0.5f,-0.5f);
    (*vertices)[2].set( 0.5f, 0.5f,-0.5f);
    (*vertices)[3].set(-0.5f, 0.5f,-0.5f);
    (*vertices)[4].set(-0.5f,-0.5f, 0.5f);
    (*vertices)[5].set( 0.5f,-0.5f, 0.5f);
    (*vertices)[6].set( 0.5f, 0.5f, 0.5f);
    (*vertices)[7].set(-0.5f, 0.5f, 0.5f);
    
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
    (*colors)[0] = normalColor;
    
    osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_QUADS, 24);
    (*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
    (*indices)[4] = 4; (*indices)[5] = 5; (*indices)[6] = 6; (*indices)[7] = 7;
    (*indices)[8] = 0; (*indices)[9] = 1; (*indices)[10]= 5; (*indices)[11]= 4;
    (*indices)[12]= 1; (*indices)[13]= 2; (*indices)[14]= 6; (*indices)[15]= 5;
    (*indices)[16]= 2; (*indices)[17]= 3; (*indices)[18]= 7; (*indices)[19]= 6;
    (*indices)[20]= 3; (*indices)[21]= 0; (*indices)[22]= 4; (*indices)[23]= 7;
    
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    geom->setDataVariance( osg::Object::DYNAMIC );
    geom->setUseDisplayList( false );
    geom->setUseVertexBufferObjects( true );
    geom->setVertexArray( vertices.get() );
    geom->setColorArray( colors.get() );
    geom->setColorBinding( osg::Geometry::BIND_OVERALL );
    geom->addPrimitiveSet( indices.get() );
    
    osgUtil::SmoothingVisitor::smooth( *geom );
    return geom.release();
}

int main( int argc, char** argv )
{
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable( createSimpleGeometry() );
    geode->getOrCreateStateSet()->setAttributeAndModes( new osg::PolygonOffset(1.0f, 1.0f) );
    
    osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
    trans->addChild( geode.get() );
    trans->setMatrix( osg::Matrix::translate(0.0f, 0.0f, 1.0f) );
    
    osgViewer::Viewer viewer;
    osg::ref_ptr<SelectModelHandler> selector = new SelectModelHandler( viewer.getCamera() );
    
    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( trans.get() );
    root->addChild( selector->createPointSelector() );  // Caution: It has bound, too
    
    viewer.addEventHandler( selector.get() );
    viewer.setSceneData( root.get() );
    
    osg::CullSettings::CullingMode mode = viewer.getCamera()->getCullingMode();
    viewer.getCamera()->setCullingMode( mode & (~osg::CullSettings::SMALL_FEATURE_CULLING) );
    return viewer.run();
}

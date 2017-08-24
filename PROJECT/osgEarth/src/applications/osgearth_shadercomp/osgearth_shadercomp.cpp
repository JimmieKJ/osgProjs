/* -*-c++-*- */
/* osgEarth - Dynamic map generation toolkit for OpenSceneGraph
* Copyright 2015 Pelican Mapping
* http://osgearth.org
*
* osgEarth is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

/**
 * This is a set of unit tests for osgEarth's shader composition framework.
 *
 * By default, osgEarth uses GL shaders to render the terrain. Shader composition is a
 * mechanism by which you can inject custom shader code into osgEarth's shader program
 * pipeline. This gets around the problem of having to duplicate shader code in order 
 * to add functionality.
 */
#include <osg/Notify>
#include <osg/CullFace>
#include <osgDB/ReadFile>
#include <osgGA/StateSetManipulator>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarth/VirtualProgram>
#include <osgEarth/Registry>
#include <osgEarth/Capabilities>
#include <osgEarth/ShaderUtils>
#include <osgEarthUtil/Controls>

using namespace osgEarth;
using namespace osgEarth::Util::Controls;



int usage( const std::string& msg )
{    
    OE_NOTICE
        << msg << "\n\n"
        << "USAGE: osgearth_shadercomp \n"
        << "           [--test1]    : Run the function injection test \n"
        << "           [--test2]    : Run the accept callback test \n"
        << "           [--test3]    : Run the shader LOD test \n"
        << "           [--test4]    : Run the memory test \n"
        << "           [--test5]    : Run the Program state set test \n"
        << "           [--test6]    : Run the 2-camera test \n"
        << "           [--test7]    : Run the geometry shader injection test \n"
        << std::endl;

    return -1;
}

//Utility:
osg::Geode* makeGeom( float v )
{
    osg::Geode* geode = new osg::Geode();
    osg::Geometry* geom = new osg::Geometry();
    osg::Vec3Array* verts = new osg::Vec3Array();
    verts->push_back( osg::Vec3(v-1, 0, 0) );
    verts->push_back( osg::Vec3(v+1, 0, 0) );
    verts->push_back( osg::Vec3(  0, 0, 2) );
    geom->setVertexArray( verts );
    geom->setUseDisplayList(false);
    geom->setUseVertexBufferObjects(true);
    osg::Vec4Array* colors = new osg::Vec4Array();
    colors->push_back( osg::Vec4(0,0,1,1) );
    geom->setColorArray(colors);
    geom->setColorBinding(osg::Geometry::BIND_OVERALL);
    geom->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLES,0,3));
    geode->addDrawable(geom);
    return geode;
}

//-------------------------------------------------------------------------

// Simple function injection test -- turns the earth gray with a haze.
namespace TEST_1
{
    char s_hazeVertShader[] =
        "#version " GLSL_VERSION_STR "\n"
        "varying vec3 v_pos; \n"
        "void setup_haze(inout vec4 VertexVIEW) \n"
        "{ \n"
        "    v_pos = vec3(VertexVIEW); \n"
        "} \n";

    char s_hazeFragShader[] =
        "#version " GLSL_VERSION_STR "\n"
        "varying vec3 v_pos; \n"
        "void apply_haze(inout vec4 color) \n"
        "{ \n"
        "    float dist = clamp( length(v_pos)/1e7, 0.0, 0.75 ); \n"
        "    color = mix(color, vec4(0.5, 0.5, 0.5, 1.0), dist); \n"
        "} \n";

    osg::StateAttribute* createHaze()
    {
        osgEarth::VirtualProgram* vp = new osgEarth::VirtualProgram();
        vp->setFunction( "setup_haze", s_hazeVertShader, osgEarth::ShaderComp::LOCATION_VERTEX_VIEW );
        vp->setFunction( "apply_haze", s_hazeFragShader, osgEarth::ShaderComp::LOCATION_FRAGMENT_LIGHTING );
        vp->setShaderLogging(true, "shaders.txt");
        return vp;
    }

    osg::Group* run( osg::Node* earth )
    {   
        osg::Group* g = new osg::Group();
        g->addChild( earth );
        g->getOrCreateStateSet()->setAttributeAndModes( createHaze(), osg::StateAttribute::ON );
        return g;
    }
}

//-------------------------------------------------------------------------

// Tests the VirtualProgram's ShaderComp::AcceptCallback
namespace TEST_2
{
    const char* fragShader =
        "#version 110\n"
        "void make_it_red(inout vec4 color) {\n"
        "    color.r = 1.0;\n"
        "}\n";

    struct Acceptor : public ShaderComp::AcceptCallback
    {
        // Return true to activate the shader function.
        bool operator()(const osg::State& state)
        {
            osg::Camera* camera = *state.getGraphicsContext()->getCameras().begin();
            if (!camera) return false;
            osg::Viewport* viewport = camera->getViewport();
            if (!viewport) return false;
            return viewport->width() > 1000;
        }
    };

    osg::Group* run(osg::Node* node)
    {
        VirtualProgram* vp = VirtualProgram::getOrCreate(node->getOrCreateStateSet());
        vp->setFunction("make_it_red", fragShader, ShaderComp::LOCATION_FRAGMENT_LIGHTING, new Acceptor());
        
        osg::Group* g = new osg::Group();
        g->addChild( node );
        return g;
    }
}

//-------------------------------------------------------------------------

// Tests the VirtualProgram's min/max range for functions (shader LOD)
namespace TEST_3
{
    const char* fragShader =
        "#version 110\n"
        "void make_it_red(inout vec4 color) {\n"
        "    color.r = 1.0;\n"
        "}\n";

    osg::Group* run(osg::Node* node)
    {
        float radius = osgEarth::SpatialReference::get("wgs84")->getEllipsoid()->getRadiusEquator();

        VirtualProgram* vp = VirtualProgram::getOrCreate(node->getOrCreateStateSet());

        // Install the shader function:
        vp->setFunction("make_it_red", fragShader, ShaderComp::LOCATION_FRAGMENT_LIGHTING);

        // Set a maximum LOD range for the above function:
        vp->setFunctionMinRange( "make_it_red", 500000 );
        vp->setFunctionMaxRange( "make_it_red", 1000000 );

        osg::Group* g = new osg::Group();

        // Install a callback that will convey the LOD range to the shader LOD.
        g->addCullCallback( new RangeUniformCullCallback() );

        g->addChild( node );
        return g;
    }
}
//-------------------------------------------------------------------

// Tests memory management by installing and uninstalling shader
// functions every frame.

namespace TEST_4
{
    const char* fragShader =
        "#version 110\n"
        "void make_it_red(inout vec4 color) {\n"
        "    color.r *= 1.5;\n"
        "}\n";

    struct Acceptor : public ShaderComp::AcceptCallback
    {
        osg::ref_ptr<osg::Array> _a;

        Acceptor()
        {
            _a = new osg::Vec4Array(1024000);
        }

        bool operator()(const osg::State& state)
        {
            return true;
        }
    };

    struct MyGroup : public osg::Group
    {
        bool _toggle;

        MyGroup() : _toggle(false)
        {
            this->setNumChildrenRequiringUpdateTraversal(1);
        }

        void traverse(osg::NodeVisitor& nv)
        {
            if (nv.getVisitorType() == nv.UPDATE_VISITOR)
            {
                if ( (nv.getFrameStamp()->getFrameNumber() % 2) == 0 )
                {
                    _toggle = !_toggle;

                    VirtualProgram* vp = VirtualProgram::getOrCreate(this->getOrCreateStateSet());
                    if ( _toggle )
                    {
                        vp->setFunction(
                            "make_it_red", fragShader,
                            osgEarth::ShaderComp::LOCATION_FRAGMENT_COLORING,
                            new Acceptor() );
                    }
                    else
                    {
                        vp->removeShader("make_it_red");
                    }
                }
            }
            osg::Group::traverse(nv);
        }
    };

    osg::Group* run(osg::Node* node)
    {
        MyGroup* g = new MyGroup();
        g->addChild( node );
        return g;
    }
}

//-------------------------------------------------------------------------

namespace TEST_5
{
    char s_vert[] =
        "#version " GLSL_VERSION_STR "\n"
        "void main() { \n"
        "    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; \n"
        "} \n";
    char s_frag[] =
        "#version " GLSL_VERSION_STR "\n"
        "void main() { \n"
        "    gl_FragColor = vec4(1.0,0.0,0.0,1.0); \n"
        "} \n";
    char s_vp[] =
        "#version " GLSL_VERSION_STR "\n"
        "void test( inout vec4 color ) { color = vec4(1.0,0.0,0.0,1.0); } \n";

    osg::Group* run()
    {
        osg::Node* n1 = makeGeom( -5 );
        osg::Node* n2 = makeGeom(  5 );

        VirtualProgram* vp = new VirtualProgram();
        vp->setFunction("test", s_vp, ShaderComp::LOCATION_FRAGMENT_LIGHTING);
        n1->getOrCreateStateSet()->setAttributeAndModes( vp, 1 );

        osg::Group* root = new osg::Group();
        root->getOrCreateStateSet()->setRenderBinDetails( 0, "TraversalOrderBin" );
        root->getOrCreateStateSet()->setMode(GL_LIGHTING,0);

        root->addChild( n1 );
        root->addChild( n2 );

        return root;
    }
}

//-------------------------------------------------------------------------

// Tests the VirtualProgram's ShaderComp::AcceptCallback with multiple cameras
// in order to vertify that the State Stack Memory is being properly disabled
// when Accept Callbacks are in play.
namespace TEST_6
{
    const char* fragShader =
        "#version 110\n"
        "void make_it_red(inout vec4 color) {\n"
        "    color.r = 1.0;\n"
        "}\n";
    const char* fragShader2 =
        "#version 110\n"
        "void make_it_blue(inout vec4 color) {\n"
        "    color.b = 1.0;\n"
        "}\n";

    // This acceptor will only include the fragment shader snippet above
    // when the camera's viewport.x == 0. Normally the Program will only
    // be applied once in succession. 
    struct Acceptor : public ShaderComp::AcceptCallback
    {
        Acceptor() : _fn(0) { }

        // Return true to activate the shader function.
        bool operator()(const osg::State& state)
        {
            const osg::Viewport* vp = state.getCurrentViewport();
            return vp && vp->x() == 0.0;
        }

        unsigned _fn;
    };

    osg::Group* run(osg::Node* node)
    {
        osg::Group* group1 = new osg::Group();
        VirtualProgram* vp1 = VirtualProgram::getOrCreate(group1->getOrCreateStateSet());
        vp1->setFunction("make_it_red", fragShader, ShaderComp::LOCATION_FRAGMENT_LIGHTING, new Acceptor());
        vp1->setAcceptCallbacksVaryPerFrame(true);
        group1->addChild( node );

        osg::Camera* cam1 = new osg::Camera();
        cam1->setViewport(0, 0, 200, 200);
        cam1->addChild( group1 );

        osg::Camera* cam2 = new osg::Camera();
        cam2->setViewport(201, 0, 200, 200);
        cam2->addChild( group1 );        

        osg::Group* group2 = new osg::Group();
        VirtualProgram* vp2 =  VirtualProgram::getOrCreate(group2->getOrCreateStateSet());
        vp2->setFunction("make_it_blue", fragShader2, ShaderComp::LOCATION_FRAGMENT_LIGHTING);
        group2->addChild( node );

        osg::Camera* cam3 = new osg::Camera();
        cam3->setViewport(0, 201, 200, 200);
        cam3->addChild( group2 );

        osg::Camera* cam4 = new osg::Camera();
        cam4->setViewport(201, 201, 200, 200);
        cam4->addChild( group2 );
        
        osg::Group* g = new osg::Group();
        g->addChild( cam1 );
        g->addChild( cam2 );
        g->addChild( cam3 );
        g->addChild( cam4 );

        return g;
    }
}

//-------------------------------------------------------------------------

namespace TEST_7
{
    const char* vert =
        "#version 120\n"
        "out float oe_red; \n"
        "void myVertShader(inout vec4 vertex) { \n"
        "    oe_red = 1.0; \n"
        "} \n";

    const char* geom =
        "#version 330\n"
        "#pragma vp_name ShaderComp Test 7 Geom Shader (Triangle Viewer)\n"

        "layout(triangles) in; \n"
        "layout(triangle_strip) out; \n"
        "layout(max_vertices = 3) out; \n"
        
        "void VP_LoadVertex(in int); \n"
        "void VP_EmitVertex(); \n"

        "uniform float osg_FrameTime; \n"

        "void myGeomShader() \n"
        "{ \n"
        "    float strength = 0.25 + sin(osg_FrameTime*2.0)*0.25; \n"
        "    vec4 cen = (gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position)/3.0; \n"        
        "    for(int i=0; i < 3; ++i ) \n"
        "    { \n"
        "        VP_LoadVertex(i); \n"
        "        vec4 pos = gl_in[i].gl_Position; \n"
        "        pos += vec4(normalize(cen.xyz-pos.xyz) * distance(cen, pos) * strength, 0.0); \n"
        "        gl_Position = pos; \n"
        "        VP_EmitVertex(); \n"
        "    } \n"
        "    EndPrimitive(); \n"
        "} \n";

    const char* frag =
        "#version 120\n"
        "in float oe_red; \n"
        "void myFragShader(inout vec4 color) \n"
        "{ \n"
        "    // nop\n"
        "} \n";

    osg::StateAttribute* createVP()
    {
        osgEarth::VirtualProgram* vp = new osgEarth::VirtualProgram();
        vp->setFunction( "myVertShader", vert, osgEarth::ShaderComp::LOCATION_VERTEX_MODEL );
        vp->setFunction( "myGeomShader", geom, osgEarth::ShaderComp::LOCATION_GEOMETRY );
        vp->setFunction( "myFragShader", frag, osgEarth::ShaderComp::LOCATION_FRAGMENT_COLORING );
        vp->setShaderLogging(true, "test7.glsl");
        return vp;
    }

    osg::Group* run( osg::Node* earth )
    {   
        osg::Group* g = new osg::Group();
        g->addChild( earth );
        g->getOrCreateStateSet()->setAttribute( createVP() );
        g->getOrCreateStateSet()->setAttributeAndModes(new osg::CullFace(osg::CullFace::BACK));
        return g;
    }
}

//-------------------------------------------------------------------------

int main(int argc, char** argv)
{
    osg::ArgumentParser arguments(&argc,argv);
    osgViewer::Viewer viewer(arguments);

    bool test1 = arguments.read("--test1");
    bool test2 = arguments.read("--test2");
    bool test3 = arguments.read("--test3");
    bool test4 = arguments.read("--test4");
    bool test5 = arguments.read("--test5");
    bool test6 = arguments.read("--test6");
    bool test7 = arguments.read("--test7");
    bool ok    = test1 || test2 || test3 || test4 || test5 || test6 || test7;

    if ( !ok )
    {
        return usage("");
    }

    osg::Group* root = new osg::Group();
    viewer.setSceneData( root );

    // add a canvas:
    ControlCanvas* canvas = new ControlCanvas();
    root->addChild( canvas );

    // and a label:
    LabelControl* label = new LabelControl();
    canvas->addControl(label);

    if ( test1 || test2 || test3 || test4 || test6 )
    {
        osg::Node* earthNode = osgDB::readNodeFile( "gdal_tiff.earth" );
        if (!earthNode)
        {
            return usage( "Unable to load earth model." );
        }

        if ( test1 )
        {
            root->addChild( TEST_1::run(earthNode) );
            label->setText( "Function injection test: the map appears hazy at high altitude." );
        }
        else if ( test2 )
        {
            root->addChild( TEST_2::run(earthNode) );
            label->setText( "Accept callback test: the map turns red when viewport width > 1000" );
        }
        else if ( test3 )
        {
            root->addChild( TEST_3::run(earthNode) );
            label->setText( "Shader LOD test: the map turns red between 500K and 1M meters altitude" );
        }
        else if ( test4 )
        {
            root->addChild( TEST_4::run(earthNode) );
            label->setText("Memory management test; monitor memory for stability");
        }
        else if ( test6 )
        {
            root->addChild( TEST_6::run(earthNode) );
            label->setText("State Memory Stack test; top row, both=blue. bottom left=red, bottom right=normal.");
        }
        
        viewer.setCameraManipulator( new osgEarth::Util::EarthManipulator() );
    }
    else if ( test5 )
    {
        osgEarth::Registry::instance()->getCapabilities();
        root->addChild( TEST_5::run() );
        label->setText( "Leakage test: red tri on the left, blue on the right." );
    }
    else if ( test7 )
    {
        root->addChild( TEST_7::run( osgDB::readNodeFiles(arguments) ) );
        label->setText("Geometry Shader Injection Test.");
    }


    // add some stock OSG handlers:
    viewer.addEventHandler(new osgViewer::StatsHandler());
    viewer.addEventHandler(new osgViewer::WindowSizeHandler());
    viewer.addEventHandler(new osgViewer::ThreadingHandler());
    viewer.addEventHandler(new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()));

    return viewer.run();
}

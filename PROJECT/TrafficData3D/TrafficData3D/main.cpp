#include "TrafficData3D_H.h"

#include "trafficdata3d.h"
#include <QtWidgets/QApplication>

#include <../../TDRenderingExtensions/RenderingSky.h>
#include <../../TDSceneTools/MouseViewCoords.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TrafficData3D w;

	osg::ref_ptr<osgViewer::Viewer> viewer=new osgViewer::Viewer();
	viewer->setThreadingModel(viewer->SingleThreaded);
	viewer->setRunFrameScheme( viewer->ON_DEMAND );

	QWidget* viewerWidget = new osgEarth::QtGui::ViewerWidget(viewer );
	w.setCentralWidget(viewerWidget);

	osg::ref_ptr<osgEarth::Util::EarthManipulator> earthManipulator=new osgEarth::Util::EarthManipulator();
	viewer->setCameraManipulator(earthManipulator);

	osg::ref_ptr<osg::Group> rootNode=new osg::Group();
	viewer->setSceneData(rootNode);

	osg::ref_ptr<osgEarth::MapNode> mapNode=osgEarth::MapNode::findMapNode(osgDB::readNodeFile("D://google.earth"));
	rootNode->addChild(mapNode);

	//添加天气
	TDRenderingExtensions::RenderingSky *sky=new TDRenderingExtensions::RenderingSky(mapNode,viewer);
	sky->skyNodeCallback->bSkyNodeAnimation=false;
	osgEarth::insertGroup(sky->skyNode,mapNode);

	//添加状态
	TDSceneTools::MouseViewCoords* mvCoords=new TDSceneTools::MouseViewCoords( viewer, rootNode, mapNode, earthManipulator);

	w.show();
	return a.exec();
}

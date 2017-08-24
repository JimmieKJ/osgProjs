#include "MouseViewCoords.h"
#include <Windows.h>

using namespace std;
using namespace TDSceneTools;

using namespace osgEarth::Symbology;
using namespace osgEarth::Util::Controls;

void unicodeToUTF8(const std::wstring &src, std::string& result)
{
	int n = WideCharToMultiByte(CP_UTF8, 0, src.c_str(), -1, 0, 0, 0, 0);
	result.resize(n);
	::WideCharToMultiByte(CP_UTF8, 0, src.c_str(), -1, (char*)result.c_str(), result.length(), 0, 0);
}

void unicodeToGB2312(const std::wstring& wstr, std::string& result)
{
	int n = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, 0, 0, 0, 0);
	result.resize(n);
	::WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, (char*)result.c_str(), n, 0, 0);
}

void utf8ToUnicode(const std::string& src, std::wstring& result)
{
	int n = MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, NULL, 0);
	result.resize(n);
	::MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, (LPWSTR)result.c_str(), result.length());
}

void gb2312ToUnicode(const std::string& src, std::wstring& result)
{
	int n = MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, NULL, 0);
	result.resize(n);
	::MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, (LPWSTR)result.c_str(), result.length());
}

void gb2312ToUtf8(const std::string& src, std::string& result)
{
	std::wstring strWideChar;
	gb2312ToUnicode(src, strWideChar);
	unicodeToUTF8(strWideChar, result);
}

MouseViewCoords::MouseViewCoordsEventHandler::MouseViewCoordsEventHandler(osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgEarth::Util::EarthManipulator> em, osg::ref_ptr<osgEarth::Util::Controls::Grid> grid,osg::Vec2 vp)
{
	_bMouseViewCoords = false;

	_mapNode = mapNode;
	_em = em;
	_grid = grid;

	_grid->setBackColor(osg::Vec4f(0.0, 0.0, 0.0, 0.3));
	_grid->setSize(1000, 75);

	_mouseLabel = new osgEarth::Util::Controls::LabelControl();
	_mouseLabel->setFont(osgText::readFontFile( "D:/PROJECT/TrafficData3D/Data/simhei.ttf"));
	_mouseLabel->setEncoding(osgText::String::ENCODING_UTF8);
	_mouseLabel->setFontSize(18);
	_grid->setControl(0, 0, _mouseLabel);

	_viewLabel = new osgEarth::Util::Controls::LabelControl();
	_viewLabel->setFont(osgText::readFontFile( "D:/PROJECT/TrafficData3D/Data/simhei.ttf"));
	_viewLabel->setEncoding(osgText::String::ENCODING_UTF8);
	_viewLabel->setFontSize(18);
	_grid->setControl(0, 1, _viewLabel);

	_grid->setPosition(vp.x() - 1000, vp.y() - 65);

}

bool MouseViewCoords::MouseViewCoordsEventHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	//if (!_bMouseViewCoords)
	//	return false;

	if (ea.getEventType() == ea.RESIZE)
	{
		_grid->setPosition(ea.getWindowWidth() - 1000, ea.getWindowHeight() - 65);
	}

	if (ea.getEventType() == ea.FRAME)
	{
		_grid->setVisible(true);

		std::string strUtf8 = "";
		char wsrc[512];
		osgEarth::Viewpoint vm = _em->getViewpoint();

		sprintf(wsrc, "视点：  经度：%.3f， 纬度：%.3f， 视点高度：%.1f米， 水平视角：%.3f， 垂直视角：%.3f", vm.focalPoint()->x(),vm.focalPoint()->y(), vm.getRange(), vm.getHeading(), vm.getPitch()); 

		gb2312ToUtf8(std::string(wsrc), strUtf8);
		_viewLabel->setText(strUtf8.c_str());
	}

	if (ea.getEventType() == ea.MOVE || ea.getEventType() == ea.DRAG)
	{
		std::string strUtf8 = "";
		osg::Vec3d world;

		if (_mapNode->getTerrain()->getWorldCoordsUnderMouse(aa.asView(), ea.getX(), ea.getY(), world))
		{
			osgEarth::GeoPoint _p;
			_p.fromWorld(_mapNode->getMapSRS(), world);

			char wsrc[512];
			sprintf(wsrc, "鼠标：  经度：%.6f， 纬度：%.6f， 海拔：%.6f米", _p.x(), _p.y(), _p.z());

			gb2312ToUtf8(std::string(wsrc), strUtf8);
			_mouseLabel->setText(strUtf8.c_str());
		}
		else
		{
			std::string wsrc = "";
			gb2312ToUtf8(std::string(wsrc), strUtf8);
			_mouseLabel->setText(strUtf8.c_str());
		}
	}



	return false;
}

void MouseViewCoords::MouseViewCoordsEventHandler::setBMouseViewCoords(bool bMouseViewCoords)
{
	_bMouseViewCoords = bMouseViewCoords;
}

bool MouseViewCoords::MouseViewCoordsEventHandler::getBMouseViewCoords()
{
	return _bMouseViewCoords;
}

MouseViewCoords::MouseViewCoords(osg::ref_ptr<osgViewer::Viewer> mainViewer, osg::ref_ptr<osg::Group> mainGroup, osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgEarth::Util::EarthManipulator> em)
{
	_bMouseViewCoords = false;

	_mainViewer = mainViewer;
	_mainGroup = mainGroup;
	_mainCanvas =osgEarth::Util::Controls::ControlCanvas::getOrCreate(_mainViewer);

	_mainGrid = new osgEarth::Util::Controls::Grid();

	_mouseViewCoordsEventHandler = new MouseViewCoordsEventHandler(mapNode, em, _mainGrid,osg::Vec2(_mainViewer->getCamera()->getViewport()->x(),_mainViewer->getCamera()->getViewport()->y()));
	_mainViewer->addEventHandler(_mouseViewCoordsEventHandler);


	_mainCanvas->addChild(_mainGrid);
}

void MouseViewCoords::setBMouseViewCoords(bool bMouseViewCoords)
{
	_bMouseViewCoords = bMouseViewCoords;

	_setMouseViewCoords();
	_mouseViewCoordsEventHandler->setBMouseViewCoords(bMouseViewCoords);
}

bool MouseViewCoords::getBMouseViewCoords()
{
	return _bMouseViewCoords;
}

void MouseViewCoords::_setMouseViewCoords()
{
	//if (_bMouseViewCoords)
	//{
	//	_w = _mainViewer->getCamera()->getViewport()->width();
	//	_h = _mainViewer->getCamera()->getViewport()->height();
	//	_mainGrid->setPosition(_w - 500, _h - 65);

	//	_mainGroup->addChild(_mainCanvas);
	//}
	//else
	//{
	//	_mainGroup->removeChild(_mainCanvas);
	//}
}
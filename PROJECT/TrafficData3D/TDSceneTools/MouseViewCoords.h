#ifndef MOUSE_VIEW_COORDS_H
#define MOUSE_VIEW_COORDS_H

#include <TrafficData3D_EXPORT.h>
#include <TrafficData3D_H.h>

namespace TDSceneTools
{
	class TRAFFICDATA_API MouseViewCoords
	{
	private:
		class MouseViewCoordsEventHandler :public osgGA::GUIEventHandler
		{
		public:
			MouseViewCoordsEventHandler(osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgEarth::Util::EarthManipulator> em, osg::ref_ptr<osgEarth::Util::Controls::Grid> grid,osg::Vec2 vp);
			virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
			void setBMouseViewCoords(bool bMouseViewCoords);
			bool getBMouseViewCoords();
		private:
			bool _bMouseViewCoords;
			std::string _EarthPath;

			osg::ref_ptr<osgEarth::MapNode>  _mapNode;
			osg::ref_ptr<osgEarth::Util::EarthManipulator> _em;
			osg::ref_ptr<osgEarth::Util::Controls::Grid> _grid;
			osgEarth::Util::Controls::LabelControl* _mouseLabel;
			osgEarth::Util::Controls::LabelControl* _viewLabel;
		};

	public:
		MouseViewCoords(osg::ref_ptr<osgViewer::Viewer> mainViewer, osg::ref_ptr<osg::Group> mainGroup, osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgEarth::Util::EarthManipulator> em);
		void setBMouseViewCoords(bool bMouseViewCoords);
		bool getBMouseViewCoords();

	private:
		void _setMouseViewCoords();

	private:
		bool _bMouseViewCoords;

		osg::ref_ptr<osgEarth::Util::Controls::ControlCanvas> _mainCanvas;
		osg::ref_ptr<osgEarth::Util::Controls::Grid> _mainGrid;
		//osgEarth::Util::Controls::ControlCanvas* _mainCanvas;
		//osgEarth::Util::Controls::Grid*  _mainGrid;

		osg::ref_ptr<osgViewer::Viewer> _mainViewer;
		osg::ref_ptr<osg::Group> _mainGroup;

		MouseViewCoordsEventHandler* _mouseViewCoordsEventHandler;

		int _w, _h;

	};
}

#endif
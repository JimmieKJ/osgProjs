#ifndef RENDERING_SKY_H
#define RENDERING_SKY_H

#include <TrafficData3D_EXPORT.h>
#include <TrafficData3D_H.h>

namespace TDRenderingExtensions
{
	class TRAFFICDATA_API RenderingSky
	{
	private:
		class SkyNodeCallback :public osg::NodeCallback
		{
		public:
			SkyNodeCallback();
			virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

		private:
			double _accumTime;
			double _prevTime;


		public:
			bool bSkyNodeAnimation;
			double rate;
			double time_hours;
			float ambient;
		};

	public:
		RenderingSky(osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgViewer::Viewer> viewer);
	private:
		void _initSkyNode(osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgViewer::Viewer> viewer);

	public:
		osg::ref_ptr<osgEarth::Drivers::SimpleSky::SkyNode> skyNode;
		SkyNodeCallback* skyNodeCallback;
	};
}
#endif
#include "RenderingSky.h"

using namespace TDRenderingExtensions;

RenderingSky::SkyNodeCallback::SkyNodeCallback()
{
	_prevTime = -1;
	_accumTime = 0.0;

	bSkyNodeAnimation = 1;
	rate = 30;
	time_hours = 8.0f;
	ambient = 0;
}

void RenderingSky::SkyNodeCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	osg::ref_ptr<osgEarth::Util::SkyNode> skyNode = dynamic_cast<osgEarth::Util::SkyNode*>(node);
	if (skyNode)
	{
		if (bSkyNodeAnimation)
		{
			double time = nv->getFrameStamp()->getSimulationTime();
			if (_prevTime > 0)
			{
				osgEarth::TimeStamp t = skyNode->getDateTime().asTimeStamp();
				double delta = ceil(time - _prevTime)*rate;
				_accumTime += delta;
				if (_accumTime > 1.0)
				{
					double deltaS = floor(_accumTime);
					_accumTime -= deltaS;
					t += deltaS;

					skyNode->setDateTime(t);
					time_hours=skyNode->getDateTime().hours();
				}
			}
			_prevTime = time;
		}
		else
		{
			skyNode->setDateTime(osgEarth::DateTime::DateTime(2000, 1, 1, time_hours));
		}

		skyNode->getSunLight()->setAmbient(osg::Vec4(ambient, ambient, ambient, 1));
	}
	traverse(node, nv);
}

RenderingSky::RenderingSky(osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgViewer::Viewer> viewer)
{
	osgEarth::Drivers::SimpleSky::SimpleSkyOptions sky;
	skyNode = osgEarth::Drivers::SimpleSky::SkyNode::create(sky, mapNode);

	skyNodeCallback = new SkyNodeCallback();

	_initSkyNode(mapNode, viewer);
}

void RenderingSky::_initSkyNode(osg::ref_ptr<osgEarth::MapNode> mapNode, osg::ref_ptr<osgViewer::Viewer> viewer)
{
	//skyNode->setDateTime(osgEarth::DateTime::DateTime(2000, 1, 1, 8.0f));

	skyNode->setMoonVisible(true);
	skyNode->setSunVisible(true);
	skyNode->setStarsVisible(true);

	skyNode->attach(viewer, 0);

	skyNode->setUpdateCallback(skyNodeCallback);
}
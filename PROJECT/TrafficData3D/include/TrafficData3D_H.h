#ifndef TRAFFICDATA3D_H_H
#define TRAFFICDATA3D_H_H

#include <osg/BlendFunc>
#include <osg/Notify>
#include <osg/ComputeBoundsVisitor>
#include <osg/PositionAttitudeTransform>
#include <osg/AnimationPath>
#include <osg/ImageStream>
#include <osg/Geode>
#include <osg/TextureRectangle>
#include <osg/ImageStream>
#include <osg/Depth>

#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgDB/WriteFile>
#include <osgDB/ReadFile>
#include <osgDB/FileUtils>

#include <osgGA/EventVisitor>
#include <osgGA/StateSetManipulator>
#include <osgGA/NodeTrackerManipulator>

#include <osgEarth/MapNode>

#include <osgEarthUtil/Controls>
#include <osgEarthUtil/ExampleResources>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Sky>
#include <osgEarthUtil/Shadowing>
#include <osgEarthUtil/GeodeticGraticule>
#include <osgEarthUtil/LatLongFormatter>
#include <osgEarthUtil/AnnotationEvents>
#include <osgEarthUtil/AutoClipPlaneHandler>
#include <osgEarthUtil/BrightnessContrastColorFilter>
#include <osgEarthUtil/CMYKColorFilter>
#include <osgEarthUtil/GammaColorFilter>
#include <osgEarthUtil/HSLColorFilter>
#include <osgEarthUtil/RGBColorFilter>
#include <osgEarthUtil/ChromaKeyColorFilter>

#ifdef TrafficData3D_USEQT
#include <osgEarthQt/ViewerWidget>
#endif

#include <osgEarthDrivers/sky_simple/SimpleSkyOptions>

#endif
/**********************************************************\

  Auto-generated osgWeb.h

  This file contains the auto-generated main plugin object
  implementation for the osgWeb project

\**********************************************************/
#ifndef H_osgWebPLUGIN
#define H_osgWebPLUGIN

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"

#include "PluginCore.h"

#include "PluginWindowWin.h"
#include <osg/Group>
#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osgViewer/api/Win32/GraphicsWindowWin32>

class RenderingThread : public OpenThreads::Thread
{
public:
    RenderingThread()
    : OpenThreads::Thread(), viewerPtr(0) {}
    
    virtual ~RenderingThread()
    {
        if ( viewerPtr ) viewerPtr->setDone( true );
        while( isRunning() )
            OpenThreads::Thread::YieldCurrentThread();
    }
    
    virtual void run()
    {
        if ( !viewerPtr ) return;
        do
        {
            viewerPtr->frame();
        } while ( !testCancel() && !viewerPtr->done() );
        viewerPtr = NULL;
    }
    
    osgViewer::Viewer* viewerPtr;
};

class CommandHandler : public osgGA::GUIEventHandler
{
public:
	void addCommand( const std::string& cmd )
	{
		OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mutex);
		commands.push_back( cmd );
	}

	virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
	{
		if ( ea.getEventType()!=osgGA::GUIEventAdapter::FRAME )
			return false;

		std::vector<std::string> localCommands;
		{
			OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mutex);
			localCommands.swap( commands );
		}

		osgViewer::Viewer* viewer = static_cast<osgViewer::Viewer*>( &aa );
		if ( viewer && viewer->getSceneData() )
		{
			osg::Group* root = dynamic_cast<osg::Group*>( viewer->getSceneData() );
			if ( root )
			{
				for ( unsigned int i=0; i<localCommands.size(); ++i )
				{
					root->removeChildren( 0, root->getNumChildren() );
					root->addChild( osgDB::readNodeFile(localCommands[i]) );
				}
			}
		}
		return false;
	}

	std::vector<std::string> commands;
	OpenThreads::Mutex mutex;
};

FB_FORWARD_PTR(osgWeb)
class osgWeb : public FB::PluginCore
{
public:
    static void StaticInitialize();
    static void StaticDeinitialize();

public:
    osgWeb();
    virtual ~osgWeb();

public:
    void onPluginReady();
    void shutdown();
    virtual FB::JSAPIPtr createJSAPI();
    // If you want your plugin to always be windowless, set this to true
    // If you want your plugin to be optionally windowless based on the
    // value of the "windowless" param tag, remove this method or return
    // FB::PluginCore::isWindowless()
    virtual bool isWindowless() { return false; }

    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::MouseDownEvent, onMouseDown, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *);
    virtual bool onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *);
    virtual bool onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *);
    virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *);
    virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/
    
    osg::ref_ptr<CommandHandler> _commandHandler;
    osgViewer::Viewer _viewer;
    RenderingThread* _thread;
};


#endif


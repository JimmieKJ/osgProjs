# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgGA

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/PROJECT/OpenSceneGraph-3.5.1")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgGAd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgGA.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgGAs.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgGArd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgGAd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgGA.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgGAs.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgGArd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgGA" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/AnimationPathManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/CameraViewSwitchManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/DriveManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/Device"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/Event"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/EventHandler"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/EventQueue"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/EventVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/FirstPersonManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/FlightManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/GUIActionAdapter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/GUIEventAdapter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/GUIEventHandler"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/KeySwitchMatrixManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/CameraManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/MultiTouchTrackballManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/NodeTrackerManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/OrbitManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/StandardManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/SphericalManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/StateSetManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/TerrainManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/TrackballManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/UFOManipulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/Widget"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgGA/Version"
    )
endif()


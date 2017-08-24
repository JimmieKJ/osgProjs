# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgManipulator

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgManipulatord.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgManipulator.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgManipulators.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgManipulatorrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgManipulatord.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgManipulator.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgManipulators.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgManipulatorrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgManipulator" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/AntiSquish"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Command"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/CommandManager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Constraint"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Dragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Projector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/RotateCylinderDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/RotateSphereDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Scale1DDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Scale2DDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/ScaleAxisDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Selection"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TabBoxDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TabBoxTrackballDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TabPlaneDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TabPlaneTrackballDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TrackballDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Translate1DDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Translate2DDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TranslateAxisDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/TranslatePlaneDragger"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgManipulator/Version"
    )
endif()


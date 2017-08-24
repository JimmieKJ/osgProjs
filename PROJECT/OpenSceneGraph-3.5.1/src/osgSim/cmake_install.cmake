# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgSim

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgSimd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgSim.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgSims.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgSimrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgSimd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgSim.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgSims.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgSimrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgSim" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/BlinkSequence"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ColorRange"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/DOFTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ElevationSlice"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/HeightAboveTerrain"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/GeographicLocation"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/Impostor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ImpostorSprite"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/InsertImpostorsVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/LightPoint"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/LightPointNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/LightPointSystem"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/LineOfSight"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/MultiSwitch"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/OverlayNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ObjectRecordData"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ScalarBar"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ScalarsToColors"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/Sector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/ShapeAttribute"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/SphereSegment"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/Version"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgSim/VisibilityGroup"
    )
endif()


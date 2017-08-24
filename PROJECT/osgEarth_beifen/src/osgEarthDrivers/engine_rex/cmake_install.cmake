# Install script for directory: D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/OSGEARTH")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/osgPlugins-3.5.1" TYPE MODULE FILES "D:/PROJECT/osgEarth/lib/Debug/osgdb_osgearth_engine_rexd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/osgPlugins-3.5.1" TYPE MODULE FILES "D:/PROJECT/osgEarth/lib/Release/osgdb_osgearth_engine_rex.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/osgPlugins-3.5.1" TYPE MODULE FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgdb_osgearth_engine_rexs.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/osgPlugins-3.5.1" TYPE MODULE FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgdb_osgearth_engine_rexrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarthDrivers/engine_rex" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/Common"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/GeometryPool"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/Shaders"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/RexTerrainEngineNode"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/RexTerrainEngineOptions"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/LoadTileData"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/MaskGenerator"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/MPTexture"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/QuickReleaseGLObjects"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/RenderBindings"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/SurfaceNode"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/TileDrawable"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/EngineContext"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/TileNode"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/TileNodeRegistry"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/Loader"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/Unloader"
    "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/SelectionInfo"
    )
endif()


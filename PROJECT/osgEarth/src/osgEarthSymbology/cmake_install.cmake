# Install script for directory: D:/PROJECT/osgEarth/src/osgEarthSymbology

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthSymbologyd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthSymbology.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthSymbologys.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthSymbologyrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthSymbologyd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthSymbology.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthSymbologys.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthSymbologyrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarthSymbology" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/AGG.h"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/AltitudeSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/BillboardResource"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/BillboardSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Common"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Color"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/CoverageSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/CssUtils"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Expression"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/ExtrusionSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Fill"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Geometry"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/GeometryFactory"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/GEOS"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/GeometryRasterizer"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/IconResource"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/IconSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/InstanceResource"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/InstanceSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/LineSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/MarkerResource"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/MarkerSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/MeshConsolidator"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/MeshFlattener"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/MeshSubdivider"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/ModelResource"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/ModelSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/PointSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/PolygonSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Query"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/RenderSymbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Resource"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/ResourceCache"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/ResourceLibrary"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Skins"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/StencilVolumeNode"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Stroke"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Style"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/StyleSelector"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/StyleSheet"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Symbol"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/Tags"
    "D:/PROJECT/osgEarth/src/osgEarthSymbology/TextSymbol"
    )
endif()


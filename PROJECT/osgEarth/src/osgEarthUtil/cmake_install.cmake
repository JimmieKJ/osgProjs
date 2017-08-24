# Install script for directory: D:/PROJECT/osgEarth/src/osgEarthUtil

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthUtild.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthUtil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthUtils.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthUtilrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthUtild.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthUtil.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthUtils.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthUtilrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarthUtil" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ActivityMonitorTool"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/AnnotationEvents"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/AutoClipPlaneHandler"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ArcGIS"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/AtlasBuilder"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Common"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Controls"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ContourMap"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ClampCallback"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/DataScanner"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/EarthManipulator"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Ephemeris"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ExampleResources"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Export"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/FeatureQueryTool"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Fog"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Formatter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GeodeticGraticule"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GraticuleExtension"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GraticuleNode"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GraticuleOptions"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GraticuleTerrainEffect"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/HTM"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/LatLongFormatter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/LineOfSight"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/LinearLineOfSight"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/LODBlending"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/LogarithmicDepthBuffer"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/MeasureTool"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/MGRSFormatter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/MGRSGraticule"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/MouseCoordsTool"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ObjectLocator"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Ocean"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/PolyhedralLineOfSight"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/RadialLineOfSight"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/RTTPicker"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Shaders"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Shadowing"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/SimplexNoise"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/SimplePager"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/Sky"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/SpatialData"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/StarData"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TerrainProfile"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TileIndex"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TileIndexBuilder"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TFS"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TFSPackager"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TMS"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TMSBackFiller"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/TMSPackager"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/UTMGraticule"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/VerticalScale"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/WFS"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/WMS"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/BrightnessContrastColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/CMYKColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GammaColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/GLSLColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/HSLColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/RGBColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/ChromaKeyColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarthUtil/NightColorFilter"
    )
endif()


# Install script for directory: D:/PROJECT/osgEarth/src/osgEarthFeatures

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthFeaturesd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthFeatures.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthFeaturess.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthFeaturesrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthFeaturesd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthFeatures.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthFeaturess.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthFeaturesrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarthFeatures" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/AltitudeFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/BufferFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/BuildGeometryFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/BuildTextFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/CentroidFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/Common"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/ConvertTypeFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/CropFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/ExtrudeGeometryFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/Feature"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureCursor"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureDisplayLayout"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureDrawSet"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureIndex"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureListSource"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureModelGraph"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureModelSource"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureSource"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureSourceIndexNode"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FeatureTileSource"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/Filter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/FilterContext"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/GeometryCompiler"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/GeometryUtils"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/LabelSource"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/OgrUtils"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/OptimizerHints"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/PolygonizeLines"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/ResampleFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/ScaleFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/Session"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/ScatterFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/Script"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/ScriptEngine"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/SubstituteModelFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/TessellateOperator"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/TextSymbolizer"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/TransformFilter"
    "D:/PROJECT/osgEarth/src/osgEarthFeatures/VirtualFeatureSource"
    )
endif()


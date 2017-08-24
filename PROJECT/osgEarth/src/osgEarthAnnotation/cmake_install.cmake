# Install script for directory: D:/PROJECT/osgEarth/src/osgEarthAnnotation

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthAnnotationd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthAnnotation.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthAnnotations.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthAnnotationrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthAnnotationd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthAnnotation.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthAnnotations.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthAnnotationrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarthAnnotation" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationSettings"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationEditing"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationExtension"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationData"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationRegistry"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/AnnotationUtils"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/CircleNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/Common"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/Decoration"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/Draggers"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/EllipseNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/Export"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/FeatureNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/FeatureEditing"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/GeoPositionNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/GeoPositionNodeAutoScaler"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/LocalGeometryNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/HighlightDecoration"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/ImageOverlay"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/ImageOverlayEditor"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/LabelNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/ModelNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/PlaceNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/RectangleNode"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/ScaleDecoration"
    "D:/PROJECT/osgEarth/src/osgEarthAnnotation/TrackNode"
    )
endif()


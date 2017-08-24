# Install script for directory: D:/PROJECT/osgEarth/src/osgEarth

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Release/osgEarth.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarths.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Release/osgEarth.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarths.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarth" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarth/AlphaEffect"
    "D:/PROJECT/osgEarth/src/osgEarth/AutoScale"
    "D:/PROJECT/osgEarth/src/osgEarth/Bounds"
    "D:/PROJECT/osgEarth/src/osgEarth/Cache"
    "D:/PROJECT/osgEarth/src/osgEarth/CacheEstimator"
    "D:/PROJECT/osgEarth/src/osgEarth/CacheBin"
    "D:/PROJECT/osgEarth/src/osgEarth/CachePolicy"
    "D:/PROJECT/osgEarth/src/osgEarth/CacheSeed"
    "D:/PROJECT/osgEarth/src/osgEarth/Capabilities"
    "D:/PROJECT/osgEarth/src/osgEarth/Clamping"
    "D:/PROJECT/osgEarth/src/osgEarth/ClampableNode"
    "D:/PROJECT/osgEarth/src/osgEarth/ClampingTechnique"
    "D:/PROJECT/osgEarth/src/osgEarth/ColorFilter"
    "D:/PROJECT/osgEarth/src/osgEarth/Common"
    "D:/PROJECT/osgEarth/src/osgEarth/CompositeTileSource"
    "D:/PROJECT/osgEarth/src/osgEarth/Config"
    "D:/PROJECT/osgEarth/src/osgEarth/Containers"
    "D:/PROJECT/osgEarth/src/osgEarth/Cube"
    "D:/PROJECT/osgEarth/src/osgEarth/CullingUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/DateTime"
    "D:/PROJECT/osgEarth/src/osgEarth/DateTimeRange"
    "D:/PROJECT/osgEarth/src/osgEarth/Decluttering"
    "D:/PROJECT/osgEarth/src/osgEarth/DepthOffset"
    "D:/PROJECT/osgEarth/src/osgEarth/DPLineSegmentIntersector"
    "D:/PROJECT/osgEarth/src/osgEarth/DrapeableNode"
    "D:/PROJECT/osgEarth/src/osgEarth/DrapingCullSet"
    "D:/PROJECT/osgEarth/src/osgEarth/DrapingTechnique"
    "D:/PROJECT/osgEarth/src/osgEarth/DrawInstanced"
    "D:/PROJECT/osgEarth/src/osgEarth/ECEF"
    "D:/PROJECT/osgEarth/src/osgEarth/ElevationField"
    "D:/PROJECT/osgEarth/src/osgEarth/ElevationLayer"
    "D:/PROJECT/osgEarth/src/osgEarth/ElevationLOD"
    "D:/PROJECT/osgEarth/src/osgEarth/ElevationQuery"
    "D:/PROJECT/osgEarth/src/osgEarth/Export"
    "D:/PROJECT/osgEarth/src/osgEarth/Extension"
    "D:/PROJECT/osgEarth/src/osgEarth/FadeEffect"
    "D:/PROJECT/osgEarth/src/osgEarth/FileUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/GeoCommon"
    "D:/PROJECT/osgEarth/src/osgEarth/GeoData"
    "D:/PROJECT/osgEarth/src/osgEarth/Geoid"
    "D:/PROJECT/osgEarth/src/osgEarth/GeoMath"
    "D:/PROJECT/osgEarth/src/osgEarth/GeoTransform"
    "D:/PROJECT/osgEarth/src/osgEarth/GeometryClamper"
    "D:/PROJECT/osgEarth/src/osgEarth/HeightFieldUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/Horizon"
    "D:/PROJECT/osgEarth/src/osgEarth/HTTPClient"
    "D:/PROJECT/osgEarth/src/osgEarth/ImageLayer"
    "D:/PROJECT/osgEarth/src/osgEarth/ImageMosaic"
    "D:/PROJECT/osgEarth/src/osgEarth/ImageToHeightFieldConverter"
    "D:/PROJECT/osgEarth/src/osgEarth/ImageUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/IOTypes"
    "D:/PROJECT/osgEarth/src/osgEarth/JsonUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/Layer"
    "D:/PROJECT/osgEarth/src/osgEarth/LineFunctor"
    "D:/PROJECT/osgEarth/src/osgEarth/Locators"
    "D:/PROJECT/osgEarth/src/osgEarth/LocalTangentPlane"
    "D:/PROJECT/osgEarth/src/osgEarth/Map"
    "D:/PROJECT/osgEarth/src/osgEarth/MapCallback"
    "D:/PROJECT/osgEarth/src/osgEarth/MapFrame"
    "D:/PROJECT/osgEarth/src/osgEarth/MapInfo"
    "D:/PROJECT/osgEarth/src/osgEarth/MapModelChange"
    "D:/PROJECT/osgEarth/src/osgEarth/MapNode"
    "D:/PROJECT/osgEarth/src/osgEarth/MapNodeObserver"
    "D:/PROJECT/osgEarth/src/osgEarth/MapNodeOptions"
    "D:/PROJECT/osgEarth/src/osgEarth/MapOptions"
    "D:/PROJECT/osgEarth/src/osgEarth/MaskLayer"
    "D:/PROJECT/osgEarth/src/osgEarth/MaskNode"
    "D:/PROJECT/osgEarth/src/osgEarth/MaskSource"
    "D:/PROJECT/osgEarth/src/osgEarth/Memory"
    "D:/PROJECT/osgEarth/src/osgEarth/MemCache"
    "D:/PROJECT/osgEarth/src/osgEarth/ModelLayer"
    "D:/PROJECT/osgEarth/src/osgEarth/ModelSource"
    "D:/PROJECT/osgEarth/src/osgEarth/NativeProgramAdapter"
    "D:/PROJECT/osgEarth/src/osgEarth/NodeUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/Notify"
    "D:/PROJECT/osgEarth/src/osgEarth/optional"
    "D:/PROJECT/osgEarth/src/osgEarth/ObjectIndex"
    "D:/PROJECT/osgEarth/src/osgEarth/OverlayDecorator"
    "D:/PROJECT/osgEarth/src/osgEarth/OverlayNode"
    "D:/PROJECT/osgEarth/src/osgEarth/PhongLightingEffect"
    "D:/PROJECT/osgEarth/src/osgEarth/Picker"
    "D:/PROJECT/osgEarth/src/osgEarth/IntersectionPicker"
    "D:/PROJECT/osgEarth/src/osgEarth/PrimitiveIntersector"
    "D:/PROJECT/osgEarth/src/osgEarth/Profile"
    "D:/PROJECT/osgEarth/src/osgEarth/Profiler"
    "D:/PROJECT/osgEarth/src/osgEarth/Progress"
    "D:/PROJECT/osgEarth/src/osgEarth/QuadTree"
    "D:/PROJECT/osgEarth/src/osgEarth/Random"
    "D:/PROJECT/osgEarth/src/osgEarth/Registry"
    "D:/PROJECT/osgEarth/src/osgEarth/Revisioning"
    "D:/PROJECT/osgEarth/src/osgEarth/Shaders"
    "D:/PROJECT/osgEarth/src/osgEarth/ShaderFactory"
    "D:/PROJECT/osgEarth/src/osgEarth/ShaderGenerator"
    "D:/PROJECT/osgEarth/src/osgEarth/ShaderLoader"
    "D:/PROJECT/osgEarth/src/osgEarth/ShaderUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/Shadowing"
    "D:/PROJECT/osgEarth/src/osgEarth/SharedSARepo"
    "D:/PROJECT/osgEarth/src/osgEarth/SpatialReference"
    "D:/PROJECT/osgEarth/src/osgEarth/StateSetCache"
    "D:/PROJECT/osgEarth/src/osgEarth/StateSetLOD"
    "D:/PROJECT/osgEarth/src/osgEarth/StringUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/TaskService"
    "D:/PROJECT/osgEarth/src/osgEarth/Terrain"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainEffect"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainLayer"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainOptions"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainEngineNode"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainEngineRequirements"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainTileModel"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainTileModelFactory"
    "D:/PROJECT/osgEarth/src/osgEarth/TerrainTileNode"
    "D:/PROJECT/osgEarth/src/osgEarth/TileKeyDataStore"
    "D:/PROJECT/osgEarth/src/osgEarth/TilePatchCallback"
    "D:/PROJECT/osgEarth/src/osgEarth/Tessellator"
    "D:/PROJECT/osgEarth/src/osgEarth/TextureCompositor"
    "D:/PROJECT/osgEarth/src/osgEarth/TileKey"
    "D:/PROJECT/osgEarth/src/osgEarth/TileHandler"
    "D:/PROJECT/osgEarth/src/osgEarth/TileSource"
    "D:/PROJECT/osgEarth/src/osgEarth/TileVisitor"
    "D:/PROJECT/osgEarth/src/osgEarth/TimeControl"
    "D:/PROJECT/osgEarth/src/osgEarth/TraversalData"
    "D:/PROJECT/osgEarth/src/osgEarth/ThreadingUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/Units"
    "D:/PROJECT/osgEarth/src/osgEarth/URI"
    "D:/PROJECT/osgEarth/src/osgEarth/Utils"
    "D:/PROJECT/osgEarth/src/osgEarth/Version"
    "D:/PROJECT/osgEarth/src/osgEarth/VerticalDatum"
    "D:/PROJECT/osgEarth/src/osgEarth/Viewpoint"
    "D:/PROJECT/osgEarth/src/osgEarth/VirtualProgram"
    "D:/PROJECT/osgEarth/src/osgEarth/XmlUtils"
    "D:/PROJECT/osgEarth/src/osgEarth/tinystr.h"
    "D:/PROJECT/osgEarth/src/osgEarth/tinyxml.h"
    )
endif()


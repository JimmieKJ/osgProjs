# Install script for directory: D:/PROJECT/osgEarth/src/osgEarthSplat

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthSplatd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthSplat.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthSplats.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthSplatrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Debug/osgEarthSplatd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/Release/osgEarthSplat.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/MinSizeRel/osgEarthSplats.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/osgEarth/lib/RelWithDebInfo/osgEarthSplatrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgEarthSplat" TYPE FILE FILES
    "D:/PROJECT/osgEarth/src/osgEarthSplat/Coverage"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/Export"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/LandCover"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/LandCoverTerrainEffect"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/LandCoverTilePatchCallback"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/LandUseTileSource"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/NoiseTextureFactory"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/SplatCoverageLegend"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/SplatCatalog"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/SplatExtension"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/SplatOptions"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/SplatShaders"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/SplatTerrainEffect"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/Surface"
    "D:/PROJECT/osgEarth/src/osgEarthSplat/Zone"
    )
endif()


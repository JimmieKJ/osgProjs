# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgShadow

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgShadowd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgShadow.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgShadows.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgShadowrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgShadowd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgShadow.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgShadows.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgShadowrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgShadow" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/OccluderGeometry"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ShadowTechnique"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ShadowTexture"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ShadowVolume"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ShadowedScene"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ShadowSettings"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/SoftShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ParallelSplitShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/Version"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ConvexPolyhedron"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/DebugShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/LightSpacePerspectiveShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/MinimalCullBoundsShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/MinimalDrawBoundsShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/MinimalShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ProjectionShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/StandardShadowMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ViewDependentShadowTechnique"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgShadow/ViewDependentShadowMap"
    )
endif()


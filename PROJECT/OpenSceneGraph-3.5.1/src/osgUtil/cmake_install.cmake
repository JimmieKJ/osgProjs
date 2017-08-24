# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgUtil

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgUtild.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgUtil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgUtils.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgUtilrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgUtild.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgUtil.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgUtils.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgUtilrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgUtil" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/ConvertVec"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/CubeMapGenerator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/CullVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/DelaunayTriangulator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/DisplayRequirementsVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/DrawElementTypeSimplifier"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/EdgeCollector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/GLObjectsVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/HalfWayMapGenerator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/HighlightMapGenerator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/IntersectionVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/IntersectVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/IncrementalCompileOperation"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/LineSegmentIntersector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/MeshOptimizers"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/OperationArrayFunctor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/Optimizer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/PerlinNoise"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/PlaneIntersector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/PolytopeIntersector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/PositionalStateContainer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/PrintVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/RayIntersector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/ReflectionMapGenerator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/RenderBin"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/RenderLeaf"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/RenderStage"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/ReversePrimitiveFunctor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/SceneView"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/SceneGraphBuilder"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/ShaderGen"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/Simplifier"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/SmoothingVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/StateGraph"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/Statistics"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/TangentSpaceGenerator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/Tessellator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/TransformAttributeFunctor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/TransformCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/TriStripVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/UpdateVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgUtil/Version"
    )
endif()


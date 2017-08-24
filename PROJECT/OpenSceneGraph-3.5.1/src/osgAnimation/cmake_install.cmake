# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgAnimation

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgAnimationd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgAnimation.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgAnimations.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgAnimationrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgAnimationd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgAnimation.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgAnimations.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgAnimationrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgAnimation" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Action"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/ActionAnimation"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/ActionBlendIn"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/ActionBlendOut"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/ActionCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/ActionStripAnimation"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/ActionVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Animation"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/AnimationManagerBase"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/AnimationUpdateCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/BasicAnimationManager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Bone"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/BoneMapVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Channel"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/CubicBezier"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/EaseMotion"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/FrameAction"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Interpolator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Keyframe"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/LinkVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/MorphGeometry"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/RigGeometry"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/RigTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/RigTransformHardware"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/RigTransformSoftware"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Sampler"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Skeleton"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedMatrixElement"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedQuaternionElement"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedRotateAxisElement"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedScaleElement"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedTransformElement"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedTranslateElement"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StackedTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StatsVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/StatsHandler"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Target"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Timeline"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/TimelineAnimationManager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/UpdateBone"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/UpdateMaterial"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/UpdateMatrixTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/UpdateUniform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/Vec3Packed"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgAnimation/VertexInfluence"
    )
endif()


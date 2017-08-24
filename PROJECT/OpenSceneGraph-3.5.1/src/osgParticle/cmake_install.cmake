# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgParticle

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgParticled.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgParticle.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgParticles.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgParticlerd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgParticled.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgParticle.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgParticles.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgParticlerd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgParticle" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/AccelOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/AngularAccelOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/BoxPlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/CenteredPlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ConnectedParticleSystem"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ConstantRateCounter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Counter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Emitter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ExplosionDebrisEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ExplosionEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/FireEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/FluidFrictionOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/FluidProgram"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ForceOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Interpolator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/LinearInterpolator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ModularEmitter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ModularProgram"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/MultiSegmentPlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Operator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Particle"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ParticleEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ParticleProcessor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ParticleSystem"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ParticleSystemUpdater"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Placer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/PointPlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/PrecipitationEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Program"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/RadialShooter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/RandomRateCounter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/range"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/SectorPlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/SegmentPlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Shooter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/SmokeEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/SmokeTrailEffect"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/VariableRateCounter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/Version"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/CompositePlacer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/AngularDampingOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/DampingOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/ExplosionOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/OrbitOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/DomainOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/BounceOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgParticle/SinkOperator"
    )
endif()


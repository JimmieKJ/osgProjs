# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/OpenThreads/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osg/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgDB/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgUtil/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgGA/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgText/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgViewer/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgAnimation/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgFX/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgManipulator/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgParticle/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgUI/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgVolume/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgShadow/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgSim/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgTerrain/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgWidget/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgPresentation/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgWrappers/serializers/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgWrappers/deprecated-dotosg/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgPlugins/cmake_install.cmake")
  include("D:/PROJECT/OpenSceneGraph-3.5.1/src/osgQt/cmake_install.cmake")

endif()


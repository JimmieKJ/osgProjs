# Install script for directory: D:/PROJECT/osgEarth/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/PROJECT/osgEarth/src/osgEarth/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthAnnotation/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthFeatures/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthSymbology/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthUtil/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthQt/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthSplat/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthSilverLining/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthTriton/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/osgEarthDrivers/cmake_install.cmake")
  include("D:/PROJECT/osgEarth/src/applications/cmake_install.cmake")

endif()


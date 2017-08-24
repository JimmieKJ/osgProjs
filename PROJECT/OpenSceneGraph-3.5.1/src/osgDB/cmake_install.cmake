# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgDB

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgDBd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgDB.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgDBs.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgDBrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgDBd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgDB.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgDBs.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgDBrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgDB" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/DataTypes"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/StreamOperator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Serializer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ObjectWrapper"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/InputStream"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/OutputStream"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Archive"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/AuthenticationMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Callbacks"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ClassInterface"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ConvertBase64"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ConvertUTF"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/DatabasePager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/DatabaseRevisions"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/DotOsgWrapper"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/DynamicLibrary"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ExternalFileWriter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/FileCache"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/FileNameUtils"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/FileUtils"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/fstream"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ImageOptions"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ImagePager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ImageProcessor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Input"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ObjectCache"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Output"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Options"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ParameterOutput"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/PluginQuery"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ReaderWriter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/ReadFile"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Registry"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/SharedStateManager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/Version"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/WriteFile"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgDB/XmlParser"
    )
endif()


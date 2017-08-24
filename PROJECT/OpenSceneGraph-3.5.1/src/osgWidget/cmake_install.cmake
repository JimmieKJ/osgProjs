# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osgWidget

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgWidgetd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgWidget.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgWidgets.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgWidgetrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgWidgetd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgWidget.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgWidgets.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgWidgetrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osgWidget" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Box"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Browser"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/PdfReader"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/VncClient"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Canvas"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/EventInterface"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Frame"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Input"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Label"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Lua"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Python"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/ScriptEngine"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/StyleInterface"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/StyleManager"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Table"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Types"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/UIObjectParent"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Util"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Version"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/ViewerEventHandlers"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Widget"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/Window"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osgWidget/WindowManager"
    )
endif()


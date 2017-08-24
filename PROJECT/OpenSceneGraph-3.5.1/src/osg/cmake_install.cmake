# Install script for directory: D:/PROJECT/OpenSceneGraph-3.5.1/src/osg

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osg.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgs.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/PROJECT/OpenSceneGraph-3.5.1/lib/osgrd.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osg.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgs.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/PROJECT/OpenSceneGraph-3.5.1/bin/osg141-osgrd.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libopenscenegraph-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/osg" TYPE FILE FILES
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/AlphaFunc"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/AnimationPath"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ApplicationUsage"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ArgumentParser"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Array"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ArrayDispatchers"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/AudioStream"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/AutoTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Billboard"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BlendColor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BlendEquation"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BlendEquationi"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BlendFunc"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BlendFunci"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BoundingBox"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BoundingSphere"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BoundsChecking"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/buffered_value"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BufferIndexBinding"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BufferObject"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/BufferTemplate"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Callback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Camera"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CameraView"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Capability"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ClampColor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ClearNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ClipControl"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ClipNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ClipPlane"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ClusterCullingCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CollectOccludersVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ColorMask"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ColorMaski"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ColorMatrix"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ComputeBoundsVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ContextData"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ConvexPlanarOccluder"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ConvexPlanarPolygon"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CoordinateSystemNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CopyOp"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CullFace"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CullingSet"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CullSettings"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/CullStack"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/DeleteHandler"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Depth"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/DisplaySettings"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Drawable"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/DrawPixels"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Endian"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Export"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/fast_back_stack"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Fog"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/FragmentProgram"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/FrameBufferObject"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/FrameStamp"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/FrontFace"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Geode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Geometry"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GL2Extensions"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GLDefines"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GLExtensions"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GLBeginEndAdapter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GLObjects"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GLU"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GraphicsCostEstimator"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GraphicsContext"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GraphicsThread"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Group"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Hint"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Image"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ImageSequence"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ImageStream"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ImageUtils"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/io_utils"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/KdTree"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Light"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LightModel"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LightSource"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LineSegment"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LineStipple"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LineWidth"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LOD"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/LogicOp"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Material"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Math"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Matrix"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Matrixd"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Matrixf"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/MatrixTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/MixinVector"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Multisample"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Node"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/NodeCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/NodeTrackerCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/NodeVisitor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Notify"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Object"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/observer_ptr"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Observer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ObserverNodePath"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/OccluderNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/OcclusionQueryNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/OperationThread"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PatchParameter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PagedLOD"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Plane"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Point"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PointSprite"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PolygonMode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PolygonOffset"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PolygonStipple"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Polytope"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PositionAttitudeTransform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PrimitiveSet"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/PrimitiveRestartIndex"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Program"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Projection"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ProxyNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Quat"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Referenced"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ref_ptr"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/RenderInfo"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/SampleMaski"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Scissor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ScriptEngine"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Sequence"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ShadeModel"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Shader"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ShaderAttribute"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ShaderComposer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ShadowVolumeOccluder"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Shape"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ShapeDrawable"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/State"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/StateAttribute"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/StateAttributeCallback"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/StateSet"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Stats"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Stencil"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/StencilTwoSided"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Switch"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TemplatePrimitiveFunctor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TexEnv"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TexEnvCombine"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TexEnvFilter"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TexGen"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TexGenNode"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TexMat"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Texture"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Texture1D"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Texture2D"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Texture2DMultisample"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Texture2DArray"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Texture3D"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TextureBuffer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TextureCubeMap"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TextureRectangle"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Timer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TransferFunction"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Transform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TriangleFunctor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/TriangleIndexFunctor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Types"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Uniform"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/UserDataContainer"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/ValueObject"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2b"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2d"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2f"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2i"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2s"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2ub"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2ui"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec2us"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3b"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3d"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3f"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3i"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3s"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3ub"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3ui"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec3us"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4b"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4d"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4f"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4i"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4s"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4ub"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4ui"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Vec4us"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/VertexAttribDivisor"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/VertexProgram"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/View"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Viewport"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Version"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/Config"
    "D:/PROJECT/OpenSceneGraph-3.5.1/include/osg/GL"
    )
endif()


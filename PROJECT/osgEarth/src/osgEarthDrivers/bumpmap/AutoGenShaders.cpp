/** CMake Template File - compiled into AutoGenShaders.cpp */
#include <osgEarthDrivers/bumpmap/BumpMapShaders>

#define MULTILINE(...) #__VA_ARGS__

using namespace osgEarth::BumpMap;

Shaders::Shaders()
{
    VertexView = "BumpMap.vert.view.glsl";
    _sources[VertexView] = MULTILINE($__HASHTAG__version $GLSL_VERSION_STR\n
\n
$__HASHTAG__pragma vp_entryPoint oe_bumpmap_vertexView\n
$__HASHTAG__pragma vp_location   vertex_view\n
$__HASHTAG__pragma vp_order      0.5\n
\n
uniform vec4 oe_tile_key;\n
uniform float oe_bumpmap_scale;\n
uniform float oe_bumpmap_baseLOD;\n
\n
out vec4 oe_layer_tilec;\n
out vec3 vp_Normal;\n
\n
out vec2 oe_bumpmap_coords;\n
out float oe_bumpmap_range;\n
\n
\n
vec2 oe_bumpmap_scaleCoords(in vec2 coords, in float targetLOD)\n
{\n
    float dL = oe_tile_key.z - targetLOD;\n
    float factor = exp2(dL);\n
    float invFactor = 1.0/factor;\n
    vec2 scale = vec2(invFactor);\n
    vec2 result = coords * scale;\n
\n
    // For upsampling we need to calculate an offset as well\n
    float upSampleToggle = factor >= 1.0 ? 1.0 : 0.0;\n
    {\n
        vec2 a = floor(oe_tile_key.xy * invFactor);\n
        vec2 b = a * factor;\n
        vec2 c = (a+1.0) * factor;\n
        vec2 offset = (oe_tile_key.xy-b)/(c-b);\n
        result += upSampleToggle * offset;\n
    }\n
\n
    return result;\n
}\n
\n
void oe_bumpmap_vertexView(inout vec4 vertexView)\n
{\n
    oe_bumpmap_range = -vertexView.z;\n
\n
    // quantize the scale factor\n
    float iscale = float(int(oe_bumpmap_scale));\n
\n
    // scale sampling coordinates to a target LOD.\n
    oe_bumpmap_coords = oe_bumpmap_scaleCoords(oe_layer_tilec.st, floor(oe_bumpmap_baseLOD)) * iscale;\n
}\n
\n
);

    FragmentSimple = "BumpMap.frag.simple.glsl";
    _sources[FragmentSimple] = MULTILINE($__HASHTAG__version $GLSL_VERSION_STR\n
\n
$__HASHTAG__pragma vp_entryPoint oe_bumpmap_fragment\n
$__HASHTAG__pragma vp_location   fragment_coloring\n
$__HASHTAG__pragma vp_order      0.3\n
\n
$__HASHTAG__pragma include BumpMap.frag.common.glsl\n
\n
in vec3 vp_Normal;\n
in vec2 oe_bumpmap_coords;\n
in vec3 oe_UpVectorView;\n
\n
uniform sampler2D oe_bumpmap_tex;\n
uniform float     oe_bumpmap_intensity;\n
uniform float     oe_bumpmap_slopeFactor;\n
\n
\n
void oe_bumpmap_fragment(inout vec4 color)\n
{\n
	// sample the bump map\n
    vec3 bump = gl_NormalMatrix * normalize(texture2D(oe_bumpmap_tex, oe_bumpmap_coords).xyz*2.0-1.0);\n
    \n
    // calculate slope from normal:\n
    float slope = clamp( (1.0-dot(oe_UpVectorView, vp_Normal))*oe_bumpmap_slopeFactor, 0.0, 1.0);\n
    \n
	// permute the normal with the bump.\n
	vp_Normal = normalize(vp_Normal + bump*oe_bumpmap_intensity*slope);\n
}\n
\n
);

    FragmentProgressive = "BumpMap.frag.progressive.glsl";
    _sources[FragmentProgressive] = MULTILINE($__HASHTAG__version $GLSL_VERSION_STR\n
\n
$__HASHTAG__pragma vp_entryPoint oe_bumpmap_fragment\n
$__HASHTAG__pragma vp_location   fragment_coloring\n
$__HASHTAG__pragma vp_order      0.3\n
\n
$__HASHTAG__pragma include BumpMap.frag.common.glsl\n
\n
uniform sampler2D oe_bumpmap_tex;\n
uniform float     oe_bumpmap_intensity;\n
uniform int       oe_bumpmap_octaves;\n
uniform float     oe_bumpmap_maxRange;\n
uniform float     oe_bumpmap_slopeFactor;\n
\n
// framework/stage global\n
in vec3 vp_Normal;\n
in vec3 oe_UpVectorView;\n
\n
// from BumpMap.model.vert.glsl\n
in vec2 oe_bumpmap_coords;\n
\n
// from BumpMap.view.vert.glsl\n
in float oe_bumpmap_range;\n
\n
// Entry point for progressive blended bump maps\n
void oe_bumpmap_fragment(inout vec4 color)\n
{\n
	// sample the bump map\n
    const float amplitudeDecay = 1.0; // no decay.\n
    float maxLOD = float(oe_bumpmap_octaves)+1.0;\n
\n
    // starter vector:\n
    vec3 bump = vec3(0.0);    \n
    float scale = 1.0;\n
    float amplitude = 1.0;\n
    float limit = oe_bumpmap_range;\n
    float range = oe_bumpmap_maxRange;\n
    float lastRange = oe_bumpmap_maxRange;\n
    for(float lod = 1.0; lod < maxLOD; lod += 1.0, scale *= 2.0, amplitude *= amplitudeDecay)\n
    {\n
        float fadeIn = 1.0;\n
        if ( range <= limit && limit < oe_bumpmap_maxRange )\n
            fadeIn = clamp((lastRange-limit)/(lastRange-range), 0.0, 1.0);\n
        bump += (texture2D(oe_bumpmap_tex, oe_bumpmap_coords*scale).xyz*2.0-1.0)*amplitude*fadeIn;\n
        if ( range <= limit )\n
            break;\n
        lastRange = range;\n
        range = oe_bumpmap_maxRange/exp(lod);\n
    }\n
\n
    // finally, transform into view space and normalize the vector.\n
    bump = normalize(gl_NormalMatrix*bump);\n
    \n
    // calculate slope from normal:\n
    float slope = mix(1.0, 1.0 - dot(oe_UpVectorView, vp_Normal), oe_bumpmap_slopeFactor);\n
\n
	// permute the normal with the bump.\n
	vp_Normal = normalize(vp_Normal + bump*oe_bumpmap_intensity*slope);\n
}\n
\n
);

    FragmentCommon = "BumpMap.frag.common.glsl";
    _sources[FragmentCommon] = MULTILINE($__HASHTAG__pragma vp_define OE_USE_NORMAL_MAP\n
\n
$__HASHTAG__ifdef OE_USE_NORMAL_MAP\n
\n
// normal map version:\n
uniform sampler2D oe_tile_normalTex;\n
in vec2 oe_normalMapCoords;\n
\n
float oe_bumpmap_getSlope()\n
{\n
    vec4 encodedNormal = texture2D(oe_nmap_normalTex, oe_normalMapCoords);\n
    vec3 normalTangent = normalize(encodedNormal.xyz*2.0-1.0);\n
    return clamp((1.0-normalTangent.z)/0.8, 0.0, 1.0);\n
}\n
\n
$__HASHTAG__else // OE_USE_NORMAL_MAP\n
\n
// non- normal map version:\n
in float oe_bumpmap_slope;\n
\n
float oe_bumpmap_getSlope()\n
{\n
    return oe_bumpmap_slope;\n
}\n
\n
$__HASHTAG__endif // OE_USE_NORMAL_MAP\n
\n
);
};

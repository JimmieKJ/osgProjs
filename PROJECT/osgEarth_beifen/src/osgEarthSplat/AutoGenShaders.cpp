// CMake will compile this file into AutoGenShaders.cpp

#include <osgEarthSplat/SplatShaders>

#define MULTILINE(...) #__VA_ARGS__

using namespace osgEarth::Splat;

SplattingShaders::SplattingShaders()
{
    Types = "Splat.types.glsl";
    _sources[Types] = MULTILINE(// begin: Splat.types.glsl\n
\n
// Environment structure passed around locally.\n
struct oe_SplatEnv {\n
    float lod;\n
    float range;\n
    float elevation;\n
    float slope;\n
    vec4 noise;\n
};\n
\n
// Rendering parameters for splat texture and noise-based detail texture.\n
struct oe_SplatRenderInfo {\n
    float primaryIndex;\n
    float detailIndex;\n
    float brightness;\n
    float contrast;\n
    float threshold;\n
    float minSlope;\n
};\n
\n
// end: Splat.types.glsl\n
);

    Noise = "Splat.Noise.glsl";
    _sources[Noise] = MULTILINE($__HASHTAG__version 110\n
//\n
// Description : Array and textureless GLSL 2D/3D/4D simplex \n
//               noise functions.\n
//      Author : Ian McEwan, Ashima Arts.\n
//  Maintainer : ijm\n
//     Lastmod : 20110822 (ijm)\n
//     License : Copyright (C) 2011 Ashima Arts. All rights reserved.\n
//               Distributed under the MIT License. See LICENSE file.\n
//               https://github.com/ashima/webgl-noise\n
// \n
\n
vec4 oe_noise_mod289(vec4 x) {\n
  return x - floor(x * (1.0 / 289.0)) * 289.0; }\n
\n
float oe_noise_mod289(float x) {\n
  return x - floor(x * (1.0 / 289.0)) * 289.0; }\n
\n
vec4 oe_noise_permute(vec4 x) {\n
     return oe_noise_mod289(((x*34.0)+1.0)*x);\n
}\n
\n
float oe_noise_permute(float x) {\n
     return oe_noise_mod289(((x*34.0)+1.0)*x);\n
}\n
\n
vec4 oe_noise_taylorInvSqrt(vec4 r)\n
{\n
  return 1.79284291400159 - 0.85373472095314 * r;\n
}\n
\n
float oe_noise_taylorInvSqrt(float r)\n
{\n
  return 1.79284291400159 - 0.85373472095314 * r;\n
}\n
\n
vec4 oe_noise_grad4(float j, vec4 ip)\n
  {\n
  const vec4 ones = vec4(1.0, 1.0, 1.0, -1.0);\n
  vec4 p,s;\n
\n
  p.xyz = floor( fract (vec3(j) * ip.xyz) * 7.0) * ip.z - 1.0;\n
  p.w = 1.5 - dot(abs(p.xyz), ones.xyz);\n
  s = vec4(lessThan(p, vec4(0.0)));\n
  p.xyz = p.xyz + (s.xyz*2.0 - 1.0) * s.www; \n
\n
  return p;\n
  }\n
						\n
// (sqrt(5) - 1)/4 = F4, used once below\n
$__HASHTAG__define oe_noise_F4 0.309016994374947451\n
\n
float oe_noise_snoise(vec4 v)\n
  {\n
  const vec4  C = vec4( 0.138196601125011,  // (5 - sqrt(5))/20  G4\n
                        0.276393202250021,  // 2 * G4\n
                        0.414589803375032,  // 3 * G4\n
                       -0.447213595499958); // -1 + 4 * G4\n
\n
// First corner\n
  vec4 i  = floor(v + dot(v, vec4(oe_noise_F4)) );\n
  vec4 x0 = v -   i + dot(i, C.xxxx);\n
\n
// Other corners\n
\n
// Rank sorting originally contributed by Bill Licea-Kane, AMD (formerly ATI)\n
  vec4 i0;\n
  vec3 isX = step( x0.yzw, x0.xxx );\n
  vec3 isYZ = step( x0.zww, x0.yyz );\n
//  i0.x = dot( isX, vec3( 1.0 ) );\n
  i0.x = isX.x + isX.y + isX.z;\n
  i0.yzw = 1.0 - isX;\n
//  i0.y += dot( isYZ.xy, vec2( 1.0 ) );\n
  i0.y += isYZ.x + isYZ.y;\n
  i0.zw += 1.0 - isYZ.xy;\n
  i0.z += isYZ.z;\n
  i0.w += 1.0 - isYZ.z;\n
\n
  // i0 now contains the unique values 0,1,2,3 in each channel\n
  vec4 i3 = clamp( i0, 0.0, 1.0 );\n
  vec4 i2 = clamp( i0-1.0, 0.0, 1.0 );\n
  vec4 i1 = clamp( i0-2.0, 0.0, 1.0 );\n
\n
  //  x0 = x0 - 0.0 + 0.0 * C.xxxx\n
  //  x1 = x0 - i1  + 1.0 * C.xxxx\n
  //  x2 = x0 - i2  + 2.0 * C.xxxx\n
  //  x3 = x0 - i3  + 3.0 * C.xxxx\n
  //  x4 = x0 - 1.0 + 4.0 * C.xxxx\n
  vec4 x1 = x0 - i1 + C.xxxx;\n
  vec4 x2 = x0 - i2 + C.yyyy;\n
  vec4 x3 = x0 - i3 + C.zzzz;\n
  vec4 x4 = x0 + C.wwww;\n
\n
// Permutations\n
  i = oe_noise_mod289(i); \n
  float j0 = oe_noise_permute( oe_noise_permute( oe_noise_permute( oe_noise_permute(i.w) + i.z) + i.y) + i.x);\n
  vec4 j1 = oe_noise_permute( oe_noise_permute( oe_noise_permute( oe_noise_permute (\n
             i.w + vec4(i1.w, i2.w, i3.w, 1.0 ))\n
           + i.z + vec4(i1.z, i2.z, i3.z, 1.0 ))\n
           + i.y + vec4(i1.y, i2.y, i3.y, 1.0 ))\n
           + i.x + vec4(i1.x, i2.x, i3.x, 1.0 ));\n
\n
// Gradients: 7x7x6 points over a cube, mapped onto a 4-cross polytope\n
// 7*7*6 = 294, which is close to the ring size 17*17 = 289.\n
  vec4 ip = vec4(1.0/294.0, 1.0/49.0, 1.0/7.0, 0.0) ;\n
\n
  vec4 p0 = oe_noise_grad4(j0,   ip);\n
  vec4 p1 = oe_noise_grad4(j1.x, ip);\n
  vec4 p2 = oe_noise_grad4(j1.y, ip);\n
  vec4 p3 = oe_noise_grad4(j1.z, ip);\n
  vec4 p4 = oe_noise_grad4(j1.w, ip);\n
\n
// Normalise gradients\n
  vec4 norm = oe_noise_taylorInvSqrt(vec4(dot(p0,p0), dot(p1,p1), dot(p2, p2), dot(p3,p3)));\n
  p0 *= norm.x;\n
  p1 *= norm.y;\n
  p2 *= norm.z;\n
  p3 *= norm.w;\n
  p4 *= oe_noise_taylorInvSqrt(dot(p4,p4));\n
\n
// Mix contributions from the five corners\n
  vec3 m0 = max(0.6 - vec3(dot(x0,x0), dot(x1,x1), dot(x2,x2)), 0.0);\n
  vec2 m1 = max(0.6 - vec2(dot(x3,x3), dot(x4,x4)            ), 0.0);\n
  m0 = m0 * m0;\n
  m1 = m1 * m1;\n
  return 49.0 * ( dot(m0*m0, vec3( dot( p0, x0 ), dot( p1, x1 ), dot( p2, x2 )))\n
               + dot(m1*m1, vec2( dot( p3, x3 ), dot( p4, x4 ) ) ) ) ;\n
}\n
\n
// Generates a tiled fractal simplex noise value and clamps the values to [0..1].\n
float oe_noise_fractal4D(in vec2 seed, in float frequency, in float persistence, in float lacunarity, in int octaves)\n
{\n
    const float TwoPI = 6.283185;\n
	float f = frequency;\n
	float amp = 1.0;\n
	float maxAmp = 0.0;\n
	float n = 0.0;\n
    \n
    vec4 seed4D;\n
    seed4D.xy = cos(seed*TwoPI)/TwoPI;\n
    seed4D.zw = sin(seed*TwoPI)/TwoPI;\n
\n
	for(int i=0; i<octaves; ++i)\n
	{\n
		n += oe_noise_snoise(seed4D*f) * amp;\n
		maxAmp += amp;\n
		amp *= persistence;\n
		f *= lacunarity;\n
	}\n
	//return n / maxAmp;\n
    const float low = 0.0;\n
    const float high = 1.0;\n
\n
    n /= maxAmp;\n
    n = n * (high-low)/2.0 + (high+low)/2.0;\n
    return clamp(n, 0.0, 1.0);\n
}\n
\n
);

    VertModel = "Splat.vert.model.glsl";
    _sources[VertModel] = MULTILINE($__HASHTAG__version 330\n
$__HASHTAG__pragma vp_entryPoint oe_splat_vertex_model\n
$__HASHTAG__pragma vp_location   vertex_model\n
$__HASHTAG__pragma vp_order      0.5\n
\n
vec3 vp_Normal; // stage global\n
out float oe_splat_slope;\n
\n
void oe_splat_vertex_model(inout vec4 VertexMODEL)\n
{\n
    // calculate slope from the Z component of the current normal\n
    // since the terrain is in LTP space. This is only used when normal maps\n
    // are not available, which is hopefully never :/\n
    oe_splat_slope = 1.0-vp_Normal.z;\n
}\n
\n
);

    VertView = "Splat.vert.view.glsl";
    _sources[VertView] = MULTILINE($__HASHTAG__version 330\n
\n
$__HASHTAG__pragma vp_entryPoint oe_splat_vertex_view\n
$__HASHTAG__pragma vp_location   vertex_view\n
$__HASHTAG__pragma vp_order      0.5\n
\n
$__HASHTAG__pragma include Splat.types.glsl\n
\n
out vec4 oe_layer_tilec;\n
out float oe_splat_range;\n
out vec2 oe_splat_covtc;\n
\n
uniform mat4 COVERAGE_TEXTURE_MATRIX;   // assigned at runtime\n
\n
\n
void oe_splat_vertex_view(inout vec4 VertexVIEW)\n
{\n
    // range from camera to vertex\n
    oe_splat_range = -VertexVIEW.z;\n
\n
    // calculate the coverage sampling coordinates. The texture matrix accounts\n
    // for any super-sampling that might be in effect for the current LOD.\n
    oe_splat_covtc = (COVERAGE_TEXTURE_MATRIX * oe_layer_tilec).st;\n
}\n
\n
);

    Frag = "Splat.frag.glsl";
    _sources[Frag] = MULTILINE($__HASHTAG__version 330\n
\n
$__HASHTAG__pragma vp_entryPoint oe_splat_complex\n
$__HASHTAG__pragma vp_location   fragment_coloring\n
$__HASHTAG__pragma vp_order      0.4\n
\n
// define to activate 'edit' mode in which uniforms control\n
// the splatting parameters.\n
$__HASHTAG__pragma vp_define SPLAT_EDIT\n
\n
// define to activate GPU-generated noise instead of a noise texture.\n
$__HASHTAG__pragma vp_define SPLAT_GPU_NOISE\n
\n
// include files\n
$__HASHTAG__pragma include Splat.types.glsl\n
$__HASHTAG__pragma include Splat.frag.common.glsl\n
\n
// ref: Splat.getRenderInfo.frag.glsl\n
oe_SplatRenderInfo oe_splat_getRenderInfo(in float value, in oe_SplatEnv env);\n
\n
// from: Splat.util.glsl\n
void oe_splat_getLodBlend(in float range, in float baseLOD, out float lod0, out float lod1, out float range0, out float range1, out float blend);\n
vec2 oe_splat_getSplatCoords(in vec2 coords, in float lod);\n
\n
// from the terrain engine:\n
in vec4 oe_layer_tilec;\n
uniform vec4 oe_tile_key;\n
\n
// from the vertex shader:\n
in vec2 oe_splat_covtc;\n
in float oe_splat_range;\n
\n
// from SplatTerrainEffect:\n
uniform float oe_splat_warp;\n
uniform float oe_splat_blur;\n
uniform sampler2D oe_splat_coverageTex;\n
uniform sampler2DArray oe_splatTex;\n
uniform float oe_splat_scaleOffset;\n
\n
uniform float oe_splat_detailRange;\n
uniform float oe_splat_noiseScale;\n
uniform float oe_splat_useBilinear; // 1=true, -1=false\n
\n
$__HASHTAG__ifdef SPLAT_EDIT\n
uniform float oe_splat_brightness;\n
uniform float oe_splat_contrast;\n
uniform float oe_splat_threshold;\n
uniform float oe_splat_minSlope;\n
$__HASHTAG__endif\n
\n
// Warps the coverage sampling coordinates to mitigate blockiness.\n
vec2 oe_splat_warpCoverageCoords(in vec2 splat_tc, in oe_SplatEnv env)\n
{\n
    vec2 seed = oe_splat_covtc;\n
    float n1 = 2.0*env.noise.y-1.0;\n
    vec2 tc = oe_splat_covtc + n1*oe_splat_warp;\n
    return clamp(tc, 0.0, 1.0);\n
}\n
\n
vec4 oe_splat_getTexel(in float index, in vec2 tc)\n
{\n
    return texture(oe_splatTex, vec3(tc, index));\n
}\n
\n
// Samples a detail texel using its render info parameters.\n
// Returns the weighting factor in the alpha channel.\n
vec4 oe_splat_getDetailTexel(in oe_SplatRenderInfo ri, in vec2 tc, in oe_SplatEnv env)\n
{\n
    float hasDetail = ri.detailIndex >= 0.0 ? 1.0 : 0.0;\n
\n
$__HASHTAG__ifdef SPLAT_EDIT\n
    float brightness = oe_splat_brightness;\n
    float contrast = oe_splat_contrast;\n
    float threshold = oe_splat_threshold;\n
    float minSlope = oe_splat_minSlope;\n
$__HASHTAG__else\n
    float brightness = ri.brightness;\n
    float contrast = ri.contrast;\n
    float threshold = ri.threshold;\n
    float minSlope = ri.minSlope;\n
$__HASHTAG__endif\n
\n
    // start with the noise value\n
    float n = env.noise.x;\n
	\n
    // apply slope limiter, then reclamp and threshold:\n
    float s;\n
    if ( env.slope >= minSlope )\n
        s = 1.0;\n
    else if ( env.slope < 0.1*minSlope )\n
        s = 0.0;\n
    else\n
        s = (env.slope-0.1*minSlope)/(minSlope-0.1*minSlope);\n
\n
    brightness *= s;\n
\n
    // apply brightness and contrast, then reclamp\n
    n = clamp(((n-0.5)*contrast + 0.5) * brightness, 0.0, 1.0);\n
    \n
    // apply final threshold:\n
	n = n < threshold ? 0.0 : n;\n
\n
    // sample the texel and return it.\n
    vec4 result = oe_splat_getTexel( max(ri.detailIndex,0), tc);\n
    return vec4(result.rgb, hasDetail*n);\n
}\n
\n
// Generates a texel using nearest-neighbor coverage sampling.\n
vec4 oe_splat_nearest(in vec2 splat_tc, in oe_SplatEnv env)\n
{\n
    vec2 tc = oe_splat_covtc; //oe_splat_warpCoverageCoords(splat_tc, env);\n
    float coverageValue = texture2D(oe_splat_coverageTex, tc).r;\n
    oe_SplatRenderInfo ri = oe_splat_getRenderInfo(coverageValue, env);\n
    vec4 primary = oe_splat_getTexel(ri.primaryIndex, splat_tc);\n
    float detailToggle = ri.detailIndex >= 0 ? 1.0 : 0.0;\n
    vec4 detail  = oe_splat_getDetailTexel(ri, splat_tc, env) * detailToggle;    \n
    return vec4( mix(primary.rgb, detail.rgb, detail.a), 1.0 );\n
}\n
\n
// Generates a texel using bilinear filtering on the coverage data.\n
vec4 oe_splat_bilinear(in vec2 splat_tc, in oe_SplatEnv env)\n
{\n
    vec4 texel = vec4(0,0,0,1);\n
\n
    //TODO: coverage warping is slow due to the noise function. Consider removing/reworking.\n
    vec2 tc = oe_splat_covtc; //oe_splat_warpCoverageCoords(splat_tc, env);\n
\n
    float a = oe_splat_blur;\n
    float pixelWidth = a/256.0; // 256 = hard-coded cov tex size //TODO \n
    float halfPixelWidth = 0.5*pixelWidth;\n
    float pixelWidth2 = pixelWidth*pixelWidth;\n
\n
    // Find the four quantized coverage coordinates that form a box around the actual\n
    // coverage coordinates, where each quantized coord is at the center of a coverage texel.\n
    vec2 rem = mod(tc, pixelWidth);\n
    vec2 sw;\n
    sw.x = tc.x - rem.x + (rem.x >= halfPixelWidth ? halfPixelWidth : -halfPixelWidth);\n
    sw.y = tc.y - rem.y + (rem.y >= halfPixelWidth ? halfPixelWidth : -halfPixelWidth);\n
    vec2 ne = sw + pixelWidth;\n
    vec2 nw = vec2(sw.x, ne.y);\n
    vec2 se = vec2(ne.x, sw.y);\n
\n
    // Calculate the weighting for each corner.\n
    vec2 dsw = tc-sw;\n
    vec2 dse = tc-se;\n
    vec2 dne = tc-ne;\n
    vec2 dnw = tc-nw;\n
\n
    float sw_weight = max(pixelWidth2-dot(dsw,dsw),0.0);\n
    float se_weight = max(pixelWidth2-dot(dse,dse),0.0);\n
    float ne_weight = max(pixelWidth2-dot(dne,dne),0.0);\n
    float nw_weight = max(pixelWidth2-dot(dnw,dnw),0.0);\n
\n
    // normalize the weights so they total 1.0\n
    float invTotalWeight = 1.0/(sw_weight+se_weight+ne_weight+nw_weight);\n
    sw_weight *= invTotalWeight;\n
    se_weight *= invTotalWeight;\n
    ne_weight *= invTotalWeight;\n
    nw_weight *= invTotalWeight;\n
\n
    // Sample coverage values using quantized corner coords:\n
    float value_sw = texture2D(oe_splat_coverageTex, clamp(sw, 0.0, 1.0)).r;\n
    float value_se = texture2D(oe_splat_coverageTex, clamp(se, 0.0, 1.0)).r;\n
    float value_ne = texture2D(oe_splat_coverageTex, clamp(ne, 0.0, 1.0)).r;\n
    float value_nw = texture2D(oe_splat_coverageTex, clamp(nw, 0.0, 1.0)).r;\n
\n
    // Build the render info data for each corner:\n
    oe_SplatRenderInfo ri_sw = oe_splat_getRenderInfo(value_sw, env);\n
    oe_SplatRenderInfo ri_se = oe_splat_getRenderInfo(value_se, env);\n
    oe_SplatRenderInfo ri_ne = oe_splat_getRenderInfo(value_ne, env);\n
    oe_SplatRenderInfo ri_nw = oe_splat_getRenderInfo(value_nw, env);\n
\n
    // Primary splat:\n
    vec3 sw_primary = oe_splat_getTexel(ri_sw.primaryIndex, splat_tc).rgb;\n
    vec3 se_primary = oe_splat_getTexel(ri_se.primaryIndex, splat_tc).rgb;\n
    vec3 ne_primary = oe_splat_getTexel(ri_ne.primaryIndex, splat_tc).rgb;\n
    vec3 nw_primary = oe_splat_getTexel(ri_nw.primaryIndex, splat_tc).rgb;\n
\n
    // Detail splat - weighting is in the alpha channel\n
    // TODO: Pointless to have a detail range? -gw\n
    // TODO: If noise is a texture, just try to single-sample it instead\n
    float detailToggle =env.range < oe_splat_detailRange ? 1.0 : 0.0;\n
    vec4 sw_detail = detailToggle * oe_splat_getDetailTexel(ri_sw, splat_tc, env);\n
    vec4 se_detail = detailToggle * oe_splat_getDetailTexel(ri_se, splat_tc, env);\n
    vec4 ne_detail = detailToggle * oe_splat_getDetailTexel(ri_ne, splat_tc, env);\n
    vec4 nw_detail = detailToggle * oe_splat_getDetailTexel(ri_nw, splat_tc, env);   \n
\n
    // Combine everything based on weighting:\n
    texel.rgb =\n
        sw_weight * mix(sw_primary, sw_detail.rgb, sw_detail.a) +\n
        se_weight * mix(se_primary, se_detail.rgb, se_detail.a) +\n
        ne_weight * mix(ne_primary, ne_detail.rgb, ne_detail.a) +\n
        nw_weight * mix(nw_primary, nw_detail.rgb, nw_detail.a);\n
\n
    return texel;\n
}\n
\n
$__HASHTAG__ifdef SPLAT_GPU_NOISE\n
\n
uniform float oe_splat_freq;\n
uniform float oe_splat_pers;\n
uniform float oe_splat_lac;\n
uniform float oe_splat_octaves;\n
\n
// see: Splat.Noise.glsl\n
float oe_noise_fractal4D(in vec2 seed, in float frequency, in float persistence, in float lacunarity, in int octaves);\n
\n
vec4 oe_splat_getNoise(in vec2 tc)\n
{\n
    return vec4(oe_noise_fractal4D(tc, oe_splat_freq, oe_splat_pers, oe_splat_lac, int(oe_splat_octaves)));\n
}\n
\n
$__HASHTAG__else // !SPLAT_GPU_NOISE\n
\n
uniform sampler2D oe_splat_noiseTex;\n
vec4 oe_splat_getNoise(in vec2 tc)\n
{\n
    return texture(oe_splat_noiseTex, tc.st);\n
}\n
\n
$__HASHTAG__endif // SPLAT_GPU_NOISE\n
\n
// Simplified entry point with does no filtering or range blending. (much faster.)\n
void oe_splat_simple(inout vec4 color)\n
{\n
    float noiseLOD = floor(oe_splat_noiseScale);\n
    vec2 noiseCoords = oe_splat_getSplatCoords(oe_layer_tilec.st, noiseLOD);\n
\n
    oe_SplatEnv env;\n
    env.range = oe_splat_range;\n
    env.slope = oe_splat_getSlope();\n
    env.noise = oe_splat_getNoise(noiseCoords);\n
    env.elevation = 0.0;\n
\n
    color = oe_splat_bilinear(oe_layer_tilec.st, env);\n
}\n
\n
// Main entry point for fragment shader.\n
void oe_splat_complex(inout vec4 color)\n
{\n
    // Noise coords.\n
    float noiseLOD = floor(oe_splat_noiseScale);\n
    vec2 noiseCoords = oe_splat_getSplatCoords(oe_layer_tilec.st, noiseLOD); //TODO: move to VS for slight speedup\n
\n
    oe_SplatEnv env;\n
    env.range = oe_splat_range;\n
    env.slope = oe_splat_getSlope();\n
    env.noise = oe_splat_getNoise(noiseCoords);\n
    env.elevation = 0.0;\n
\n
    // quantize the scale offset so we take the hit in the FS\n
    float scaleOffset = oe_splat_scaleOffset >= 0.0 ? ceil(oe_splat_scaleOffset) : floor(oe_splat_scaleOffset);\n
        \n
    // Calculate the 2 LODs we need to blend. We have to do this in the FS because \n
    // it's quite possible for a single triangle to span more than 2 LODs.\n
    float lod0, lod1;\n
    float range0, range1;\n
    float lodBlend = -1.0;\n
    oe_splat_getLodBlend(oe_splat_range, scaleOffset, lod0, lod1, range0, range1, lodBlend);\n
\n
    // Sample the two LODs:\n
    vec2 tc0 = oe_splat_getSplatCoords(oe_layer_tilec.st, lod0);\n
    env.range = range0;\n
    vec4 texel0 = oe_splat_bilinear(tc0, env);\n
    \n
    vec2 tc1 = oe_splat_getSplatCoords(oe_layer_tilec.st, lod1);\n
    env.range = range1;\n
    vec4 texel1 = oe_splat_bilinear(tc1, env);\n
    \n
    // Blend:\n
    vec4 texel = mix(texel0, texel1, lodBlend);\n
\n
    color = mix(color, texel, texel.a);\n
\n
    // uncomment to visualize slope.\n
    //color.rgba = vec4(env.slope,0,0,1);\n
}\n
\n
);

    FragCommon = "Splat.frag.common.glsl";
    _sources[FragCommon] = MULTILINE(// begin: Splat.frag.common.glsl\n
\n
// TODO:\n
// Encapsulate the "use normal map" define logic in the terrain SDK itself.\n
\n
$__HASHTAG__pragma vp_define OE_USE_NORMAL_MAP\n
\n
$__HASHTAG__ifdef OE_USE_NORMAL_MAP\n
\n
// import SDK\n
vec4 oe_terrain_getNormalAndCurvature(in vec2);\n
\n
// normal map version:\n
in vec2 oe_normalMapCoords;\n
\n
float oe_splat_getSlope()\n
{\n
    vec4 encodedNormal = oe_terrain_getNormalAndCurvature( oe_normalMapCoords );\n
    vec3 normalTangent = normalize(encodedNormal.xyz*2.0-1.0);\n
    return clamp((1.0-normalTangent.z)/0.8, 0.0, 1.0);\n
}\n
\n
$__HASHTAG__else // !OE_USE_NORMAL_MAP\n
\n
// non- normal map version:\n
in float oe_splat_slope;\n
\n
float oe_splat_getSlope()\n
{\n
    return oe_splat_slope;\n
}\n
\n
$__HASHTAG__endif // OE_USE_NORMAL_MAP\n
\n
// end: Splat.frag.common.glsl\n
);

    FragGetRenderInfo = "Splat.frag.getRenderInfo.glsl";
    _sources[FragGetRenderInfo] = MULTILINE($__HASHTAG__version 330\n
\n
$__HASHTAG__pragma include Splat.types.glsl\n
\n
// Samples the coverage data and returns main and detail indices.\n
oe_SplatRenderInfo oe_splat_getRenderInfo(in float value, in oe_SplatEnv env)\n
{\n
    float primary = -1.0;   // primary texture index\n
    float detail = -1.0;    // detail texture index\n
    float brightness = 1.0; // default noise function brightness factor\n
    float contrast = 1.0;   // default noise function contrast factor\n
    float threshold = 0.0;  // default noise function threshold\n
    float slope = 0.0;      // default minimum slope\n
\n
    $COVERAGE_SAMPLING_FUNCTION\n
\n
    return oe_SplatRenderInfo(primary, detail, brightness, contrast, threshold, slope);\n
}\n
\n
);

    Util = "Splat.util.glsl";
    _sources[Util] = MULTILINE($__HASHTAG__version 120\n
$__HASHTAG__pragma vp_location fragment_coloring\n
\n
uniform vec4 oe_tile_key;  // osgEarth TileKey\n
\n
\n
// Mapping of view ranges to splat texture levels of detail.\n
$__HASHTAG__define RANGE_COUNT 11\n
const float oe_SplatRanges[RANGE_COUNT] = float[](  50.0, 125.0, 250.0, 500.0, 1000.0, 4000.0, 30000.0, 150000.0, 300000.0, 1000000.0, 5000000.0 );\n
const float oe_SplatLevels[RANGE_COUNT] = float[](  20.0,  19.0,  18.0,  17.0,   16.0,   14.0,    12.0,     10.0,      8.0,       6.0,       4.0 );\n
\n
/**\n
 * Given a camera distance, return the two LODs it falls between and\n
 * the blend factor [0..1] between then.\n
 * in  range   = camera distace to fragment\n
 * in  baseLOD = LOD at which texture scale is 1.0\n
 * out LOD0    = near LOD\n
 * out LOD1    = far LOD\n
 * out blend   = Blend factor between LOD0 and LOD1 [0..1]\n
 */\n
void\n
oe_splat_getLodBlend(in float range, in float baseLOD, out float out_LOD0, out float out_LOD1, out float out_range0, out float out_range1, out float out_blend)\n
{\n
    float clampedRange = clamp(range, oe_SplatRanges[0], oe_SplatRanges[RANGE_COUNT-1]);\n
\n
    out_blend = -1.0;\n
    for(int i=0; i<RANGE_COUNT-1 && out_blend < 0; ++i)\n
    {\n
        if ( clampedRange >= oe_SplatRanges[i] && clampedRange <= oe_SplatRanges[i+1] )\n
        {\n
            out_LOD0 = oe_SplatLevels[i]   + baseLOD;\n
            out_LOD1 = oe_SplatLevels[i+1] + baseLOD;\n
            out_range0 = oe_SplatRanges[i];\n
            out_range1 = oe_SplatRanges[i+1];\n
            out_blend = clamp((clampedRange-oe_SplatRanges[i])/(oe_SplatRanges[i+1]-oe_SplatRanges[i]), 0.0, 1.0);\n
        }\n
    }\n
}\n
\n
/**\n
 * Scales the incoming tile splat coordinates to match the requested\n
 * LOD level. We offset the level from the current tile key's LOD (.z)\n
 * because otherwise you run into single-precision jitter at high LODs.\n
 */\n
vec2 \n
oe_splat_getSplatCoords(in vec2 tc, float lod)\n
{\n
    float dL = oe_tile_key.z - lod;\n
    float factor = exp2(dL);\n
    float invFactor = 1.0/factor;\n
    vec2 scale = vec2(invFactor); \n
    vec2 result = tc * scale;\n
\n
    // For upsampling we need to calculate an offset as well\n
    if ( factor >= 1.0 )\n
    {\n
        vec2 a = floor(oe_tile_key.xy * invFactor);\n
        vec2 b = a * factor;\n
        vec2 c = (a+1.0) * factor;\n
        vec2 offset = (oe_tile_key.xy-b)/(c-b);\n
        result += offset;\n
    }\n
\n
    return result;\n
}\n
\n
\n
);
}


LandCoverShaders::LandCoverShaders()
{
    LandCover_TCS = "LandCover.TCS.glsl";
    _sources[LandCover_TCS] = MULTILINE($__HASHTAG__version 400\n
\n
/**\n
 * TCS that assigns a patch grid density.\n
 */\n
 \n
$__HASHTAG__pragma vp_name       LandCover tessellation control shader\n
$__HASHTAG__pragma vp_entryPoint oe_landcover_configureTess\n
$__HASHTAG__pragma vp_location   tess_control\n
\n
layout(vertices=3) out;\n
\n
uniform float oe_landcover_density;\n
\n
// per-vertex tile coordinates\n
vec4 oe_layer_tilec;\n
\n
// SDK function to sample the coverage data\n
int oe_landcover_getBiomeIndex(in vec4);\n
\n
// SDK function to load per-vertex data\n
void VP_LoadVertex(in int);\n
\n
// MAIN ENTRY POINT                \n
void oe_landcover_configureTess()\n
{\n
	if (gl_InvocationID == 0)\n
	{\n
        float d = 0.0;\n
\n
        VP_LoadVertex(0);\n
        if ( oe_landcover_getBiomeIndex(oe_layer_tilec) >= 0 ) {\n
            d = oe_landcover_density;\n
        }\n
        else {\n
            VP_LoadVertex(1);\n
            if ( oe_landcover_getBiomeIndex(oe_layer_tilec) >= 0 ) {\n
                d = oe_landcover_density;\n
                VP_LoadVertex(0);\n
            }\n
            else {\n
                VP_LoadVertex(2);\n
                if ( oe_landcover_getBiomeIndex(oe_layer_tilec) >= 0 ) {\n
                    d = oe_landcover_density;\n
                    VP_LoadVertex(0);\n
                }\n
            }\n
        }\n
\n
        gl_TessLevelOuter[0] = d;\n
        gl_TessLevelOuter[1] = d;\n
        gl_TessLevelOuter[2] = d;\n
        gl_TessLevelInner[0] = d;\n
	}\n
}\n
\n
);

    LandCover_TES = "LandCover.TES.glsl";
    _sources[LandCover_TES] = MULTILINE($__HASHTAG__version 410\n
\n
$__HASHTAG__pragma vp_name       LandCover TES Shader\n
$__HASHTAG__pragma vp_entryPoint oe_landcover_tessellate\n
$__HASHTAG__pragma vp_location   tess_eval\n
\n
// osgEarth terrain is always CCW winding\n
layout(triangles, fractional_odd_spacing, ccw) in;\n
\n
// Internal helpers:\n
void VP_Interpolate3();\n
void VP_EmitVertex();\n
\n
float VP_Interpolate3(float a, float b, float c) \n
{\n
    return dot(gl_TessCoord.xyz, vec3(a,b,c));\n
}\n
\n
vec2 VP_Interpolate3(vec2 a, vec2 b, vec2 c) \n
{\n
    return vec2(dot(gl_TessCoord.xyz, vec3(a.x,b.x,c.x)),\n
	dot(gl_TessCoord.xyz, vec3(a.y,b.y,c.y)));\n
}\n
\n
vec3 VP_Interpolate3(vec3 a, vec3 b, vec3 c) \n
{\n
    return vec3(dot(gl_TessCoord.xyz, vec3(a.x,b.x,c.x)),\n
	dot(gl_TessCoord.xyz, vec3(a.y,b.y,c.y)),\n
	dot(gl_TessCoord.xyz, vec3(a.z,b.z,c.z)));\n
}\n
\n
vec4 VP_Interpolate3(vec4 a, vec4 b, vec4 c) \n
{\n
    return vec4(dot(gl_TessCoord.xyz, vec3(a.x,b.x,c.x)),\n
				dot(gl_TessCoord.xyz, vec3(a.y,b.y,c.y)),\n
				dot(gl_TessCoord.xyz, vec3(a.z,b.z,c.z)),\n
				dot(gl_TessCoord.xyz, vec3(a.w,b.w,c.w)));\n
}\n
\n
                \n
vec3 vp_Normal;\n
\n
// simplest possible pass-though:\n
void oe_landcover_tessellate()\n
{\n
    VP_Interpolate3();\n
    // Must re-normalize the normal vector since interpolation was linear?\n
	//vp_Normal = normalize(vp_Normal);\n
    VP_EmitVertex();\n
}\n
\n
);

    LandCover_GS = "LandCover.GS.glsl";
    _sources[LandCover_GS] = MULTILINE($__HASHTAG__version 400 compatibility\n
$__HASHTAG__pragma vp_name       LandCover geometry shader\n
$__HASHTAG__pragma vp_entryPoint oe_landcover_geom\n
$__HASHTAG__pragma vp_location   geometry\n
                \n
layout(triangles)        in;        // triangles from the TileDrawable\n
layout(triangle_strip)   out;       // output a triangle-strip billboard\n
layout(max_vertices = 8) out;       // four verts per billboard\n
                \n
// VP helper functions:\n
void VP_LoadVertex(in int);\n
void VP_EmitViewVertex();\n
\n
uniform float osg_FrameTime;            // Frame time (seconds) used for wind animation\n
                \n
uniform float oe_landcover_width;           // width of each billboard\n
uniform float oe_landcover_height;          // height of each billboard\n
uniform float oe_landcover_ao;              // fake ambient occlusion of ground verts (0=full)\n
\n
uniform float oe_landcover_fill;            // percentage of points that make it through, based on noise function\n
uniform float oe_landcover_windFactor;      // wind blowing the foliage\n
uniform float oe_landcover_maxDistance;     // distance at which flora disappears\n
\n
uniform float oe_landcover_contrast;\n
uniform float oe_landcover_brightness;\n
\n
uniform sampler2D oe_tile_elevationTex;\n
uniform mat4      oe_tile_elevationTexMatrix;\n
uniform float     oe_tile_elevationSize;\n
\n
uniform bool oe_isShadowCamera;\n
\n
// Noise texture:\n
uniform sampler2D oe_splat_noiseTex;\n
\n
// different noise texture channels:\n
$__HASHTAG__define NOISE_SMOOTH   0\n
$__HASHTAG__define NOISE_RANDOM   1\n
$__HASHTAG__define NOISE_RANDOM_2 2\n
$__HASHTAG__define NOISE_CLUMPY   3\n
\n
// Input tile coordinates [0..1]\n
in vec4 oe_layer_tilec;\n
\n
// Output grass texture coordinates to the fragment shader\n
out vec2 oe_landcover_texCoord;\n
\n
// Input from the TCS that \n
//flat in int oe_landcover_biomeIndex;\n
\n
// Output that selects the land cover texture from the texture array (non interpolated)\n
flat out float oe_landcover_arrayIndex;\n
\n
struct oe_landcover_Biome {\n
    int firstBillboardIndex;\n
    int numBillboards;\n
    float density;\n
    float fill;\n
    vec2 maxWidthHeight;\n
};\n
void oe_landcover_getBiome(in int biomeIndex, out oe_landcover_Biome biome);\n
\n
struct oe_landcover_Billboard {\n
    int arrayIndex;\n
    float width;\n
    float height;\n
};\n
void oe_landcover_getBillboard(in int billboardIndex, out oe_landcover_Billboard bb);\n
\n
\n
// Output colors/normals:\n
out vec4 vp_Color;\n
out vec3 vp_Normal;\n
\n
// Up vector for clamping.\n
in vec3 oe_UpVectorView;\n
\n
// SDK import\n
float oe_terrain_getElevation(in vec2);\n
\n
// Generated in code\n
int oe_landcover_getBiomeIndex(in vec4);\n
\n
uniform bool oe_landcover_useMask;\n
uniform sampler2D MASK_SAMPLER;\n
uniform mat4 MASK_TEXTURE;\n
\n
\n
// Sample the elevation texture and move the vertex accordingly.\n
void\n
oe_landcover_clamp(inout vec4 vert_view, in vec3 up, vec2 UV)\n
{\n
    float elev = oe_terrain_getElevation( UV );\n
    vert_view.xyz += up*elev;\n
}\n
\n
// Generate a pseudo-random value in the specified range:\n
float\n
oe_landcover_rangeRand(float minValue, float maxValue, vec2 co)\n
{\n
    float t = fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);\n
    return minValue + t*(maxValue-minValue);\n
}\n
\n
// Generate a wind-perturbation value\n
float\n
oe_landcover_applyWind(float time, float factor, float randOffset)\n
{\n
   return sin(time + randOffset) * factor;\n
}\n
\n
// Generate a pseudo-random barycentric point inside a triangle.\n
vec3\n
oe_landcover_getRandomBarycentricPoint(vec2 seed)\n
{\n
    vec3 b;\n
    b[0] = oe_landcover_rangeRand(0.0, 1.0, seed.xy);\n
    b[1] = oe_landcover_rangeRand(0.0, 1.0, seed.yx);\n
    if (b[0]+b[1] >= 1.0)\n
    {\n
        b[0] = 1.0 - b[0];\n
        b[1] = 1.0 - b[1];\n
    }\n
    b[2] = 1.0 - b[0] - b[1];\n
    return b;\n
}\n
\n
// MAIN ENTRY POINT  \n
void\n
oe_landcover_geom()\n
{    \n
    vec4 center = vec4(0,0,0,1);\n
    vec2 tileUV = vec2(0,0);\n
    \n
    // gen a random point within the input triangle\n
    vec3 b = oe_landcover_getRandomBarycentricPoint(gl_in[0].gl_Position.xy);\n
    \n
    // Load the triangle data and compute the new position and tile coords\n
    // using the barycentric coordinates.\n
    for(int i=0; i < 3; ++i)\n
    {\n
        VP_LoadVertex(i);      \n
        \n
        center.x += b[i] * gl_in[i].gl_Position.x;\n
        center.y += b[i] * gl_in[i].gl_Position.y;\n
        center.z += b[i] * gl_in[i].gl_Position.z;\n
        \n
        tileUV.x += b[i] * oe_layer_tilec.x;\n
        tileUV.y += b[i] * oe_layer_tilec.y;\n
    }\n
    \n
$__HASHTAG__if 1\n
    // Look up the biome at this point:\n
    int biomeIndex = oe_landcover_getBiomeIndex(vec4(tileUV,0,1));\n
    if ( biomeIndex < 0 )\n
    {\n
        // No biome defined; bail out without emitting any geometry.\n
        return;\n
    }\n
$__HASHTAG__else\n
    int biomeIndex = oe_landcover_biomeIndex;\n
$__HASHTAG__endif\n
    \n
    // If we're using a mask texture, sample it now:\n
    if ( oe_landcover_useMask )\n
    {\n
        float mask = texture(MASK_SAMPLER, (MASK_TEXTURE*vec4(tileUV,0,1)).st).a;\n
        if ( mask > 0.0 )\n
        {\n
            // Failed to pass the mask; no geometry emitted.\n
            return;\n
        }\n
    }\n
    \n
    // Transform to view space.\n
    vec4 center_view = gl_ModelViewMatrix * center;\n
    vec3 up_view     = oe_UpVectorView;\n
    \n
    // Clamp the center point to the elevation.\n
    oe_landcover_clamp(center_view, up_view, tileUV);\n
\n
    // Calculate the normalized camera range:\n
    float nRange = clamp(-center_view.z/oe_landcover_maxDistance, 0.0, 1.0);\n
\n
    // Distance culling:\n
    if ( nRange == 1.0 )\n
        return;\n
\n
    // look up biome:\n
    oe_landcover_Biome biome;\n
    oe_landcover_getBiome(biomeIndex, biome);\n
    \n
    // Viewpoint culling:\n
    // TODO: remove hard-coded max width/height and replace with a vp_define or a uniform.\n
    // Note: this value must account for the height variation introduced by the noise function\n
    // later in this shader!\n
    vec4 cullPoint = center_view;\n
    cullPoint.xy -= sign(cullPoint.xy) * min(biome.maxWidthHeight, abs(cullPoint.xy));\n
    cullPoint = gl_ProjectionMatrix * cullPoint;\n
    float absw = abs(cullPoint.w);\n
    if ( abs(cullPoint.x) > absw || abs(cullPoint.y) > absw )// || abs(cullPoint.z) > absw )\n
        return;\n
\n
    // sample the noise texture.\n
    vec4 noise = texture(oe_splat_noiseTex, tileUV);\n
\n
    // discard instances based on noise value threshold (coverage). If it passes,\n
    // scale the noise value back up to [0..1]\n
    if ( noise[NOISE_SMOOTH] > oe_landcover_fill )\n
        return;\n
    else\n
        noise[NOISE_SMOOTH] /= oe_landcover_fill;\n
\n
    // select a billboard seemingly at random. Need to scale n to account for the fill limit first though.\n
    int billboardIndex = biome.firstBillboardIndex + int( floor(noise[NOISE_RANDOM] * float(biome.numBillboards) ) );\n
    billboardIndex = min(billboardIndex, biome.firstBillboardIndex + biome.numBillboards - 1);\n
\n
    oe_landcover_Billboard billboard;\n
    oe_landcover_getBillboard(billboardIndex, billboard);\n
    \n
    // pass the billboard's array index along to the fragment shader.\n
    oe_landcover_arrayIndex = float(billboard.arrayIndex);\n
    \n
	\n
    // push the falloff closer to the max distance.\n
    float falloff = 1.0-(nRange*nRange*nRange);\n
\n
    // billboard width, which shrinks into the distance\n
    float width = billboard.width * falloff;\n
    \n
    // vary the height of each instance and shrink it as it disappears into the distance.\n
    float height = billboard.height;\n
    height *= abs(1.0 + noise[NOISE_RANDOM_2]);\n
    height *= falloff;\n
\n
	// compute the billboard corners in view space.\n
    vec4 LL, LR, UL, UR;\n
    \n
    if ( oe_isShadowCamera == false )\n
    {\n
        vec3 tangentVector = normalize(cross(vec3(0,0,-1), up_view));\n
        vec3 halfWidthTangentVector = tangentVector * 0.5 * width;\n
        vec3 heightVector = up_view*height;\n
        \n
        LL = vec4(center_view.xyz - halfWidthTangentVector, 1.0);\n
        LR = vec4(center_view.xyz + halfWidthTangentVector, 1.0);\n
        UL = vec4(LL.xyz + heightVector, 1.0);\n
        UR = vec4(LR.xyz + heightVector, 1.0);\n
                      \n
        // TODO: animate based on wind parameters.\n
        float nw = noise[NOISE_SMOOTH];\n
        float wind = width*oe_landcover_windFactor*nw;\n
        UL.x += oe_landcover_applyWind(osg_FrameTime*(1+nw), wind, UL.x);\n
        UR.x += oe_landcover_applyWind(osg_FrameTime*(1-nw), wind, tileUV.t);\n
    \n
        // Color variation, brightness, and contrast:\n
        vec3 color = vec3( noise[NOISE_RANDOM_2] );\n
        color = ( ((color - 0.5) * oe_landcover_contrast + 0.5) * oe_landcover_brightness);\n
\n
        vp_Color = vec4(color*oe_landcover_ao, falloff);\n
\n
        // calculates normals:\n
        vec3 faceNormalVector = normalize(cross(tangentVector, heightVector));\n
        float blend = 0.25 + (noise[NOISE_RANDOM_2]*0.25);\n
        vec3 Lnormal = mix(-tangentVector, faceNormalVector, blend);\n
        vec3 Rnormal = mix( tangentVector, faceNormalVector, blend);\n
\n
        gl_Position = LL;\n
        oe_landcover_texCoord = vec2(0,0);\n
        vp_Normal = Lnormal;\n
        VP_EmitViewVertex();\n
    \n
        gl_Position = LR;\n
        oe_landcover_texCoord = vec2(1,0);\n
        vp_Normal = Rnormal;\n
        VP_EmitViewVertex();\n
\n
        vp_Color = vec4(color, falloff);      \n
\n
        gl_Position = UL;\n
        oe_landcover_texCoord = vec2(0,1);\n
        vp_Normal = Lnormal;\n
        VP_EmitViewVertex();\n
\n
        oe_landcover_texCoord = vec2(1,1);\n
        vp_Normal = Rnormal;\n
        gl_Position = UR;\n
        VP_EmitViewVertex();\n
                    \n
        EndPrimitive();\n
    }\n
    else\n
    {\n
        // generating cross-hatch geometry (for shadowing)\n
\n
        vec3 eastVector = gl_NormalMatrix * vec3(1,0,0);\n
        vec3 halfWidthTangentVector = cross(eastVector, up_view) * 0.5 * width;\n
        vec3 heightVector = up_view*height;\n
\n
        vp_Color = vec4(1,1,1,falloff);\n
\n
        for(int i=0; i<2; ++i)\n
        {\n
            LL = vec4(center_view.xyz - halfWidthTangentVector, 1.0);\n
            LR = vec4(center_view.xyz + halfWidthTangentVector, 1.0);\n
            UL = vec4(LL.xyz + heightVector, 1.0);\n
            UR = vec4(LR.xyz + heightVector, 1.0);\n
    \n
            gl_Position = LL;\n
            oe_landcover_texCoord = vec2(0,0);\n
            VP_EmitViewVertex();\n
    \n
            gl_Position = LR;\n
            oe_landcover_texCoord = vec2(1,0);\n
            VP_EmitViewVertex();    \n
\n
            gl_Position = UL;\n
            oe_landcover_texCoord = vec2(0,1);\n
            VP_EmitViewVertex();\n
\n
            oe_landcover_texCoord = vec2(1,1);\n
            gl_Position = UR;\n
            VP_EmitViewVertex();\n
                    \n
            EndPrimitive();\n
\n
            halfWidthTangentVector = cross(halfWidthTangentVector, up_view);\n
        }\n
    }\n
}\n
\n
);

    LandCover_FS = "LandCover.FS.glsl";
    _sources[LandCover_FS] = MULTILINE($__HASHTAG__version 330\n
$__HASHTAG__pragma vp_name       Land cover billboard texture application\n
$__HASHTAG__pragma vp_entryPoint oe_landcover_fragment\n
$__HASHTAG__pragma vp_location   fragment_coloring\n
\n
$__HASHTAG__define IS_ARRAY\n
                     \n
uniform bool oe_terrain_hasMultiSamples;\n
\n
$__HASHTAG__ifdef IS_ARRAY\n
\n
uniform sampler2DArray oe_landcover_texArray;\n
uniform float oe_landcover_exposure;\n
in vec2 oe_landcover_texCoord;\n
in vec4 oe_layer_tilec;\n
\n
flat in float oe_landcover_arrayIndex; // from LandCover.GS.glsl\n
\n
void oe_landcover_fragment(inout vec4 color)\n
{    \n
    // modulate the texture\n
    color = texture(oe_landcover_texArray, vec3(oe_landcover_texCoord, oe_landcover_arrayIndex)) * color;\n
    color.rgb *= oe_landcover_exposure;\n
    \n
    // if multisampling is off, use alpha-discard.\n
    if ( !oe_terrain_hasMultiSamples && color.a < 0.15 )\n
        discard;\n
}\n
\n
$__HASHTAG__else\n
\n
uniform sampler2D oe_landcover_tex;\n
uniform float oe_landcover_exposure;\n
\n
in vec2 oe_landcover_texCoord;\n
in vec4 oe_layer_tilec;\n
\n
void oe_landcover_fragment(inout vec4 color)\n
{    \n
    // modulate the texture\n
    color = texture(oe_landcover_tex, oe_landcover_texCoord) * color;\n
    color.rgb *= oe_landcover_exposure;\n
    \n
    // if multisampling is off, use alpha-discard.\n
    if ( !oe_terrain_hasMultiSamples && color.a < 0.15 )\n
        discard;\n
}\n
\n
$__HASHTAG__endif\n
);
}

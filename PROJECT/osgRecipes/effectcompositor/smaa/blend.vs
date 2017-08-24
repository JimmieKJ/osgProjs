varying vec4 offset1;
varying vec4 offset2;
varying vec4 offset3;
#define SMAA_PIXEL_SIZE vec2(1.0/1920.0, 1.0/1080.0)
#define SMAA_MAX_SEARCH_STEPS 8

void main()
{
    gl_Position = ftransform();
    gl_TexCoord[0] = gl_MultiTexCoord0;
    offset1 = gl_TexCoord[0].xyxy + SMAA_PIXEL_SIZE.xyxy * vec4(-0.25, -0.125, 1.25, -0.125);
    offset2 = gl_TexCoord[0].xyxy + SMAA_PIXEL_SIZE.xyxy * vec4(-0.125,-0.25, -0.125, 1.25);
    offset3 = vec4(offset1.xz, offset2.yw) + vec4(-2.0, 2.0, -2.0, 2.0) *
              SMAA_PIXEL_SIZE.xxyy * (float)(SMAA_MAX_SEARCH_STEPS);
}

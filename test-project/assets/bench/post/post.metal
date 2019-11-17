#include <metal_stdlib>

using namespace metal;

typedef struct {
	float4 position [[position]];
	float2 uv;
} RasterizerData;

typedef struct {
	float4 position [[attribute(0)]];
	float2 uv [[attribute(1)]];
} SpruceVertex;

vertex RasterizerData vertexShader(SpruceVertex vert [[stage_in]]) {
	RasterizerData out;
	out.position = vert.position;
    vert.uv.y = 1 - vert.uv.y;
	out.uv = vert.uv;
	return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]], texture2d<float> colorTexture [[texture(1)]]) {
	constexpr sampler textureSampler(mag_filter::linear, min_filter::linear);
	const float4 colorSample = colorTexture.sample(textureSampler, in.uv);
	return float4(colorSample);
}

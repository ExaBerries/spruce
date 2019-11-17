#include <metal_stdlib>

using namespace metal;

typedef struct {
	float4 position [[position]];
	float4 shadowPos;
} RasterizerData;

typedef struct {
	float3 position [[attribute(0)]];
} SpruceVertex;

vertex RasterizerData vertexShader(SpruceVertex vert [[stage_in]], constant float4x4& camera [[buffer(1)]], constant float4x4& worldTrans [[buffer(2)]], constant float4x4& shadowCamera [[buffer(3)]]) {
	RasterizerData out;
	out.position = camera * worldTrans * float4(vert.position, 1);
	out.shadowPos = shadowCamera * worldTrans * float4(vert.position, 1);
	return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]], depth2d<float> shadowMap [[texture(4)]], constant float4& color [[buffer(5)]]) {
	float intensity = 1.0;
	float2 xy = in.shadowPos.xy;
	xy.y = 1 - xy.y;
	constexpr sampler depthSampler(mag_filter::linear, min_filter::linear);
	if (shadowMap.sample(depthSampler, xy) < in.shadowPos.z - 0.001) {
		intensity = 0.5;
	}
    return float4(color.rgb * intensity, color.a);
}

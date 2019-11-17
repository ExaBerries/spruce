#include <metal_stdlib>

using namespace metal;

typedef struct {
	float4 position [[position]];
} RasterizerData;

typedef struct {
	float3 position [[attribute(0)]];
} SpruceVertex;

vertex RasterizerData vertexShader(SpruceVertex vert [[stage_in]], constant float4x4& camera [[buffer(1)]], constant float4x4& worldTrans [[buffer(2)]]) {
	RasterizerData out;
	out.position = camera * worldTrans * float4(vert.position, 1.0f);
	return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]], constant float4& color [[buffer(3)]]) {
    float intensity = 1.0f;
    return float4(color.rgb * intensity, color.a);
}

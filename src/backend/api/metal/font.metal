R"***(
#include <metal_stdlib>

using namespace metal;

typedef struct {
	float4 position [[position]];
	float2 texCoord;
} RasterizerData;

typedef struct {
	float3 position [[attribute(0)]];
	float2 texCoord [[attribute(1)]];
} SpruceVertex;

vertex RasterizerData vertexShader(SpruceVertex vert [[stage_in]], constant float4x4& camera [[buffer(1)]]) {
	RasterizerData out;
	out.position = camera * float4(vert.position, 1);
	out.texCoord = vert.texCoord;
	return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]], texture2d<float> tex [[texture(2)]], constant float4& color [[buffer(3)]]) {
	constexpr sampler textureSampler(mag_filter::linear, min_filter::linear);
	return tex.sample(textureSampler, in.texCoord);
	//float alpha = tex.sample(textureSampler, in.texCoord).r;
	//return float4(1, 1, 1, alpha) * color;
}
)***"

#include <metal_stdlib>

using namespace metal;

typedef struct {
	float3 position [[attribute(0)]];
} SpruceVertex;

vertex float4 vertexShader(SpruceVertex vert [[stage_in]], constant float4x4& camera [[buffer(1)]], constant float4x4& worldTrans [[buffer(2)]]) {
	return camera * worldTrans * float4(vert.position, 1.0);
}

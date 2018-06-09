R"***(
#include <metal_stdlib>

using namespace metal;

typedef struct {
    float4 position [[position]];
    float4 color;
} RasterizerData;

typedef struct {
    float3 position [[attribute(0)]];
    float4 color [[attribute(1)]];
} SpruceVertex;

vertex RasterizerData vertexShader(SpruceVertex vert [[stage_in]], constant float4x4& camera [[buffer(1)]]) {
    RasterizerData out;
    out.position = camera * float4(vert.position, 1);
    out.color = vert.color;
    return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]]) {
    return in.color;
}
)***"


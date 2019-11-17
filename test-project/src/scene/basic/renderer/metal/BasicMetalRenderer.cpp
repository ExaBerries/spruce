#include <scene/basic/renderer/metal/BasicMetalRenderer.h>
#ifdef __APPLE__
#include <scene/basic/Basic.h>
#include <scene/basic/renderer/metal/BasicMetalMeshData.h>
#include <simd/simd.h>

namespace sprucetest {
	BasicMetalRenderer::BasicMetalRenderer(Application& app) : MetalRenderer<Basic, BasicRendererData>(app) {
		queue = context.device.createCommandQueue();
		MetalRenderPipelineDescriptor pipelineDescriptor;
		string shdrStr = io::readFileTxt({FileHandle::INTERNAL, "basic/default/default.metal"});
		library = context.device.createLibrary(shdrStr);
		vertFn = library->newFunctionWithName("vertexShader");
		fragFn = library->newFunctionWithName("fragmentShader");
		pipelineDescriptor.setVertexFunction(vertFn);
		pipelineDescriptor.setFragmentFunction(fragFn);
		pipelineDescriptor.setColorAttachmentPixelFormat(0, MetalPixelFormat::BGRA8UNORM);
		pipelineDescriptor.setColorAttachmentBlending(0, false);
		pipelineDescriptor.setDepthAttachmentPixelFormat(MetalPixelFormat::DEPTH32FLOAT);
		MetalVertexDescriptor vertexDescriptor;
		vertexDescriptor.setAttribute(0, MetalVertexFormat::FLOAT3, 0, 0);
		vertexDescriptor.setLayout(0, MetalVertexStepFunction::PER_VERTEX, sizeof(float) * 3, 1);
		pipelineDescriptor.setVertexDescriptor(vertexDescriptor);
		pipelineState = context.device.newRenderPipelineState(pipelineDescriptor);
		depthStencilState = context.device.newDepthStencilState(MetalCompareFunction::LESS, true);
	}

	BasicMetalRenderer::~BasicMetalRenderer() {
		delete (MetalCommandQueue*)queue;
		delete (MetalRenderPipelineState*)pipelineState;
		delete (MetalFunction*)vertFn;
		delete (MetalFunction*)fragFn;
		delete (MetalLibrary*)library;
		delete (MetalDepthStencilState*)depthStencilState;
	}

	BasicRendererData BasicMetalRenderer::encode(Basic& encodeData) {
		encodeData.camera->update(this);
		BasicRendererData data;
		data.windowSize = encodeData.windowSize;
		data.cameraTrans = encodeData.camera->combined;
		data.cubeMesh = encodeData.cubeMesh;
		vec3f pos(0, 0, 0);
		quaternion rot(0, 0, 0, 1);
		vec3f scale(1, 1, 1);
		data.worldTrans = mat4f(pos, rot, scale);
		data.color = color(1, 1, 1, 1);
		return data;
	}

	void BasicMetalRenderer::execute(BasicRendererData& executeData) {
		context.setDrawableSize(executeData.windowSize);
		context.setVSync(true);
		owner<MetalCommandBuffer> cmdBuffer = queue->createCommandBuffer();
		cmdBuffer->enqueue();
		owner<MetalDrawable> drawable = context.getDrawable();
		owner<MetalTexture> depthTexture = context.device.createTexture(MetalPixelFormat::DEPTH32FLOAT, executeData.windowSize, false, MetalResourceStorageMode::PRIVATE, MetalStorageMode::PRIVATE, MetalTextureUsage::RENDER_TARGET | MetalTextureUsage::SHADER_READ);
		MetalRenderPassDescriptor passDescriptor;
		passDescriptor.setColorAttachment(0, drawable->texture, MetalLoadAction::CLEAR, MetalStoreAction::STORE, {0, 0, 0, 1});
		passDescriptor.setDepthAttachment(depthTexture, MetalLoadAction::CLEAR, MetalStoreAction::STORE, 1.0);
		owner<MetalRenderCommandEncoder> encoder = cmdBuffer->createRenderCommandEncoder(passDescriptor);
		encoder->setRenderPipelineState(pipelineState);
		encoder->setViewport({0, 0}, {(double)executeData.windowSize.x, (double)executeData.windowSize.y}, 0, 1);
		encoder->setDepthStencilState(depthStencilState);

		vector_float4 cr0 = {executeData.cameraTrans.values[0],executeData.cameraTrans.values[1],executeData.cameraTrans.values[2],executeData.cameraTrans.values[3]};
		vector_float4 cr1 = {executeData.cameraTrans.values[4],executeData.cameraTrans.values[5],executeData.cameraTrans.values[6],executeData.cameraTrans.values[7]};
		vector_float4 cr2 = {executeData.cameraTrans.values[8],executeData.cameraTrans.values[9],executeData.cameraTrans.values[10],executeData.cameraTrans.values[11]};
		vector_float4 cr3 = {executeData.cameraTrans.values[12],executeData.cameraTrans.values[13],executeData.cameraTrans.values[14],executeData.cameraTrans.values[15]};
		matrix_float4x4 cmat = matrix_from_rows(cr0,cr1,cr2,cr3);
		encoder->setVertexBytes(&cmat, sizeof(cmat), 1);

		vector_float4 wr0 = {executeData.worldTrans.values[0],executeData.worldTrans.values[1],executeData.worldTrans.values[2],executeData.worldTrans.values[3]};
		vector_float4 wr1 = {executeData.worldTrans.values[4],executeData.worldTrans.values[5],executeData.worldTrans.values[6],executeData.worldTrans.values[7]};
		vector_float4 wr2 = {executeData.worldTrans.values[8],executeData.worldTrans.values[9],executeData.worldTrans.values[10],executeData.worldTrans.values[11]};
		vector_float4 wr3 = {executeData.worldTrans.values[12],executeData.worldTrans.values[13],executeData.worldTrans.values[14],executeData.worldTrans.values[15]};
		matrix_float4x4 wmat = matrix_from_rows(wr0,wr1,wr2,wr3);
		encoder->setVertexBytes(&wmat, sizeof(wmat), 2);

		vector_float4 col = {executeData.color.r, executeData.color.g, executeData.color.b, executeData.color.a};
		encoder->setFragmentBytes(&col, sizeof(col), 3);

		encoder->setVertexBuffer(((BasicMetalMeshData*)executeData.cubeMesh->apiData)->vertexBuffer, 0, 0);
		encoder->drawIndexedPrimitives(MetalPrimitive::TRIANGLE, executeData.cubeMesh->indices.size, MetalIndexType::UINT16, ((BasicMetalMeshData*)executeData.cubeMesh->apiData)->indexBuffer, 0);

		encoder->endEncoding();
		cmdBuffer->presentDrawable(drawable);
		cmdBuffer->commit();
		delete (MetalDrawable*)drawable;
		delete (MetalTexture*)depthTexture;
		delete (MetalRenderCommandEncoder*)encoder;
		delete (MetalCommandBuffer*)cmdBuffer;
	}

	owner<MeshAPIData> BasicMetalRenderer::createMeshAPIData(Mesh& mesh) {
		return new BasicMetalMeshData(mesh, context);
	}

	owner<TextureAPIData> BasicMetalRenderer::createTextureAPIData(Texture& texture) {
		return nullptr;
	}
}
#endif

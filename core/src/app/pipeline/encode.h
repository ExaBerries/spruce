#pragma once
#include <common.h>
#include <app/pipeline/Frame.h>
#include <app/Application.h>
#include <graphics/renderer/RendererAbstractor.h>

namespace spruce {
	void encodeFrame(Frame& frame, float delta, Application& app, RendererAbstractor* renderer) noexcept;
}

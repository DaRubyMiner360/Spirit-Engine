#include "hzpch.h"
#include "SpiritEngine/Renderer/RenderCommand.h"

namespace SpiritEngine {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
#include "hzpch.h"
#include "SpiritEngine/Renderer/GraphicsContext.h"

#include "SpiritEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace SpiritEngine {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    SPIRIT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		SPIRIT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
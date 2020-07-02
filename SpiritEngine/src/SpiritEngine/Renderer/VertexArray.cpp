#include "hzpch.h"
#include "SpiritEngine/Renderer/VertexArray.h"

#include "SpiritEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace SpiritEngine {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    SPIRIT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		SPIRIT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
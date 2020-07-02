#include "hzpch.h"
#include "SpiritEngine/Core/Window.h"

#ifdef SPIRIT_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace SpiritEngine
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef SPIRIT_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		SPIRIT_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}
#include "hzpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace SpiritEngine {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SPIRIT_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		SPIRIT_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SPIRIT_CORE_ASSERT(status, "Failed to initialize Glad!");

		SPIRIT_CORE_INFO("OpenGL Info:");
		SPIRIT_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		SPIRIT_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		SPIRIT_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	#ifdef SPIRIT_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		SPIRIT_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "SpiritEngine requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		SPIRIT_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}

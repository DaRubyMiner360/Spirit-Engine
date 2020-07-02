#pragma once
#include "SpiritEngine/Core/Base.h"

#ifdef SPIRIT_PLATFORM_WINDOWS

extern SpiritEngine::Application* SpiritEngine::CreateApplication();

int main(int argc, char** argv)
{
	SpiritEngine::Log::Init();

	SPIRIT_PROFILE_BEGIN_SESSION("Startup", "SpiritEngineProfile-Startup.json");
	auto app = SpiritEngine::CreateApplication();
	SPIRIT_PROFILE_END_SESSION();

	SPIRIT_PROFILE_BEGIN_SESSION("Runtime", "SpiritEngineProfile-Runtime.json");
	app->Run();
	SPIRIT_PROFILE_END_SESSION();

	SPIRIT_PROFILE_BEGIN_SESSION("Shutdown", "SpiritEngineProfile-Shutdown.json");
	delete app;
	SPIRIT_PROFILE_END_SESSION();
}

#endif

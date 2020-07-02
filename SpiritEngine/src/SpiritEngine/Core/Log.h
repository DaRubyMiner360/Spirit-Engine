#pragma once

#include "Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace SpiritEngine {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SPIRIT_CORE_TRACE(...)    ::SpiritEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SPIRIT_CORE_INFO(...)     ::SpiritEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SPIRIT_CORE_WARN(...)     ::SpiritEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SPIRIT_CORE_WARNING(...)     ::SpiritEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SPIRIT_CORE_ERROR(...)    ::SpiritEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SPIRIT_CORE_CRITICAL(...) ::SpiritEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SPIRIT_TRACE(...)         ::SpiritEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SPIRIT_INFO(...)          ::SpiritEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SPIRIT_WARN(...)          ::SpiritEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SPIRIT_WARNING(...)          ::SpiritEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SPIRIT_ERROR(...)         ::SpiritEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SPIRIT_CRITICAL(...)      ::SpiritEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
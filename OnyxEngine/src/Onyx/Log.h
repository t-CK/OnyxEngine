#pragma once

// Onyx engine
#include "Core.h"
// Vendors
#include <spdlog/spdlog.h>

namespace Onyx
{

	class ONYX_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#if _DEBUG
// Core log macros
#define ONYX_CORE_FATAL(...)   ::Onyx::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define ONYX_CORE_ERROR(...)   ::Onyx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ONYX_CORE_WARNING(...) ::Onyx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ONYX_CORE_INFO(...)    ::Onyx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ONYX_CORE_TRACE(...)   ::Onyx::Log::GetCoreLogger()->trace(__VA_ARGS__)
							   
// Client log macros		   
#define ONYX_FATAL(...)        ::Onyx::Log::GetClientLogger()->critical(__VA_ARGS__)
#define ONYX_ERROR(...)        ::Onyx::Log::GetClientLogger()->error(__VA_ARGS__)
#define ONYX_WARNING(...)      ::Onyx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ONYX_INFO(...)         ::Onyx::Log::GetClientLogger()->info(__VA_ARGS__)
#define ONYX_TRACE(...)        ::Onyx::Log::GetClientLogger()->trace(__VA_ARGS__)

#else
#define ONYX_CORE_FATAL(...)
#define ONYX_CORE_ERROR(...)
#define ONYX_CORE_WARNING(...)
#define ONYX_CORE_INFO(...)
#define ONYX_CORE_ASSERT(x, ...)

#define ONYX_FATAL(...)
#define ONYX_ERROR(...)
#define ONYX_WARNING(...)
#define ONYX_INFO(...)

#endif
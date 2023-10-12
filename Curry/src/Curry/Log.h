#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Curry {
	class CURRY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define CURRY_CORE_TRACE(...)	::Curry::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CURRY_CORE_INFO(...)	::Curry::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CURRY_CORE_WARN(...)	::Curry::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CURRY_CORE_ERROR(...)	::Curry::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CURRY_CORE_CRITICAL(...)	::Curry::Log::GetCoreLogger()->critical(__VA_ARGS__)


// Client Log Macros
#define CURRY_TRACE(...)		::Curry::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CURRY_INFO(...)			::Curry::Log::GetClientLogger()->info(__VA_ARGS__)
#define CURRY_WARN(...)			::Curry::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CURRY_ERROR(...)		::Curry::Log::GetClientLogger()->error(__VA_ARGS__)
#define CURRY_CRITICAL(...)		::Curry::Log::GetClientLogger()->critical(__VA_ARGS__)



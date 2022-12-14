#pragma once

#ifdef ONYX_PLATFORM_WINDOWS
	#ifdef ONYX_BUILD_DLL
		#define ONYX_API __declspec(dllexport)
	#else 
		#define ONYX_API __declspec(dllimport)
	#endif // ONYX_BUILD_DLL
#else
	#error Onyx currently supports Windows only

#endif // ONYX_PLATFORM_WINDOWS

#ifdef ONYX_ENABLE_ASSERTS
    #define ONYX_CORE_ASSERT(x, ...) (if(!x) { ONYX_ERROR("Assertion failed", __VA_ARGS__); __debugbreak();}
    #define ONYX_ASSERT(x, ...) (if(!x) { ONYX_ERROR("Assertion failed", __VA_ARGS__); __debugbreak();}
#else
    #define ONYX_CORE_ASSERT(x, ...)
    #define ONYX_ASSERT(x, ...)
#endif // ONYX_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
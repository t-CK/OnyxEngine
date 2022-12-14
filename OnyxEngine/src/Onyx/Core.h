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

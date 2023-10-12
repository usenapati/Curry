#pragma once

#ifdef CRRY_PLATFORM_WINDOWS
	#ifdef CRRY_BUILD_DLL
		#define CURRY_API __declspec(dllexport)
	#else
		#define CURRY_API __declspec(dllimport)
	#endif
#else
	#error Curry only supports Windows!
#endif

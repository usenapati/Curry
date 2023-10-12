workspace "Curry"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Curry"
	location "Curry"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h}",
		"%{prj.name}/src/**.cpp}"
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"CRRY_PLATFORM_WINDOWS",
			"CRRY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath}  ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "CRRY_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "CRRY_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CRRY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h}",
		"%{prj.name}/src/**.cpp}"
	}

	includedirs
	{
		"Curry/vendor/spdlog/include",
		"Curry/src"
	}

	links
	{
		"Curry"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"CRRY_PLATFORM_WINDOWS",
		}
	
	filter "configurations:Debug"
		defines "CRRY_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "CRRY_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CRRY_DIST"
		optimize "On"

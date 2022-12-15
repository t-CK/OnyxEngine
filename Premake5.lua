workspace "OnyxEngine"
	architecture "x64"
	startproject "Sandbox"

configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

IncludeDir = {}
IncludeDir["spdlog"] = "OnyxEngine/vendor/spdlog/include"
IncludeDir["glfw"] = "OnyxEngine/vendor/glfw/include"

include "OnyxEngine/vendor/glfw"
--include "OnyxEngine/vendor/glad"
--include "OnyxEngine/vendor/ImGui"

project "OnyxEngine"
	location "OnyxEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "OnyxPch.h"
	pchsource "OnyxEngine/src/OnyxPch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glfw/include"
	}
	
	libdirs
	{
		"$(SolutionDir)OnyxEngine/vendor/lib/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}/GLFW"
	--	"$(SolutionDir)OnyxEngine/vendor/lib/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}/glad",
	--	"$(SolutionDir)OnyxEngine/vendor/lib/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}/ImGui"
	}
	
	links
	{
		"GLFW.lib"
	--	"opengl32.lib",
	--	"Glad.lib",
	--	"ImGui.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ONYX_PLATFORM_WINDOWS",
			"ONYX_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ONYX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ONYX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ONYX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"OnyxEngine/vendor/spdlog/include",
		"OnyxEngine/src"
	}

	links
	{
		"OnyxEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ONYX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ONYX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ONYX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ONYX_DIST"
		optimize "On" 
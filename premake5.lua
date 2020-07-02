workspace "SpiritEngine"
	architecture "x86_64"
	startproject "SpiritEditor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SpiritEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "SpiritEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SpiritEngine/vendor/imgui"
IncludeDir["glm"] = "SpiritEngine/vendor/glm"
IncludeDir["stb_image"] = "SpiritEngine/vendor/stb_image"
IncludeDir["SFML"] = "SpiritEngine/vendor/SFML-2.5.1/include"

group "Dependencies"
	include "SpiritEngine/vendor/GLFW"
	include "SpiritEngine/vendor/Glad"
	include "SpiritEngine/vendor/imgui"
	include "SpiritEngine/vendor/OpenAL-Soft"
	include "SpiritEngine/vendor/libogg"
	include "SpiritEngine/vendor/Vorbis"
	--include "SpiritEngine/vendor/AudioFile"
group ""

project "SpiritEngine"
	location "SpiritEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "SpiritEngine/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
		"AL_LIBTYPE_STATIC"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"SpiritEngine/vendor/OpenAL-Soft/include",
		"SpiritEngine/vendor/OpenAL-Soft/src",
		"SpiritEngine/vendor/OpenAL-Soft/src/common",
		"SpiritEngine/vendor/libogg/include",
		"SpiritEngine/vendor/Vorbis/include",
		"SpiritEngine/vendor/minimp3"--,
		--"SpiritEngine/vendor/AudioFile"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"OpenAL-Soft",
		"Vorbis",
		--"AudioFile"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "SPIRIT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPIRIT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SPIRIT_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SpiritEngine/vendor/spdlog/include",
		"SpiritEngine/src",
		"SpiritEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"SpiritEngine"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "SPIRIT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPIRIT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SPIRIT_DIST"
		runtime "Release"
		optimize "on"

project "SpiritEditor"
	location "SpiritEditor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SpiritEngine/vendor/spdlog/include",
		"SpiritEngine/src",
		"SpiritEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"SpiritEngine"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "SPIRIT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPIRIT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SPIRIT_DIST"
		runtime "Release"
		optimize "on"

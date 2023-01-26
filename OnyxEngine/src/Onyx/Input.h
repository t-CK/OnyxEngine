#pragma once

#include "Core.h"

namespace Onyx
{
	class ONYX_API Input
	{
	public:
		// KBD

		// Returns a state of specific key
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressed_Impl(keycode); }

		// Mouse

		// Is mouse button is pressed
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressed_Impl(button); }
		// Get mouse X position on window
		inline static float GetMouseX() { return s_Instance->GetMouseX_Impl(); }
		// Get mouse Y position on window
		inline static float GetMouseY() { return s_Instance->GetMouseY_Impl(); }
		// Get mouse position as std::pair
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePos_Impl(); }

		inline static Input* Get() { return s_Instance; }

	// Platform specific input functions
	// To be abstracted in platform specific input classes
	protected:
		virtual bool IsKeyPressed_Impl(int keycode) = 0;

		virtual bool IsMouseButtonPressed_Impl(int button) = 0;
		virtual std::pair<float, float> GetMousePos_Impl() = 0;
		virtual float GetMouseX_Impl() = 0;
		virtual float GetMouseY_Impl() = 0;
	private:
		static Input* s_Instance;
	};
}
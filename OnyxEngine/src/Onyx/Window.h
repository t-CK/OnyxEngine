#pragma once

#include "OnyxPch.h"

#include "Onyx/Core.h"
#include "Onyx/Events/Event.h"

namespace Onyx
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Onyx Engine", unsigned int width = 1280, unsigned int height = 720) :
			Title(title), Width(width), Height(height) { }
	};

	// Abstract Window class to be used as base class for all window classes
	class ONYX_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;


		////////////// Window size getters /////////////

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		////////////////////////////////////////////////

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void OnUpdate() = 0;

		///////////////// V-Sync ///////////////////////

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		////////////////////////////////////////////////

		// Returns a native window of graphic api
		virtual void* GetNativeWindow() const = 0;

		// Create an instance of window
		static Window* Create(const WindowProps& props = WindowProps());

		~Window() { }
	};
}
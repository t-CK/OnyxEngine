#pragma once

// Onyx Engine
#include "Onyx/Window.h"
// Vendors
#include <GLFW/glfw3.h>


namespace Onyx
{
	class ONYX_API WindowsWindowGL :
		public Window
	{
	public:
		WindowsWindowGL(const  WindowProps& props);

		void OnUpdate() override;

		////////////////// Window size getters ////////////////////////

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

		///////////////////// V-sync /////////////////////////////////

		void SetVSync(bool enabled) override;
		inline bool IsVSync() const override { return m_Data.VSync; }
		/////////////////////////////////////////////////////////////

		inline void* GetNativeWindow() const override { return (void*)m_Window; }


		virtual ~WindowsWindowGL();

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title; unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
	};
}
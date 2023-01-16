#pragma once

#include "Onyx/Layer.h"
#include "Onyx/Events/Event.h"
#include "Onyx/Events/ApplicationEvent.h"
#include "Onyx/Events/KeyEvent.h"
#include "Onyx/Events/MouseEvent.h"

namespace Onyx
{
	class ONYX_API ImGuiLayer :
		public Layer
	{
	public:
		ImGuiLayer() :
			Layer("ImGuiLayer") { }

		// Overriden from Layer

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;

		~ImGuiLayer();
	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseMoved(MouseMovedEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);

		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnKeyReleased(KeyReleasedEvent& e);
		bool OnKeyTyped(KeyTypedEvent& e);

		bool OnWindowReSized(WindowResizeEvent& e);
		bool OnWindowClosed(WindowCloseEvent& e);
	private:
		float m_Time = 0.f;
	};
}

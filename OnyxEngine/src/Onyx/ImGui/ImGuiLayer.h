#pragma once

#include "Onyx/Layer.h"
#include "Onyx/Events/Event.h"

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
		float m_Time = 0.f;
	};
}

#pragma once

#include "OnyxPch.h"
#include "Events/Event.h"

namespace Onyx
{
	class ONYX_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") :
			m_DebugName(name) { }

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate() { }
		virtual void OnEvent(Event& event) { }

		virtual ~Layer() { }
	protected:
		std::string m_DebugName;
	};
}
#pragma once

#include "Event.h"

namespace Onyx
{
	class ONYX_API MouseMovedEvent :
		public Event
	{
	public:
		MouseMovedEvent(float x, float y) :
			m_MouseX(x), m_MouseY(y) { }

		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent X: " << m_MouseX << "Mouse Y:" << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	class ONYX_API MouseScrolledEvent :
		public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY) :
			m_OffsetX(offsetX), m_OffsetY(offsetY) { }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_OffsetX, m_OffsetY;
	};

	class ONYX_API MouseButtonEvent :
		public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		
	protected:
		MouseButtonEvent(int keycode) :
			m_Button(keycode) { }

		int m_Button;
	};

	class ONYX_API MouseButtonPressedEvent :
		public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class ONYX_API MouseButtonReleasedEvent :
		public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) { }

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
#pragma once

#include "Event.h"

namespace Onyx
{
	class ONYX_API KeyEvent :
		public Event
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode) :
			m_KeyCode(keycode) { }

		int m_KeyCode;
	};

	class ONYX_API KeyPressedEvent :
		public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeateCount) :
			KeyEvent(keycode), m_RepeateCount(repeateCount) { }
		
		inline int GetRepeateCount() { return m_RepeateCount; }

		std::string ToString()
		{
			std::stringstream ss;
			ss << "KeyPressedEvent" << m_KeyCode << "(" << m_RepeateCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeateCount;
	};

	class ONYX_API KeyReleasedEvent :
		public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) :
			KeyEvent(keycode) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class ONYX_API KeyTypedEvent :
		public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) :
			KeyEvent(keycode) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}
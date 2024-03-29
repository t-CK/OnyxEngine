#pragma once

// Onyx engine
#include "Event.h"
// Vendor
#include <spdlog/fmt/ostr.h>

namespace Onyx
{
	class ONYX_API WindowResizeEvent :
		public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_Width(width), m_Height(height) { }

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight()   { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class ONYX_API WindowCloseEvent :
		public Event
	{
	public:
		WindowCloseEvent() { }

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ONYX_API AppUpdateEvent :
		public Event
	{
	public:
		AppUpdateEvent() { }

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ONYX_API AppTickEvent :
		public Event
	{
	public:
		AppTickEvent() { }

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
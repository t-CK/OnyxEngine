#pragma once

#include "Onyx/Core.h"
#include "Onyx/Input.h"

namespace Onyx
{
	class WindowsInput :
		public Input
	{
	protected:
		// KBD

		virtual bool IsKeyPressed_Impl(int keycode) override;

		// Mouse

		virtual bool IsMouseButtonPressed_Impl(int btn) override;
		virtual std::pair<float, float> GetMousePos_Impl() override;
		virtual float GetMouseX_Impl() override;
		virtual float GetMouseY_Impl() override;
	};
}

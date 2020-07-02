#pragma once

namespace SpiritEngine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;
	
	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define SPIRIT_MOUSE_BUTTON_0      ::SpiritEngine::Mouse::Button0
#define SPIRIT_MOUSE_BUTTON_1      ::SpiritEngine::Mouse::Button1
#define SPIRIT_MOUSE_BUTTON_2      ::SpiritEngine::Mouse::Button2
#define SPIRIT_MOUSE_BUTTON_3      ::SpiritEngine::Mouse::Button3
#define SPIRIT_MOUSE_BUTTON_4      ::SpiritEngine::Mouse::Button4
#define SPIRIT_MOUSE_BUTTON_5      ::SpiritEngine::Mouse::Button5
#define SPIRIT_MOUSE_BUTTON_6      ::SpiritEngine::Mouse::Button6
#define SPIRIT_MOUSE_BUTTON_7      ::SpiritEngine::Mouse::Button7
#define SPIRIT_MOUSE_BUTTON_LAST   ::SpiritEngine::Mouse::ButtonLast
#define SPIRIT_MOUSE_BUTTON_LEFT   ::SpiritEngine::Mouse::ButtonLeft
#define SPIRIT_MOUSE_BUTTON_RIGHT  ::SpiritEngine::Mouse::ButtonRight
#define SPIRIT_MOUSE_BUTTON_MIDDLE ::SpiritEngine::Mouse::ButtonMiddle

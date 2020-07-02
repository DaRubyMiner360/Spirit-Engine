#pragma once

namespace SpiritEngine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define SPIRIT_KEY_SPACE           ::SpiritEngine::Key::Space
#define SPIRIT_KEY_APOSTROPHE      ::SpiritEngine::Key::Apostrophe    /* ' */
#define SPIRIT_KEY_COMMA           ::SpiritEngine::Key::Comma         /* , */
#define SPIRIT_KEY_MINUS           ::SpiritEngine::Key::Minus         /* - */
#define SPIRIT_KEY_PERIOD          ::SpiritEngine::Key::Period        /* . */
#define SPIRIT_KEY_SLASH           ::SpiritEngine::Key::Slash         /* / */
#define SPIRIT_KEY_0               ::SpiritEngine::Key::D0
#define SPIRIT_KEY_1               ::SpiritEngine::Key::D1
#define SPIRIT_KEY_2               ::SpiritEngine::Key::D2
#define SPIRIT_KEY_3               ::SpiritEngine::Key::D3
#define SPIRIT_KEY_4               ::SpiritEngine::Key::D4
#define SPIRIT_KEY_5               ::SpiritEngine::Key::D5
#define SPIRIT_KEY_6               ::SpiritEngine::Key::D6
#define SPIRIT_KEY_7               ::SpiritEngine::Key::D7
#define SPIRIT_KEY_8               ::SpiritEngine::Key::D8
#define SPIRIT_KEY_9               ::SpiritEngine::Key::D9
#define SPIRIT_KEY_SEMICOLON       ::SpiritEngine::Key::Semicolon     /* ; */
#define SPIRIT_KEY_EQUAL           ::SpiritEngine::Key::Equal         /* = */
#define SPIRIT_KEY_A               ::SpiritEngine::Key::A
#define SPIRIT_KEY_B               ::SpiritEngine::Key::B
#define SPIRIT_KEY_C               ::SpiritEngine::Key::C
#define SPIRIT_KEY_D               ::SpiritEngine::Key::D
#define SPIRIT_KEY_E               ::SpiritEngine::Key::E
#define SPIRIT_KEY_F               ::SpiritEngine::Key::F
#define SPIRIT_KEY_G               ::SpiritEngine::Key::G
#define SPIRIT_KEY_H               ::SpiritEngine::Key::H
#define SPIRIT_KEY_I               ::SpiritEngine::Key::I
#define SPIRIT_KEY_J               ::SpiritEngine::Key::J
#define SPIRIT_KEY_K               ::SpiritEngine::Key::K
#define SPIRIT_KEY_L               ::SpiritEngine::Key::L
#define SPIRIT_KEY_M               ::SpiritEngine::Key::M
#define SPIRIT_KEY_N               ::SpiritEngine::Key::N
#define SPIRIT_KEY_O               ::SpiritEngine::Key::O
#define SPIRIT_KEY_P               ::SpiritEngine::Key::P
#define SPIRIT_KEY_Q               ::SpiritEngine::Key::Q
#define SPIRIT_KEY_R               ::SpiritEngine::Key::R
#define SPIRIT_KEY_S               ::SpiritEngine::Key::S
#define SPIRIT_KEY_T               ::SpiritEngine::Key::T
#define SPIRIT_KEY_U               ::SpiritEngine::Key::U
#define SPIRIT_KEY_V               ::SpiritEngine::Key::V
#define SPIRIT_KEY_W               ::SpiritEngine::Key::W
#define SPIRIT_KEY_X               ::SpiritEngine::Key::X
#define SPIRIT_KEY_Y               ::SpiritEngine::Key::Y
#define SPIRIT_KEY_Z               ::SpiritEngine::Key::Z
#define SPIRIT_KEY_LEFT_BRACKET    ::SpiritEngine::Key::LeftBracket   /* [ */
#define SPIRIT_KEY_BACKSLASH       ::SpiritEngine::Key::Backslash     /* \ */
#define SPIRIT_KEY_RIGHT_BRACKET   ::SpiritEngine::Key::RightBracket  /* ] */
#define SPIRIT_KEY_GRAVE_ACCENT    ::SpiritEngine::Key::GraveAccent   /* ` */
#define SPIRIT_KEY_WORLD_1         ::SpiritEngine::Key::World1        /* non-US #1 */
#define SPIRIT_KEY_WORLD_2         ::SpiritEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define SPIRIT_KEY_ESCAPE          ::SpiritEngine::Key::Escape
#define SPIRIT_KEY_ENTER           ::SpiritEngine::Key::Enter
#define SPIRIT_KEY_TAB             ::SpiritEngine::Key::Tab
#define SPIRIT_KEY_BACKSPACE       ::SpiritEngine::Key::Backspace
#define SPIRIT_KEY_INSERT          ::SpiritEngine::Key::Insert
#define SPIRIT_KEY_DELETE          ::SpiritEngine::Key::Delete
#define SPIRIT_KEY_RIGHT           ::SpiritEngine::Key::Right
#define SPIRIT_KEY_LEFT            ::SpiritEngine::Key::Left
#define SPIRIT_KEY_DOWN            ::SpiritEngine::Key::Down
#define SPIRIT_KEY_UP              ::SpiritEngine::Key::Up
#define SPIRIT_KEY_PAGE_UP         ::SpiritEngine::Key::PageUp
#define SPIRIT_KEY_PAGE_DOWN       ::SpiritEngine::Key::PageDown
#define SPIRIT_KEY_HOME            ::SpiritEngine::Key::Home
#define SPIRIT_KEY_END             ::SpiritEngine::Key::End
#define SPIRIT_KEY_CAPS_LOCK       ::SpiritEngine::Key::CapsLock
#define SPIRIT_KEY_SCROLL_LOCK     ::SpiritEngine::Key::ScrollLock
#define SPIRIT_KEY_NUM_LOCK        ::SpiritEngine::Key::NumLock
#define SPIRIT_KEY_PRINT_SCREEN    ::SpiritEngine::Key::PrintScreen
#define SPIRIT_KEY_PAUSE           ::SpiritEngine::Key::Pause
#define SPIRIT_KEY_F1              ::SpiritEngine::Key::F1
#define SPIRIT_KEY_F2              ::SpiritEngine::Key::F2
#define SPIRIT_KEY_F3              ::SpiritEngine::Key::F3
#define SPIRIT_KEY_F4              ::SpiritEngine::Key::F4
#define SPIRIT_KEY_F5              ::SpiritEngine::Key::F5
#define SPIRIT_KEY_F6              ::SpiritEngine::Key::F6
#define SPIRIT_KEY_F7              ::SpiritEngine::Key::F7
#define SPIRIT_KEY_F8              ::SpiritEngine::Key::F8
#define SPIRIT_KEY_F9              ::SpiritEngine::Key::F9
#define SPIRIT_KEY_F10             ::SpiritEngine::Key::F10
#define SPIRIT_KEY_F11             ::SpiritEngine::Key::F11
#define SPIRIT_KEY_F12             ::SpiritEngine::Key::F12
#define SPIRIT_KEY_F13             ::SpiritEngine::Key::F13
#define SPIRIT_KEY_F14             ::SpiritEngine::Key::F14
#define SPIRIT_KEY_F15             ::SpiritEngine::Key::F15
#define SPIRIT_KEY_F16             ::SpiritEngine::Key::F16
#define SPIRIT_KEY_F17             ::SpiritEngine::Key::F17
#define SPIRIT_KEY_F18             ::SpiritEngine::Key::F18
#define SPIRIT_KEY_F19             ::SpiritEngine::Key::F19
#define SPIRIT_KEY_F20             ::SpiritEngine::Key::F20
#define SPIRIT_KEY_F21             ::SpiritEngine::Key::F21
#define SPIRIT_KEY_F22             ::SpiritEngine::Key::F22
#define SPIRIT_KEY_F23             ::SpiritEngine::Key::F23
#define SPIRIT_KEY_F24             ::SpiritEngine::Key::F24
#define SPIRIT_KEY_F25             ::SpiritEngine::Key::F25

/* Keypad */
#define SPIRIT_KEY_KP_0            ::SpiritEngine::Key::KP0
#define SPIRIT_KEY_KP_1            ::SpiritEngine::Key::KP1
#define SPIRIT_KEY_KP_2            ::SpiritEngine::Key::KP2
#define SPIRIT_KEY_KP_3            ::SpiritEngine::Key::KP3
#define SPIRIT_KEY_KP_4            ::SpiritEngine::Key::KP4
#define SPIRIT_KEY_KP_5            ::SpiritEngine::Key::KP5
#define SPIRIT_KEY_KP_6            ::SpiritEngine::Key::KP6
#define SPIRIT_KEY_KP_7            ::SpiritEngine::Key::KP7
#define SPIRIT_KEY_KP_8            ::SpiritEngine::Key::KP8
#define SPIRIT_KEY_KP_9            ::SpiritEngine::Key::KP9
#define SPIRIT_KEY_KP_DECIMAL      ::SpiritEngine::Key::KPDecimal
#define SPIRIT_KEY_KP_DIVIDE       ::SpiritEngine::Key::KPDivide
#define SPIRIT_KEY_KP_MULTIPLY     ::SpiritEngine::Key::KPMultiply
#define SPIRIT_KEY_KP_SUBTRACT     ::SpiritEngine::Key::KPSubtract
#define SPIRIT_KEY_KP_ADD          ::SpiritEngine::Key::KPAdd
#define SPIRIT_KEY_KP_ENTER        ::SpiritEngine::Key::KPEnter
#define SPIRIT_KEY_KP_EQUAL        ::SpiritEngine::Key::KPEqual

#define SPIRIT_KEY_LEFT_SHIFT      ::SpiritEngine::Key::LeftShift
#define SPIRIT_KEY_LEFT_CONTROL    ::SpiritEngine::Key::LeftControl
#define SPIRIT_KEY_LEFT_ALT        ::SpiritEngine::Key::LeftAlt
#define SPIRIT_KEY_LEFT_SUPER      ::SpiritEngine::Key::LeftSuper
#define SPIRIT_KEY_RIGHT_SHIFT     ::SpiritEngine::Key::RightShift
#define SPIRIT_KEY_RIGHT_CONTROL   ::SpiritEngine::Key::RightControl
#define SPIRIT_KEY_RIGHT_ALT       ::SpiritEngine::Key::RightAlt
#define SPIRIT_KEY_RIGHT_SUPER     ::SpiritEngine::Key::RightSuper
#define SPIRIT_KEY_MENU            ::SpiritEngine::Key::Menu

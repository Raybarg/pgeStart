#pragma once

#ifndef IM_GUI_DEF
#define IM_GUI_DEF

#include "olcPixelGameEngine.h"

namespace imgui
{
	class ImmediateModeGUI;

	struct strMyUIState {
		int mouseX;
		int mouseY;
		bool mouseDown;
		int hotItem;
		int activeItem;

		int kbditem;
		int keyentered;
		int keymod;

		int lastWidget;
	};

	class ImmediateModeGUI
	{
	public:
		ImmediateModeGUI(olc::PixelGameEngine* _pge);
		virtual ~ImmediateModeGUI();

	public:
		strMyUIState state;

	public:
		void Prepare();
		void Finish();

		bool Button(int id, int x, int y, std::string sText);
		int Slider(int id, int x, int y, int max, int& value);
		int textfield(int id, int x, int y, std::string& sText);

	private:
		olc::PixelGameEngine* pge = nullptr;

		int RegionHit(int x, int y, int w, int h);
		void DisableTextEntry();
	};

}

#define GEN_ID (__LINE__)
#endif // IM_GUI_DEF


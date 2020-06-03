#include "imGUI.h"

namespace imgui
{
	ImmediateModeGUI::ImmediateModeGUI(olc::PixelGameEngine* _pge)
	{
		pge = _pge;
		state.mouseDown = false;
		state.activeItem = 0;
		state.hotItem = 0;
	}
	ImmediateModeGUI::~ImmediateModeGUI() { }

	/// <summary>
	/// Draw immediate mode UI button and return button pressed state
	/// </summary>
	/// <param name="id">Unique identifier for button</param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="sText">Button text</param>
	/// <returns>Button pressed True/False</returns>
	bool ImmediateModeGUI::Button(int id, int x, int y, std::string sText) {
		olc::vi2d pos = { x, y };
		olc::vi2d size = { 64, 48 };

		int length = sText.length();
		olc::vi2d txtPos = { x + size.x / 2 - length * 4, y + size.y / 2 - 4 };

		pge->FillRect(pos + olc::vi2d{ 5, 5 }, size, olc::DARK_GREY); // Shadow

		if (RegionHit(x, y, size.x, size.y))
		{
			state.hotItem = id;
			if (state.activeItem == 0 && state.mouseDown)
			{
				state.activeItem = id;
			}
		}

		if (state.hotItem == id)
		{
			if (state.activeItem == id)
			{
				// Its hot and active
				pge->FillRect(pos + olc::vi2d{ 2, 2 }, size, olc::WHITE);
				pge->DrawString(txtPos + olc::vi2d{ 2, 2 }, sText, olc::BLACK);
			}
			else
			{
				// Just hot
				pge->FillRect(pos, size, olc::WHITE);
				pge->DrawString(txtPos, sText, olc::BLACK);
			}
		}
		else
		{
			// Not hot
			pge->FillRect(pos, size, olc::GREY);
			pge->DrawString(txtPos, sText, olc::BLACK);
		}

		if (!state.mouseDown && state.hotItem == id && state.activeItem == id)
		{
			// Released mouse button on top of hot button -> button has been "pressed" properly
			return true;
		}

		return false;
	}

	/// <summary>
	/// Prepare imGUI. Must be called each frame before calling imGUI conditions.
	/// </summary>
	void ImmediateModeGUI::Prepare()
	{
		state.hotItem = 0;
	}

	/// <summary>
	/// Finish imGUI. Must be called each frame after all imGUI conditions have been called.
	/// </summary>
	void ImmediateModeGUI::Finish()
	{
		if (!state.mouseDown)
		{
			state.activeItem = 0;
		}
		else
		{
			if (state.activeItem == 0)
			{
				state.activeItem = -1;
			}
		}
	}

	/// <summary>
	/// Check if state mouse coordinates are inside given region
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="w"></param>
	/// <param name="h"></param>
	/// <returns>Mouse coordinates are inside given region true/false</returns>
	int ImmediateModeGUI::RegionHit(int x, int y, int w, int h)
	{
		if (state.mouseX < x || state.mouseY < y || state.mouseX >= x + w || state.mouseY > y + h)
		{
			return 0;
		}
		return 1;
	}
}
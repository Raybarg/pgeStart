#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "imgui.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "imGUI Example";
	}

public:
	imgui::ImmediateModeGUI* UI;
	olc::Pixel testColor = olc::WHITE;
	std::string testText = "Its white!";

public:
	bool OnUserCreate() override
	{
		UI = new imgui::ImmediateModeGUI(this);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Updarte imgui states
		UI->state.mouseX = GetMouseX();
		UI->state.mouseY = GetMouseY();
		UI->state.mouseDown = GetMouse(0).bHeld;

		Clear(olc::VERY_DARK_BLUE);

		DrawRect(olc::vi2d{10,10}, olc::vi2d{ 200,20 }, testColor);
		DrawString(olc::vi2d{ 18,16 }, testText, testColor);

		UI->Prepare();
		if (UI->Button(1, 50, 100, "Red"))
		{
			testColor = olc::RED;
			testText = "It's red!";
		}
		if (UI->Button(2, 150, 100, "White"))
		{
			testColor = olc::WHITE;
			testText = "It's white!";
		}
		UI->Finish();

		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}


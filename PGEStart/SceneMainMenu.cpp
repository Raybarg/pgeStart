#pragma once
#include "scenes.h"

namespace GameScenes
{
	void Scenes::DrawMainMenuScene()
	{
		static olc::Pixel testColor = olc::WHITE;
		static std::string testText = "Its white!";

		static int slidertest = 0;
		static std::string sometext1 = "Some text 1";
		static std::string sometext2 = "Some text 2";

		// Update imgui states
		UI->state.mouseX = pge->GetMouseX();
		UI->state.mouseY = pge->GetMouseY();
		UI->state.mouseDown = pge->GetMouse(0).bHeld;

		pge->Clear(olc::VERY_DARK_BLUE);

		pge->DrawRect(olc::vi2d{ 10,10 }, olc::vi2d{ 200,20 }, testColor);
		pge->DrawString(olc::vi2d{ 18,16 }, testText, testColor);

		UI->Prepare();
		if (UI->Button(GEN_ID, 50, 100, "Red"))
		{
			testColor = olc::RED;
			testText = "It's red!";
		}
		if (UI->Button(GEN_ID, 150, 100, "White"))
		{
			testColor = olc::WHITE;
			testText = "It's white!";

		}

		if (UI->Button(GEN_ID, 500, 50, "Effect1"))
		{
			state->State = GameState::States::Effect1;
		}
		if (UI->Button(GEN_ID, 500, 100, "Starfield"))
		{
			state->State = GameState::States::Starfield;
		}
		if (UI->Button(GEN_ID, 500, 150, "Intro"))
		{
			state->State = GameState::States::Intro;
		}
		if (UI->Button(GEN_ID, 500, 200, "Quit"))
		{
			pge->olc_Terminate();
		}

		UI->Slider(GEN_ID, 5, 40, 90, slidertest);

		UI->textfield(GEN_ID, 40, 40, sometext1);
		UI->textfield(GEN_ID, 40, 70, sometext2);



		pge->DrawString(olc::vi2d{ 180,16 }, std::to_string(slidertest), testColor);

		UI->Finish();
	}

	void Scenes::UpdateMainMenuScene(float elapsedTime)
	{

	}
}
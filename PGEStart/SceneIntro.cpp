#pragma once
#include "scenes.h"

namespace GameScenes
{
	void Scenes::DrawIntroScene()
	{
		pge->Clear(olc::VERY_DARK_BLUE);
		pge->DrawString(olc::vi2d(1, 1), "IntroScene");
		UI->Prepare();
		UI->Finish();
	}

	void Scenes::UpdateIntroScene(float elapsedTime)
	{
		if (pge->GetKey(olc::Key::ESCAPE).bPressed || pge->GetKey(olc::Key::SPACE).bPressed) 
		{
			state->State = GameState::States::MainMenu;
		}
	}
}

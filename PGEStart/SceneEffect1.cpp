#pragma once
#include "scenes.h"

namespace GameScenes
{
	olc::Sprite* sprImg = nullptr;
	olc::Sprite* sprScr = nullptr;
	olc::Decal* decScr = nullptr;
	
	void Scenes::DrawEffect1Scene()
	{
	}

	void Scenes::UpdateEffectScene(float elapsedTime)
	{
		static float sineff;
		LoadEffect1Assets();
		sineff += elapsedTime;
		if (sprImg)
		{
			pge->Clear(olc::VERY_DARK_BLUE);
			pge->DrawString(olc::vi2d(1, 1), "Effect 1 Scene");

			for (int x = 0; x < pge->ScreenWidth(); x++)
			{
				for (int y = 0; y < pge->ScreenHeight(); y++)
				{
					sprScr->SetPixel(x, y, sprImg->GetPixel(
						((float)sprImg->width / (float)pge->ScreenWidth()) * x + sin((y/20.0f) + sineff*5.0f),
						((float)sprImg->height / (float)pge->ScreenHeight()) * y + cos((x/20.f) + sineff*5.0f))
					);
				}
			}
			decScr->Update();
			pge->DrawDecal(olc::vi2d{ 1,1 }, decScr);

			UI->Prepare();
			UI->Finish();
		}
		
		if (pge->GetKey(olc::Key::ESCAPE).bPressed || pge->GetKey(olc::Key::SPACE).bPressed)
		{
			state->State = GameState::States::MainMenu;
		}
	}

	void Scenes::LoadEffect1Assets()
	{
		if (!sprImg)
		{
			sprImg = new olc::Sprite("Images/raybarg256.png");
		}
		if (!sprScr)
		{
			sprScr = new olc::Sprite(pge->ScreenWidth(), pge->ScreenHeight());
			decScr = new olc::Decal(sprScr);
		}
	}
}

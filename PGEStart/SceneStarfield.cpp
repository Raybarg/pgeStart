#pragma once
#include "scenes.h"

namespace GameScenes
{
	struct sBall
	{
		olc::vf2d pos;
		olc::vf2d vel;
		olc::Pixel col;
		float radius;
	};

	std::vector<sBall> vBalls;

	void Scenes::DrawStarfieldScene()
	{
		pge->Clear(olc::VERY_DARK_BLUE);
		pge->DrawString(olc::vi2d(1, 1), "StarfieldScene");
		UI->Prepare();
		UI->Finish();
	}

	void Scenes::UpdateStarfieldScene(float elapsedTime)
	{
		if (pge->GetKey(olc::Key::ESCAPE).bPressed || pge->GetKey(olc::Key::SPACE).bPressed)
		{
			state->State = GameState::States::MainMenu;
		}
		if (pge->GetMouse(0).bPressed) AddBall();
		UpdateAndDrawBalls(elapsedTime);
	}

	void Scenes::AddBall()
	{
		float fAngle = float(rand()) / float(RAND_MAX) * 2.0f * 3.14159f - 0.3f;
		float fSpeed = float(rand()) / float(RAND_MAX) * 100.0f + 20.0f;
		float fRadius = fSpeed / 22.0f;

		vBalls.push_back(
			{
				olc::vf2d(float(pge->ScreenWidth()) / 2.0f, float(pge->ScreenHeight()) / 2.0f),
				olc::vf2d(fSpeed * cos(fAngle), fSpeed * sin(fAngle)),
				olc::Pixel(rand() % 128 + 128, rand() % 128 + 128, rand() % 128 + 128),
				fRadius
			}
		);
	}

	void Scenes::RemoveBall()
	{
		if (vBalls.empty())
			return;
		vBalls.pop_back();
	}

	void Scenes::UpdateAndDrawBalls(const float fElapsedTime)
	{
		for (auto& ball : vBalls)
		{
			ball.pos += ball.vel * fElapsedTime;

			if (ball.pos.x < ball.radius || ball.pos.x > (pge->ScreenWidth() - ball.radius))
			{
				//ball.pos.x = std::clamp(ball.pos.x, ball.radius, (pge->ScreenWidth() - ball.radius));
				ball.pos.x = float(pge->ScreenWidth()) / 2.0f;
				ball.pos.y = float(pge->ScreenHeight()) / 2.0f;
				//ball.vel.x *= -1.0f;
			}

			if (ball.pos.y <= ball.radius || ball.pos.y >= (pge->ScreenHeight() - ball.radius))
			{
				//ball.pos.y = std::clamp(ball.pos.y, ball.radius, (pge->ScreenHeight() - ball.radius));
				ball.pos.x = float(pge->ScreenWidth()) / 2.0f;
				ball.pos.y = float(pge->ScreenHeight()) / 2.0f;
				//ball.vel.y *= -1.0f;
			}
		}

		for (const auto& ball : vBalls)
		{
			pge->FillCircle(ball.pos, int32_t(ball.radius), ball.col);
		}
	}
}

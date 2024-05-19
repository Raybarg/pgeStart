#pragma once
#include "olcPixelGameEngine.h"
#include "GameStates.h"
#include "imgui.h"

namespace GameScenes
{
	class Scenes
	{
	private:
		olc::PixelGameEngine* pge = nullptr;
		imgui::ImmediateModeGUI* UI = nullptr;
		GameState::GameStates* state = nullptr;

	public:
		Scenes(olc::PixelGameEngine* _pge, imgui::ImmediateModeGUI* _ui, GameState::GameStates* _state)
		{
			pge = _pge;
			UI = _ui;
			state = _state;
		};
		~Scenes() {};

		void DrawIntroScene();
		void UpdateIntroScene(float elapsedTime);

		void DrawMainMenuScene();
		void UpdateMainMenuScene(float elapsedTime);

		void DrawStarfieldScene();
		void UpdateStarfieldScene(float elapsedTime);
		void AddBall();
		void RemoveBall();
		void UpdateAndDrawBalls(const float fElapsedTime);

		void DrawEffect1Scene();
		void UpdateEffectScene(float elapsedTime);
		void LoadEffect1Assets();

		void DrawStateScene()
		{
			switch (state->State)
			{
			case GameState::States::Intro:
				DrawIntroScene();
				break;
			case GameState::States::MainMenu:
				DrawMainMenuScene();
				break;
			case GameState::States::Starfield:
				DrawStarfieldScene();
				break;
			case GameState::States::Effect1:
				DrawEffect1Scene();
				break;
			default:
				break;
			}
		}

		void UpdateStateScene(float elapsedTime)
		{
			switch (state->State)
			{
			case GameState::States::Intro:
				UpdateIntroScene(elapsedTime);
				break;
			case GameState::States::MainMenu:
				UpdateMainMenuScene(elapsedTime);
				break;
			case GameState::States::Starfield:
				UpdateStarfieldScene(elapsedTime);
				break;
			case GameState::States::Effect1:
				UpdateEffectScene(elapsedTime);
				break;
			default:
				break;
			}
		}

	};
}

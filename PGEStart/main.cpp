#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "GameStates.h"
#include "Scenes.h"

class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "imGUI Example";
	}

public:
	imgui::ImmediateModeGUI* UI;

	GameState::GameStates* gameState;
	GameScenes::Scenes* scenes;
	

public:
	bool OnUserCreate() override
	{
		UI = new imgui::ImmediateModeGUI(this);
		gameState = new GameState::GameStates(GameState::States::Intro);
		scenes = new GameScenes::Scenes(this, UI, gameState);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		scenes->DrawStateScene();
		scenes->UpdateStateScene(fElapsedTime);
		return true;
	}
};

int main()
{
	Game game;
	if (game.Construct(800, 600, 1, 1))
		game.Start();
	return 0;
}


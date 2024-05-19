#pragma once

namespace GameState
{
	enum States
	{
		Intro = 0,
		MainMenu = 1,
		Starfield = 2,
		Effect1 = 3,
	};

	class GameStates
	{
	public:
		States State;

		GameStates() 
		{
			State = States::Intro;
		};
		GameStates(States state)
		{
			State = state;
		};
		~GameStates() {};
	};
}

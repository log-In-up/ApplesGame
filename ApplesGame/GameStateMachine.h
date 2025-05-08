#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

namespace ApplesGame
{
	class GameStateMachine
	{
	private:
		GameState* currentGameState;
	public:
		GameStateMachine(GameState* gameStartingState) : currentGameState(nullptr)
		{
			this->SwitchCurrentStateTo(gameStartingState);
		}

		~GameStateMachine()
		{
			delete currentGameState;
		}

		void DrawGame(sf::RenderWindow& window);
		void HandleWindowEvents(sf::RenderWindow& window, sf::Event& event);
		void Initialization();
		void SwitchCurrentStateTo(GameState* newGameState);
		void Update(float deltaTime, sf::RenderWindow& window);
	};
}
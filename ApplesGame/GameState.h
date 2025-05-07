#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

namespace ApplesGame
{
	class GameStateMachine;

	class GameState
	{
	public:
		GameState() = default;
		GameState(GameData& gameData);

		virtual ~GameState();

		virtual void DrawGame(sf::RenderWindow& window) = 0;
		virtual void Initialization() = 0;
		virtual void Update(float deltaTime, sf::RenderWindow& window) = 0;
		void SetGameStateMachine(GameStateMachine* gameStateMachine);

	protected:
		GameStateMachine* gameStateMachine;
		GameData& gameData;
	};
}
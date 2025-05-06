#pragma once
#include "GameState.h"

namespace ApplesGame
{
	class MainMenuState : public GameState
	{
	public:
		MainMenuState(GameData& gameData);
		void DrawGame(sf::RenderWindow& window) override;
		void Initialization() override;
		void Update(float deltaTime, sf::RenderWindow& window) override;
	};
}
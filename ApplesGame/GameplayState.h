#pragma once
#include "GameState.h"

namespace ApplesGame
{
	class GameplayState : public GameState
	{
	public:
		GameplayState(GameData& gameData);
		~GameplayState();
		void DrawGame(sf::RenderWindow& window) override;
		void Initialization() override;
		void Update(float deltaTime, sf::RenderWindow& window) override;
	private:
		void RestartGame();
		void UpdateGameOverState(float deltaTime);
		void UpdateOnPlayState(float deltaTime);
	};
}
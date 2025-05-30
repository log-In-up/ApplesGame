#pragma once
#include <unordered_map>

#include "GameState.h"

namespace ApplesGame
{
	class GameplayState : public GameState
	{
	public:
		GameplayState(GameData& gameData);
		~GameplayState();
		void DrawGame(sf::RenderWindow& window) override;
		void HandleWindowEvents(sf::RenderWindow& window, sf::Event& event) override;
		void Initialization() override;
		void Update(float deltaTime, sf::RenderWindow& window) override;
	private:
		void RestartGame();
		void UpdateOnPlayState(float deltaTime);
	};
}
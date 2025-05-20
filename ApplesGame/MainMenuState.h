#pragma once
#include "GameState.h"

namespace ApplesGame
{
	class MainMenuState : public GameState
	{
	private:
		std::string GetDifficultyName();
	public:
		MainMenuState(GameData& gameData);
		~MainMenuState();
		void DrawGame(sf::RenderWindow& window) override;
		void HandleWindowEvents(sf::RenderWindow& window, sf::Event& event) override;
		void Initialization() override;
		void Update(float deltaTime, sf::RenderWindow& window) override;
	};
}
#pragma once
#include "GameState.h"

namespace ApplesGame
{
	class LeaderBoardState : public GameState
	{
	public:
		LeaderBoardState(GameData& gameData);
		~LeaderBoardState();
		void DrawGame(sf::RenderWindow& window) override;
		void HandleWindowEvents(sf::RenderWindow& window, sf::Event& event) override;
		void Initialization() override;
		void Update(float deltaTime, sf::RenderWindow& window) override;
	};
}
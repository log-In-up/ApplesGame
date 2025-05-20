#pragma once
#include <map>

#include "Game.h"
#include "SFML/Graphics.hpp"

namespace ApplesGame
{
	const unsigned int SCORE_SIZE = 24,
		INPUT_HINT_SIZE = 24,
		RESTART_GAME_SIZE = 24,
		GAME_OVER_SIZE = 48;

	class GameplayUserInterface
	{
	private:
		GameData& gameData;
		std::map<std::string, int>& recordsTable;
	public:
		GameplayUserInterface(GameData& gameData);
		~GameplayUserInterface();
		void DrawUI(sf::RenderWindow& window);
		void InitUI(const sf::Font& font);
		void UpdateUI(float deltaTime);
	private:
		void DrawTextOnGameOver(sf::RenderWindow& window);
	};
}
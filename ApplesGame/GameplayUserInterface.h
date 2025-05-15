#pragma once
#include <map>

#include "SFML/Graphics.hpp"
#include "Game.h"

namespace ApplesGame
{
	const unsigned int SCORE_SIZE = 24,
		INPUT_HINT_SIZE = 24,
		RESTART_GAME_SIZE = 24,
		GAME_OVER_SIZE = 48,
		LEADERBOARD_SIZE = 20;

	class GameplayUserInterface
	{
	public:
		GameplayUserInterface(std::map<std::string, int>& recordsTable);
		~GameplayUserInterface();
		void DrawUI(sf::RenderWindow& window);
		void InitUI(const sf::Font& font);
		void UpdateUI(GameData& gameData, float deltaTime);
	private:
		void DrawLeaderboard(sf::RenderWindow& window);
		void DrawTextOnGameOver(sf::RenderWindow& window);
		void SetTextData(sf::Text& text, const sf::Font& font, unsigned int size, const sf::Color color);
		std::map<std::string, int>& recordsTable;
	};
}
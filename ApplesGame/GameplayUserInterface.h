#pragma once
#include <map>

#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Text.h"

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
		void HandleWindowEvents(sf::RenderWindow& window, sf::Event& event);
		void InitUI(const sf::Font& font, const MenuItem& item);
		void UpdateUI(float deltaTime);
	private:
		void DrawTextOnGameOver(sf::RenderWindow& window);
	};
}
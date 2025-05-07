#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"

namespace ApplesGame
{
	class MainMenuUI
	{
	public:
		void DrawUI(sf::RenderWindow& window);
		void InitUI(const sf::Font& font);
		void UpdateUI(GameData& gameData, float deltaTime);
	private:
		void SetTextData(sf::Text& text, const sf::Font& font, unsigned int size, sf::Vector2f position);
		void UpdateDifficultyColor(GameData& gameData, sf::Text& text, GameDifficulty gameDifficulty);
		void UpdateOptionData(GameData& gameData, sf::Text& text, GameOptions gameOption, std::string startPartOfString);
	};
}
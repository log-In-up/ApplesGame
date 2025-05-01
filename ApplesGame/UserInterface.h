#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"

namespace ApplesGame
{
	class UserInterface
	{
	public:
		UserInterface();
		void DrawUI(sf::RenderWindow& window);
		void InitUI(const sf::Font& font);
		void UpdateUI(GameData& gameData, float deltaTime);
	};
}
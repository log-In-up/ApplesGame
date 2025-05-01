#pragma once
#include "AppleFactory.h"
#include "Game.h"

namespace ApplesGame
{
	class AppleDrawer
	{
	public:
		void DrawApples(const GameData& gameData, sf::RenderWindow& window);
	};
}
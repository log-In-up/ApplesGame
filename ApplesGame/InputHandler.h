#pragma once
#include "Game.h"

namespace ApplesGame
{
	class InputHandler
	{
	public:
		void ReadInputForPlayer(Player& player, sf::Event& event);
	};
}
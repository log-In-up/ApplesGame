#include "InputHandler.h"
#include "Player.h"

namespace ApplesGame
{
	void InputHandler::ReadInputForPlayer(Player& player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.SetMovementDirection(PlayerDirection::Up);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.SetMovementDirection(PlayerDirection::Right);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.SetMovementDirection(PlayerDirection::Down);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.SetMovementDirection(PlayerDirection::Left);
		}
	}
}
#include "InputHandler.h"
#include "Player.h"

namespace ApplesGame
{
	void InputHandler::ReadInputForPlayer(Player& player, sf::Event& event)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			player.SetMovementDirection(PlayerDirection::Up);
			break;
		case sf::Keyboard::Right:
			player.SetMovementDirection(PlayerDirection::Right);
			break;
		case sf::Keyboard::Down:
			player.SetMovementDirection(PlayerDirection::Down);
			break;
		case sf::Keyboard::Left:
			player.SetMovementDirection(PlayerDirection::Left);
			break;
		default:
			break;
		}
	}
}
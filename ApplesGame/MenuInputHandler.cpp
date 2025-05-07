#include "MenuInputHandler.h"
#include <SFML/Window/Keyboard.hpp>

namespace ApplesGame
{
	MenuInputHandler::MenuInputHandler(GameData& gameData) : gameData(gameData)
	{
	}

	void MenuInputHandler::Update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Easy);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Medium);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Hard);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			gameData.gameModeBitMask ^= static_cast<uint32_t>(GameOptions::InfiniteApples);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			gameData.gameModeBitMask ^= static_cast<uint32_t>(GameOptions::WithAcceleration);
		}
	}
}
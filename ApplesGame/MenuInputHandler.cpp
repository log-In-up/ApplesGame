#include "MenuInputHandler.h"
#include <SFML/Window/Keyboard.hpp>

namespace ApplesGame
{
	MenuInputHandler::MenuInputHandler(GameData& gameData) : gameData(gameData)
	{
	}

	void MenuInputHandler::Update(sf::RenderWindow& window, sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Num1:
				gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Easy);
				break;
			case sf::Keyboard::Num2:
				gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Medium);
				break;
			case sf::Keyboard::Num3:
				gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Hard);
				break;
			case sf::Keyboard::Num4:
				gameData.gameModeBitMask ^= static_cast<uint32_t>(GameOptions::InfiniteApples);
				break;
			case sf::Keyboard::Num5:
				gameData.gameModeBitMask ^= static_cast<uint32_t>(GameOptions::WithAcceleration);
				break;
			default:
				break;
			}
		}
	}
}
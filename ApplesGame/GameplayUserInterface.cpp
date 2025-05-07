#include "GameplayUserInterface.h"
#include "Mathematics.h"
#include "Game.h"

namespace ApplesGame
{
	bool isGameOverTextVisible;

	sf::Text scoreText;
	sf::Text inputHintText;
	sf::Text gameOverText;

	GameplayUserInterface::GameplayUserInterface()
	{
		isGameOverTextVisible = false;
	}

	void GameplayUserInterface::DrawUI(sf::RenderWindow& window)
	{
		scoreText.setPosition(10.f, 10.f);
		window.draw(scoreText);

		inputHintText.setPosition(window.getSize().x - 10.f, 10.f);
		window.draw(inputHintText);

		if (isGameOverTextVisible)
		{
			gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
			window.draw(gameOverText);
		}
	}

	void GameplayUserInterface::InitUI(const sf::Font& font)
	{
		scoreText.setFont(font);
		scoreText.setCharacterSize(24);
		scoreText.setFillColor(sf::Color::Yellow);

		inputHintText.setFont(font);
		inputHintText.setCharacterSize(24);
		inputHintText.setFillColor(sf::Color::White);
		inputHintText.setString("Use arrow keys to move.");
		inputHintText.setOrigin(GetTextOrigin(inputHintText, { 1.f, 0.f }));

		isGameOverTextVisible = false;
		gameOverText.setFont(font);
		gameOverText.setCharacterSize(48);
		gameOverText.setStyle(sf::Text::Bold);
		gameOverText.setFillColor(sf::Color::Red);
		gameOverText.setString("GAME OVER");
		gameOverText.setOrigin(GetTextOrigin(gameOverText, { 0.5f, 0.5f }));
	}

	void GameplayUserInterface::UpdateUI(GameData& gameData, float deltaTime)
	{
		scoreText.setString("Points: " + std::to_string(gameData.numOfPoints));

		isGameOverTextVisible = gameData.isGameOver;
	}
}
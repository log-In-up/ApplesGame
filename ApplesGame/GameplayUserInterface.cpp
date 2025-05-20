#include "Game.h"
#include "GameMain.h"
#include "GameplayUserInterface.h"
#include "LeaderboardDrawer.h"
#include "Mathematics.h"
#include "Text.h"

namespace ApplesGame
{
	bool isGameOverTextVisible;

	sf::Text scoreText;
	sf::Text inputHintText;
	sf::Text restartGameHintText;
	sf::Text gameOverText;

	LeaderboardDrawer* leaderboardUIDrawer;

	GameplayUserInterface::GameplayUserInterface(GameData& gameData) : recordsTable(gameData.recordsTable), gameData(gameData)
	{
		isGameOverTextVisible = false;

		leaderboardUIDrawer = new LeaderboardDrawer(this->recordsTable);
	}

	GameplayUserInterface::~GameplayUserInterface()
	{
		delete leaderboardUIDrawer;
	}

	void GameplayUserInterface::DrawUI(sf::RenderWindow& window)
	{
		scoreText.setPosition(10.f, 10.f);
		window.draw(scoreText);

		inputHintText.setPosition(window.getSize().x - 10.f, 10.f);
		window.draw(inputHintText);

		if (isGameOverTextVisible)
		{
			DrawTextOnGameOver(window);
		}
	}

	void GameplayUserInterface::InitUI(const sf::Font& font)
	{
		isGameOverTextVisible = false;

		SetTextData(scoreText, font, SCORE_SIZE, sf::Color::Yellow);

		SetTextData(inputHintText, font, INPUT_HINT_SIZE, sf::Color::White);
		inputHintText.setString("Use arrow keys to move.");
		inputHintText.setOrigin(GetTextOrigin(inputHintText, { 1.f, 0.f }));

		SetTextData(restartGameHintText, font, RESTART_GAME_SIZE, sf::Color::White);
		restartGameHintText.setString("Press \"R\" to restart game.");

		SetTextData(gameOverText, font, GAME_OVER_SIZE, sf::Color::Red);
		gameOverText.setStyle(sf::Text::Bold);
		gameOverText.setString("GAME OVER");
		gameOverText.setOrigin(GetTextOrigin(gameOverText, { 0.5f, 0.5f }));

		leaderboardUIDrawer->Initialization(font);
	}

	void GameplayUserInterface::UpdateUI(float deltaTime)
	{
		scoreText.setString("Points: " + std::to_string(gameData.numOfPoints));

		isGameOverTextVisible = gameData.isGameOver;
	}

	void GameplayUserInterface::DrawTextOnGameOver(sf::RenderWindow& window)
	{
		gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		window.draw(gameOverText);

		restartGameHintText.setPosition(10.f, window.getSize().y - 20.f - (float)RESTART_GAME_SIZE);
		window.draw(restartGameHintText);

		leaderboardUIDrawer->DrawLeaderboard(window);
	}
}
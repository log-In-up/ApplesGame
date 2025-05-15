#include "GameplayUserInterface.h"
#include "Mathematics.h"
#include "GameMain.h"
#include "Game.h"

namespace ApplesGame
{
	bool isGameOverTextVisible;

	sf::Text scoreText;
	sf::Text inputHintText;
	sf::Text restartGameHintText;
	sf::Text gameOverText;
	std::vector<sf::Text> players;

	GameplayUserInterface::GameplayUserInterface(std::map<std::string, int>& recordsTable) : recordsTable(recordsTable)
	{
		isGameOverTextVisible = false;

		for (std::pair<std::string, int> record : recordsTable)
		{
			sf::Text text;
			players.push_back(text);
		}
	}

	GameplayUserInterface::~GameplayUserInterface()
	{
		players.clear();
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

		for (int index = 0; index < recordsTable.size(); index++)
		{
			SetTextData(players[index], font, LEADERBOARD_SIZE, sf::Color::White);
		}
	}

	void GameplayUserInterface::UpdateUI(GameData& gameData, float deltaTime)
	{
		scoreText.setString("Points: " + std::to_string(gameData.numOfPoints));

		isGameOverTextVisible = gameData.isGameOver;
	}

	void GameplayUserInterface::DrawLeaderboard(sf::RenderWindow& window)
	{
		float y;
		for (int index = 0; index < players.size(); index++)
		{
			std::pair<const std::string, int>& record = *std::next(recordsTable.begin(), index);
			y = (float(LEADERBOARD_SIZE * index) + 10.f) + 20.f;

			players[index].setString(record.first + " " + std::to_string(record.second));
			players[index].setPosition(window.getSize().x / 2.f - 20.f, window.getSize().y / 2.f + y);

			window.draw(players[index]);
		}
	}

	void GameplayUserInterface::DrawTextOnGameOver(sf::RenderWindow& window)
	{
		gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		window.draw(gameOverText);

		restartGameHintText.setPosition(10.f, window.getSize().y - 20.f - (float)RESTART_GAME_SIZE);
		window.draw(restartGameHintText);

		DrawLeaderboard(window);
	}

	void GameplayUserInterface::SetTextData(sf::Text& text, const sf::Font& font, unsigned int size, const sf::Color color)
	{
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(color);
	}
}
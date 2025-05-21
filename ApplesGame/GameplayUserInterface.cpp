#include "Game.h"
#include "GameMain.h"
#include "GameplayUserInterface.h"
#include "LeaderboardDrawer.h"
#include "Mathematics.h"
#include "Menu.h"
#include "Text.h"
#include "TimeService.h"

namespace ApplesGame
{
	bool isGameOverTextVisible;

	sf::Text scoreText;
	sf::Text inputHintText;
	sf::Text restartGameHintText;
	sf::Text gameOverText;

	LeaderboardDrawer* leaderboardUIDrawer;
	Menu* pauseMenu;

	GameplayUserInterface::GameplayUserInterface(GameData& gameData) : recordsTable(gameData.recordsTable), gameData(gameData)
	{
		isGameOverTextVisible = false;

		leaderboardUIDrawer = new LeaderboardDrawer(this->recordsTable);
		pauseMenu = new Menu();
	}

	GameplayUserInterface::~GameplayUserInterface()
	{
		delete leaderboardUIDrawer;
		delete pauseMenu;
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

		if (TimeIsPaused())
		{
			sf::Vector2f viewSize = (sf::Vector2f)window.getView().getSize();

			sf::Text* hintText = &pauseMenu->GetCurrentContext().hintText;
			hintText->setOrigin(GetTextOrigin(*hintText, { 0.5f, 0.f }));
			hintText->setPosition(viewSize.x / 2.f, 150.f);
			window.draw(*hintText);

			pauseMenu->Draw(window, viewSize / 2.f, { 0.5f, 0.f });
		}
	}

	void GameplayUserInterface::HandleWindowEvents(sf::RenderWindow& window, sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				pauseMenu->GoBack();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				pauseMenu->PressOnSelectedItem();
			}

			Orientation orientation = pauseMenu->GetCurrentContext().childrenOrientation;
			if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Up ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Left)
			{
				pauseMenu->SwitchToPreviousMenuItem();
			}
			else if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Down ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Right)
			{
				pauseMenu->SwitchToNextMenuItem();
			}
		}
	}

	void GameplayUserInterface::InitUI(const sf::Font& font, const MenuItem& item)
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

		pauseMenu->Initialization(item);
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
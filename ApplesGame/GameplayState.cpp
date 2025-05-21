#include "AppleDrawer.h"
#include "CollisionHandler.h"
#include "GameplayState.h"
#include "GameplayUserInterface.h"
#include "GameStateMachine.h"
#include "InputHandler.h"
#include "MainMenuState.h"
#include "ObstacleDrawer.h"
#include "Text.h"
#include "TimeService.h"

namespace ApplesGame
{
	AppleDrawer* appleDrawer;
	AppleFactory appleFactory;
	CollisionHandler* collisionHandler;
	InputHandler* inputHandler;
	ObstacleDrawer* obstacleDrawer;
	ObstaclesFactory* obstaclesFactory;
	GameplayUserInterface* userInterface;

	GameplayState::GameplayState(GameData& gameData) : GameState(gameData)
	{
		int size = this->gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Hard) ?
			INCREASED_NUM_APPLES : STANDARD_NUM_APPLES;

		for (int index = 0; index < size; index++)
		{
			this->gameData.apples.push_back(AppleData());
		}
		this->gameData.obstacles = new ObstacleData[NUM_OBSTACLES];

		appleDrawer = new AppleDrawer();
		appleFactory = AppleFactory();
		collisionHandler = new CollisionHandler(this->gameData, appleFactory);
		inputHandler = new InputHandler();
		obstacleDrawer = new ObstacleDrawer();
		obstaclesFactory = new ObstaclesFactory();
		userInterface = new GameplayUserInterface(this->gameData);
	}

	GameplayState::~GameplayState()
	{
		gameData.apples.clear();
		delete[] gameData.obstacles;

		delete appleDrawer;
		delete collisionHandler;
		delete inputHandler;
		delete obstacleDrawer;
		delete userInterface;
	}

	void GameplayState::DrawGame(sf::RenderWindow& window)
	{
		gameData.player.Draw(window);

		appleDrawer->DrawApples(gameData, window);

		for (int indexOfObstacle = 0; indexOfObstacle < NUM_OBSTACLES; indexOfObstacle++)
		{
			obstacleDrawer->DrawObstacle(gameData.obstacles[indexOfObstacle], window);
		}

		userInterface->DrawUI(window);
	}

	void GameplayState::HandleWindowEvents(sf::RenderWindow& window, sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			bool gameIsPaused = TimeIsPaused();

			if (!gameData.isGameOver)
			{
				if (!gameIsPaused)
				{
					inputHandler->ReadInputForPlayer(gameData.player, event);
				}

				if (event.key.code == sf::Keyboard::P)
				{
					SetPause(!gameIsPaused);
				}
			}
			else
			{
				if (event.key.code == sf::Keyboard::R)
				{
					RestartGame();
				}
			}
		}

		userInterface->HandleWindowEvents(window, event);
	}

	void GameplayState::Initialization()
	{
		auto setTextData = [](sf::Text& text, const std::string string, sf::Font& font, unsigned int size)
			{
				text.setString(string);
				text.setFont(font);
				text.setCharacterSize(size);
			};

		auto setTextColorData = [setTextData](sf::Text& text, const std::string string, sf::Font& font, unsigned int size, sf::Color color)
			{
				setTextData(text, string, font, size);
				text.setFillColor(color);
			};

		auto setChildrenData = [](MenuItem& item, Orientation orientation, Alignment alignment, float spacing)
			{
				item.childrenOrientation = orientation;
				item.childrenAlignment = alignment;
				item.childrenSpacing = spacing;
			};

		MenuItem continuePlay;
		setTextData(continuePlay.text, "Continue", gameData.resourceData.font, 24);
		continuePlay.onPressCallback = [this](MenuItem& item)
			{
				SetPause(false);
			};

		MenuItem backToMainMenu;
		setTextData(backToMainMenu.text, "Exit to menu", gameData.resourceData.font, 24);
		backToMainMenu.onPressCallback = [this](MenuItem& item)
			{
				gameStateMachine->SwitchCurrentStateTo(new MainMenuState(gameData));
			};

		MenuItem pause;
		setTextColorData(pause.hintText, "Pause", gameData.resourceData.font, 48, sf::Color::Red);
		setChildrenData(pause, Orientation::Vertical, Alignment::Middle, 10.f);
		pause.childrens.push_back(continuePlay);
		pause.childrens.push_back(backToMainMenu);

		userInterface->InitUI(gameData.resourceData.font, pause);

		RestartGame();
	}

	void GameplayState::Update(float deltaTime, sf::RenderWindow& window)
	{
		if (!gameData.isGameOver)
		{
			UpdateOnPlayState(deltaTime);
		}

		userInterface->UpdateUI(deltaTime);
	}

	void GameplayState::RestartGame()
	{
		gameData.player.Initialization(gameData.resourceData);

		for (int indexOfApple = 0; indexOfApple < gameData.apples.size(); indexOfApple++)
		{
			appleFactory.CreateApple(gameData.apples[indexOfApple], gameData.resourceData);
		}

		for (int indexOfObstacle = 0; indexOfObstacle < NUM_OBSTACLES; indexOfObstacle++)
		{
			obstaclesFactory->CreateObstacle(gameData.obstacles[indexOfObstacle], gameData.resourceData);
		}

		gameData.numEatenApples = 0;
		gameData.numOfPoints = 0;
		gameData.isGameOver = false;

		SetPause(false);
	}

	void GameplayState::UpdateOnPlayState(float deltaTime)
	{
		gameData.player.Update(deltaTime);

		collisionHandler->Update();
	}
}
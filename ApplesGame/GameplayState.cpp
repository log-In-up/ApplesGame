#include "AppleDrawer.h"
#include "CollisionHandler.h"
#include "GameplayState.h"
#include "GameplayUserInterface.h"
#include "InputHandler.h"
#include "ObstacleDrawer.h"

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
		if (!gameData.isGameOver)
		{
			inputHandler->ReadInputForPlayer(gameData.player, event);
		}
		else
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::R)
				{
					RestartGame();
				}
			}
		}
	}

	void GameplayState::Initialization()
	{
		userInterface->InitUI(gameData.resourceData.font);

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
	}

	void GameplayState::UpdateOnPlayState(float deltaTime)
	{
		gameData.player.Update(deltaTime);

		collisionHandler->Update();
	}
}
#include <cassert>

#include "AppleDrawer.h"
#include "CollisionHandler.h"
#include "Game.h"
#include "GameMain.h"
#include "InputHandler.h"
#include "TimeService.h"
#include "ObstacleDrawer.h"
#include "ResourceLoader.h"
#include "UserInterface.h"

namespace ApplesGame
{
	AppleDrawer* appleDrawer;
	AppleFactory appleFactory;
	CollisionHandler* collisionHandler;
	InputHandler* inputHandler;
	ObstacleDrawer* obstacleDrawer;
	ObstaclesFactory obstaclesFactory;
	ResourceLoader* resourceLoader;
	TimeService* timeService;
	UserInterface* userInterface;

	Game::Game(GameData& gameData) : _gameData(gameData)
	{
		_gameData.apples = new AppleData[NUM_APPLES];
		_gameData.obstacles = new ObstacleData[NUM_OBSTACLES];

		appleDrawer = new AppleDrawer();
		appleFactory = AppleFactory();
		collisionHandler = new CollisionHandler(_gameData, appleFactory);
		inputHandler = new InputHandler();
		obstacleDrawer = new ObstacleDrawer();
		obstaclesFactory = ObstaclesFactory();
		resourceLoader = new ResourceLoader();
		timeService = new TimeService();
		userInterface = new UserInterface();
	}

	Game::~Game()
	{
		delete[] _gameData.apples;
		delete[] _gameData.obstacles;

		delete appleDrawer;
		delete collisionHandler;
		delete inputHandler;
		delete obstacleDrawer;
		delete resourceLoader;
		delete timeService;
		delete userInterface;
	}

	void Game::DrawGame(sf::RenderWindow& window)
	{
		_gameData.player.Draw(window);

		appleDrawer->DrawApples(_gameData, window);

		for (int indexOfObstacle = 0; indexOfObstacle < NUM_OBSTACLES; indexOfObstacle++)
		{
			obstacleDrawer->DrawObstacle(_gameData.obstacles[indexOfObstacle], window);
		}

		userInterface->DrawUI(window);
	}

	void Game::Initialization()
	{
		resourceLoader->LoadResources(_gameData.resourceData);

		timeService->Initialization();

		userInterface->InitUI(_gameData.resourceData.font);

		RestartGame();
	}

	void Game::Update(sf::RenderWindow& window)
	{
		float deltaTime = timeService->GetDeltaTime();

		if (_gameData.isGameOver)
		{
			UpdateGameOverState(deltaTime);
		}
		else
		{
			UpdateOnPlayState(deltaTime);
		}

		userInterface->UpdateUI(_gameData, deltaTime);
	}

	void Game::RestartGame()
	{
		_gameData.player.Initialization(_gameData.resourceData);

		for (int indexOfApple = 0; indexOfApple < NUM_APPLES; indexOfApple++)
		{
			appleFactory.CreateApple(_gameData.apples[indexOfApple], _gameData.resourceData);
		}

		for (int indexOfObstacle = 0; indexOfObstacle < NUM_OBSTACLES; indexOfObstacle++)
		{
			obstaclesFactory.CreateObstacle(_gameData.obstacles[indexOfObstacle], _gameData.resourceData);
		}

		_gameData.numEatenApples = 0;
		_gameData.numOfPoints = 0;
		_gameData.isGameOver = false;
		_gameData.timeSinceGameOver = 0.f;
	}
	void Game::UpdateGameOverState(float deltaTime)
	{
		_gameData.timeSinceGameOver += deltaTime;

		if (_gameData.timeSinceGameOver >= GAMEOVER_TIMEOUT)
		{
			RestartGame();
		}
	}
	void Game::UpdateOnPlayState(float deltaTime)
	{
		inputHandler->ReadInputForPlayer(_gameData.player);

		_gameData.player.Update(deltaTime);

		collisionHandler->Update();
	}
}
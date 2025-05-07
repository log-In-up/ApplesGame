#include <cassert>

#include "Game.h"
#include "GameMain.h"
#include "MainMenuState.h"
#include "GameStateMachine.h"
#include "ResourceLoader.h"
#include "TimeService.h"

namespace ApplesGame
{
	ResourceLoader* resourceLoader;
	TimeService* timeService;
	GameStateMachine* gameStateMachine;

	Game::Game(GameData& gameData) : gameData(gameData)
	{
		resourceLoader = new ResourceLoader();
		timeService = new TimeService();
		gameStateMachine = new GameStateMachine(new MainMenuState(this->gameData));
	}

	Game::~Game()
	{
		delete resourceLoader;
		delete timeService;
		delete gameStateMachine;
	}

	void Game::DrawGame(sf::RenderWindow& window)
	{
		gameStateMachine->DrawGame(window);
	}

	void Game::Initialization()
	{
		gameData.gameDifficultyMask = static_cast<uint32_t>(ApplesGame::GameDifficulty::Easy);
		gameData.gameModeBitMask = static_cast<uint32_t>(ApplesGame::GameOptions::Default);

		resourceLoader->LoadResources(gameData.resourceData);

		timeService->Initialization();

		gameStateMachine->Initialization();
	}

	void Game::Update(sf::RenderWindow& window)
	{
		float deltaTime = timeService->GetDeltaTime();

		gameStateMachine->Update(deltaTime, window);
	}
}
#include <cassert>

#include "Game.h"
#include "GameMain.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
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

		gameData.recordsTable =
		{
			{"Carol", 55},
			{"Jane", 30 },
			{"Alice", 120 },
			{"Bob", 85 }
		};
		gameData.recordsTable.insert({ PLAYER_NAME, 0 });
	}

	Game::~Game()
	{
		delete resourceLoader;
		delete timeService;
		delete gameStateMachine;

		gameData.recordsTable.clear();
	}

	void Game::DrawGame(sf::RenderWindow& window)
	{
		gameStateMachine->DrawGame(window);
	}

	void Game::HandleWindowEvents(sf::RenderWindow& window, sf::Event& event)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			gameStateMachine->HandleWindowEvents(window, event);
		}
	}

	void Game::Initialization()
	{
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
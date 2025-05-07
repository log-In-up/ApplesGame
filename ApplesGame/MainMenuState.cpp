#include "MainMenuState.h"
#include "GameStateMachine.h"
#include "MenuInputHandler.h"
#include "MainMenuUI.h"
#include "GameplayState.h"

namespace ApplesGame
{
	MenuInputHandler* inputHandler;
	MainMenuUI* userInterface;

	MainMenuState::MainMenuState(GameData& gameData) : GameState(gameData)
	{
		inputHandler = new MenuInputHandler(this->gameData);
		userInterface = new MainMenuUI();
	}

	MainMenuState::~MainMenuState()
	{
		delete inputHandler;
		delete userInterface;
	}

	void MainMenuState::DrawGame(sf::RenderWindow& window)
	{
		userInterface->DrawUI(window);
	}

	void MainMenuState::Initialization()
	{
		userInterface->InitUI(gameData.resourceData.font);
	}

	void MainMenuState::Update(float deltaTime, sf::RenderWindow& window)
	{
		inputHandler->Update();
		userInterface->UpdateUI(gameData, deltaTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			gameStateMachine->SwitchCurrentStateTo(new GameplayState(this->gameData));
		}
	}
}
#include "GameStateMachine.h"

namespace ApplesGame
{
	void GameStateMachine::DrawGame(sf::RenderWindow& window)
	{
		currentGameState->DrawGame(window);
	}

	void GameStateMachine::Initialization()
	{
		currentGameState->Initialization();
	}

	void GameStateMachine::SwitchCurrentStateTo(GameState* newGameState)
	{
		if (this->currentGameState != nullptr)
		{
			delete this->currentGameState;
		}

		this->currentGameState = newGameState;
		this->currentGameState->SetGameStateMachine(this);
		this->currentGameState->Initialization();
	}

	void GameStateMachine::Update(float deltaTime, sf::RenderWindow& window)
	{
		currentGameState->Update(deltaTime, window);
	}
}
#include "GameState.h"

namespace ApplesGame
{
	GameState::GameState(GameData& gameData) : gameData(gameData), gameStateMachine(nullptr)
	{
	}

	GameState::~GameState()
	{
	}

	void GameState::SetGameStateMachine(GameStateMachine* gameStateMachine)
	{
		this->gameStateMachine = gameStateMachine;
	}
}
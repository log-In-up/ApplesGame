#include "GameStateMachine.h"
#include "LeaderboardDrawer.h"
#include "LeaderBoardState.h"
#include "MainMenuState.h"
#include "Utils.h"

namespace ApplesGame
{
	LeaderboardDrawer* leaderboardDrawer;
	sf::Text* backspaceHint;

	LeaderBoardState::LeaderBoardState(GameData& gameData) : GameState(gameData)
	{
		backspaceHint = new sf::Text("Press \"Backspace\" to return to the menu", gameData.resourceData.font, 24);

		leaderboardDrawer = new LeaderboardDrawer(this->gameData.recordsTable);
	}

	LeaderBoardState::~LeaderBoardState()
	{
		delete backspaceHint;
		delete leaderboardDrawer;
	}

	void LeaderBoardState::DrawGame(sf::RenderWindow& window)
	{
		leaderboardDrawer->DrawLeaderboard(window);

		backspaceHint->setPosition(10.f, window.getSize().y - 44.0f);
		window.draw(*backspaceHint);
	}

	void LeaderBoardState::HandleWindowEvents(sf::RenderWindow& window, sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Backspace)
			{
				gameStateMachine->SwitchCurrentStateTo(new MainMenuState(gameData));
			}
		}
	}

	void LeaderBoardState::Initialization()
	{
		SelectionSort(this->gameData.recordsTable);
		leaderboardDrawer->Initialization(gameData.resourceData.font);
	}

	void LeaderBoardState::Update(float deltaTime, sf::RenderWindow& window)
	{
	}
}
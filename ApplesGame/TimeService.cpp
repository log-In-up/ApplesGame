#include <SFML/Graphics.hpp>

#include "TimeService.h"

namespace ApplesGame
{
	sf::Clock gameClock;
	float lastTime;

	bool gameIsOnPause;

	TimeService::TimeService()
	{
		gameClock = sf::Clock();
		gameIsOnPause = false;
	}

	float TimeService::GetDeltaTime()
	{
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = gameIsOnPause ? ZERO_DELTA_TIME : currentTime - lastTime;
		lastTime = currentTime;

		return deltaTime;
	}

	void TimeService::Initialization()
	{
		lastTime = gameClock.getElapsedTime().asSeconds();
	}

	bool TimeIsPaused()
	{
		return gameIsOnPause;
	}

	void SetPause(bool value)
	{
		gameIsOnPause = value;
	}
}
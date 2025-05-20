#include <SFML/Graphics.hpp>

#include "TimeService.h"

namespace ApplesGame
{
	sf::Clock gameClock;
	float lastTime;

	TimeService::TimeService()
	{
		gameClock = sf::Clock();
	}

	float TimeService::GetDeltaTime()
	{
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		return deltaTime;
	}

	void TimeService::Initialization()
	{
		lastTime = gameClock.getElapsedTime().asSeconds();
	}
}
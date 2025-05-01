#include "AppleDrawer.h"

namespace ApplesGame
{
	void AppleDrawer::DrawApples(const GameData& gameData, sf::RenderWindow& window)
	{
		for (int indexOfApple = 0; indexOfApple < NUM_APPLES; indexOfApple++)
		{
			window.draw(gameData.apples[indexOfApple].sprite);
		}
	}
}
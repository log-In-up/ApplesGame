#include "AppleDrawer.h"

namespace ApplesGame
{
	void AppleDrawer::DrawApples(const GameData& gameData, sf::RenderWindow& window)
	{
		for (int indexOfApple = 0; indexOfApple < gameData.apples.size(); indexOfApple++)
		{
			window.draw(gameData.apples[indexOfApple].sprite);
		}
	}
}
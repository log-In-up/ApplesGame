#include "ObstacleDrawer.h"
#include "Game.h"

namespace ApplesGame
{
	void ObstacleDrawer::DrawObstacle(ObstacleData& obstacleData, sf::RenderWindow& window)
	{
		window.draw(obstacleData.sprite);
	}
}
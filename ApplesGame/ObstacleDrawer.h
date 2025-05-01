#pragma once
#include "ObstaclesFactory.h"

namespace ApplesGame
{
	class ObstacleDrawer
	{
	public:
		void DrawObstacle(ObstacleData& obstacleData, sf::RenderWindow& window);
	};
}
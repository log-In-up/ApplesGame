#include "ObstaclesFactory.h"
#include "GameMain.h"

namespace ApplesGame
{
	void ObstaclesFactory::CreateObstacle(ObstacleData& obstacleData, ResourceData& resourceData)
	{
		// init apple state
		obstacleData.position.x = (float)(rand() % (SCREEN_WIDTH + 1));
		obstacleData.position.y = (float)(rand() % (SCREEN_HEIGHT + 1));

		// Init sprite
		obstacleData.sprite.setTexture(resourceData.rockTexture);
		SetSpriteSize(obstacleData.sprite, OBSTACLE_SIZE, OBSTACLE_SIZE);
		SetSpriteRelativeOrigin(obstacleData.sprite, 0.5f, 0.5f);
		obstacleData.sprite.setPosition(obstacleData.position.x, obstacleData.position.y);
	}
}
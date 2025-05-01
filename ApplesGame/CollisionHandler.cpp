#include "CollisionHandler.h"
#include "GameMain.h"

namespace ApplesGame
{
	CollisionHandler::CollisionHandler(GameData& gameData, AppleFactory& appleFactory) : _gameData(gameData), factory(appleFactory)
	{
	}

	void CollisionHandler::Update()
	{
		CheckCollisionWithApples();
		CheckCollisionWithObstacles();
		CheckScreenBordersCollision();
	}

	bool CollisionHandler::HasPlayerCollisionWithApple(const AppleData& apple)
	{
		float deltaX = _gameData.player.position.x - apple.position.x;
		float deltaY = _gameData.player.position.y - apple.position.y;
		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		return distance < (PLAYER_SIZE + APPLE_SIZE) / 2.f;
	}

	bool CollisionHandler::HasPlayerCollisionWithObstacle(const ObstacleData& obstacle)
	{
		float deltaX = _gameData.player.position.x - obstacle.position.x;
		float deltaY = _gameData.player.position.y - obstacle.position.y;
		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		return distance < (PLAYER_SIZE + OBSTACLE_SIZE) / 2.f;
	}

	bool CollisionHandler::HasPlayerCollisionWithScreenBorder()
	{
		return (_gameData.player.position.x - PLAYER_SIZE / 2.f < 0) ||
			(_gameData.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH) ||
			(_gameData.player.position.y - PLAYER_SIZE / 2.f < 0) ||
			(_gameData.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT);
	}

	void CollisionHandler::CheckCollisionWithApples()
	{
		for (int appleIndex = 0; appleIndex < NUM_APPLES; appleIndex++)
		{
			if (HasPlayerCollisionWithApple(_gameData.apples[appleIndex]))
			{
				factory.CreateApple(_gameData.apples[appleIndex], _gameData.resourceData);

				_gameData.numEatenApples++;
				_gameData.numOfPoints += POINTS_PER_APPLE;

				_gameData.player.AccelerateMovementSpeed(ACCELERATION);

				_gameData.resourceData.eatAppleSound.play();
			}
		}
	}

	void CollisionHandler::CheckCollisionWithObstacles()
	{
		for (int obstacleIndex = 0; obstacleIndex < NUM_APPLES; obstacleIndex++)
		{
			if (HasPlayerCollisionWithObstacle(_gameData.obstacles[obstacleIndex]))
			{
				_gameData.isGameOver = true;
				_gameData.resourceData.gameOverSound.play();
				break;
			}
		}
	}

	void CollisionHandler::CheckScreenBordersCollision()
	{
		if (HasPlayerCollisionWithScreenBorder())
		{
			_gameData.isGameOver = true;
			_gameData.resourceData.gameOverSound.play();
		}
	}
}
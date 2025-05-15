#include "CollisionHandler.h"
#include "GameMain.h"
#include "Utils.h"

namespace ApplesGame
{
	CollisionHandler::CollisionHandler(GameData& gameData, AppleFactory& appleFactory) : gameData(gameData), appleFactory(appleFactory)
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
		float deltaX = gameData.player.position.x - apple.position.x;
		float deltaY = gameData.player.position.y - apple.position.y;
		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		return distance < (PLAYER_SIZE + APPLE_SIZE) / 2.f;
	}

	bool CollisionHandler::HasPlayerCollisionWithObstacle(const ObstacleData& obstacle)
	{
		float deltaX = gameData.player.position.x - obstacle.position.x;
		float deltaY = gameData.player.position.y - obstacle.position.y;
		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		return distance < (PLAYER_SIZE + OBSTACLE_SIZE) / 2.f;
	}

	bool CollisionHandler::HasPlayerCollisionWithScreenBorder()
	{
		return (gameData.player.position.x - PLAYER_SIZE / 2.f < 0) ||
			(gameData.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH) ||
			(gameData.player.position.y - PLAYER_SIZE / 2.f < 0) ||
			(gameData.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT);
	}

	void CollisionHandler::CheckCollisionWithApples()
	{
		for (int appleIndex = 0; appleIndex < gameData.apples.size(); appleIndex++)
		{
			if (HasPlayerCollisionWithApple(gameData.apples[appleIndex]))
			{
				if (gameData.gameModeBitMask & static_cast<uint32_t>(GameOptions::InfiniteApples))
				{
					appleFactory.CreateApple(gameData.apples[appleIndex], gameData.resourceData);
				}
				else
				{
					appleFactory.DestroyApple(gameData.apples[appleIndex]);
				}

				gameData.numEatenApples++;
				gameData.numOfPoints += POINTS_PER_APPLE;

				if (gameData.gameModeBitMask & static_cast<uint32_t>(GameOptions::WithAcceleration))
				{
					gameData.player.AccelerateMovementSpeed(ACCELERATION);
				}

				gameData.resourceData.eatAppleSound.play();
			}
		}
	}

	void CollisionHandler::CheckCollisionWithObstacles()
	{
		for (int obstacleIndex = 0; obstacleIndex < gameData.apples.size(); obstacleIndex++)
		{
			if (HasPlayerCollisionWithObstacle(gameData.obstacles[obstacleIndex]))
			{
				LaunchGameOverSubstate();
				break;
			}
		}
	}

	void CollisionHandler::CheckScreenBordersCollision()
	{
		if (HasPlayerCollisionWithScreenBorder())
		{
			LaunchGameOverSubstate();
		}
	}

	void CollisionHandler::LaunchGameOverSubstate()
	{
		UpdateRecord(PLAYER_NAME, gameData.numEatenApples);
		SelectionSort(gameData.recordsTable);

		gameData.isGameOver = true;
		gameData.resourceData.gameOverSound.play();
	}

	void CollisionHandler::UpdateRecord(const std::string& playerId, int score)
	{
		gameData.recordsTable[playerId] = std::max(gameData.recordsTable[playerId], score);
	}
}
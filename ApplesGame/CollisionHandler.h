#pragma once
#include <unordered_map>

#include "Game.h"
namespace ApplesGame
{
	class CollisionHandler
	{
	public:
		CollisionHandler(GameData& gameData, AppleFactory& appleFactory);
		void Update();
	private:
		GameData& gameData;
		AppleFactory& appleFactory;

		bool HasPlayerCollisionWithApple(const AppleData& apple);
		bool HasPlayerCollisionWithObstacle(const ObstacleData& obstacle);
		bool HasPlayerCollisionWithScreenBorder();
		void CheckCollisionWithApples();
		void CheckCollisionWithObstacles();
		void CheckScreenBordersCollision();
		void LaunchGameOverSubstate();
		void UpdateRecord(const std::string& playerId, int score);
	};
}
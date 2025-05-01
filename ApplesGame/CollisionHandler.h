#pragma once

#include "Game.h"

namespace ApplesGame
{
	class CollisionHandler
	{
	public:
		CollisionHandler(GameData& gameData, AppleFactory& appleFactory);
		void Update();
	private:
		GameData& _gameData;
		AppleFactory& factory;

		bool HasPlayerCollisionWithApple(const AppleData& apple);
		bool HasPlayerCollisionWithObstacle(const ObstacleData& obstacle);
		bool HasPlayerCollisionWithScreenBorder();
		void CheckCollisionWithApples();
		void CheckCollisionWithObstacles();
		void CheckScreenBordersCollision();
	};
}
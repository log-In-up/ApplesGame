#pragma once
#include <SFML/Graphics.hpp>
#include "Mathematics.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	const float OBSTACLE_SIZE = 10.f;
	const int NUM_OBSTACLES = 10;

	struct ObstacleData
	{
		Vector2D position;
		sf::Sprite sprite;
	};

	class ObstaclesFactory
	{
	public:
		void CreateObstacle(ObstacleData& obstacleData, ResourceData& resourceData);
	};
}
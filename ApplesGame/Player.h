#pragma once

#include <SFML/Graphics.hpp>
#include "Mathematics.h"
#include "AppleFactory.h"
#include "ObstaclesFactory.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	const float INITIAL_SPEED = 100.f, ACCELERATION = 20.f;
	const float PLAYER_SIZE = 20.f;

	enum class PlayerDirection
	{
		Up = 0,
		Right,
		Down,
		Left
	};

	class Player
	{
	public:
		Vector2D position;
		void AccelerateMovementSpeed(float accleleration);
		void Draw(sf::RenderWindow& window);
		void Initialization(const ResourceData& resourceData);
		void SetMovementDirection(PlayerDirection movementDirection);
		void Update(float deltaTime);
	private:
		void MovePlayer(float deltaTime);
	};
}
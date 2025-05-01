#include <SFML/Graphics.hpp>
#include <cassert>
#include "Player.h"
#include "GameMain.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	sf::Sprite sprite;

	float movementSpeed = 0.f;
	PlayerDirection _movementDirection = PlayerDirection::Up;

	void Player::AccelerateMovementSpeed(float accleleration)
	{
		movementSpeed += accleleration;
	}

	void Player::Draw(sf::RenderWindow& window)
	{
		window.draw(sprite);

		switch (_movementDirection)
		{
		case PlayerDirection::Up:
			SetSpriteSize(sprite, PLAYER_SIZE, PLAYER_SIZE);
			sprite.setRotation(270.f);
			break;
		case PlayerDirection::Right:
			SetSpriteSize(sprite, -PLAYER_SIZE, -PLAYER_SIZE);
			sprite.setRotation(180.f);
			break;
		case PlayerDirection::Down:
			SetSpriteSize(sprite, PLAYER_SIZE, PLAYER_SIZE);
			sprite.setRotation(90.f);
			break;
		case PlayerDirection::Left:
			SetSpriteSize(sprite, -PLAYER_SIZE, PLAYER_SIZE);
			sprite.setRotation(0.f);
			break;
		default:
			break;
		}
	}

	void Player::Initialization(const ResourceData& resourceData)
	{
		movementSpeed = INITIAL_SPEED;
		_movementDirection = PlayerDirection::Up;

		position.x = SCREEN_WIDTH / 2.f;
		position.y = SCREEN_HEIGHT / 2.f;

		sprite.setTexture(resourceData.playerTexture);
		SetSpriteSize(sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
	}

	void Player::SetMovementDirection(PlayerDirection movementDirection)
	{
		_movementDirection = movementDirection;
	}

	void Player::Update(float deltaTime)
	{
		MovePlayer(deltaTime);
	}

	void Player::MovePlayer(float deltaTime)
	{
		switch (_movementDirection)
		{
		case PlayerDirection::Up:
			position.y -= movementSpeed * deltaTime;
			break;
		case PlayerDirection::Right:
			position.x += movementSpeed * deltaTime;
			break;
		case PlayerDirection::Down:
			position.y += movementSpeed * deltaTime;
			break;
		case PlayerDirection::Left:
			position.x -= movementSpeed * deltaTime;
			break;
		default:
			break;
		}

		sprite.setPosition(position.x, position.y);
	}
}
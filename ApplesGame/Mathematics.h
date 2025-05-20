#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	struct Vector2D
	{
		float x = 0.f;
		float y = 0.f;
	};

	class Mathematics
	{
	};

	sf::Vector2f GetTextOrigin(sf::Text& text, const Vector2D& relativePosition);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
}
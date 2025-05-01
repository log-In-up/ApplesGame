#pragma once

#include <SFML/Graphics.hpp>
#include "Mathematics.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	const float APPLE_SIZE = 20.f;
	const int NUM_APPLES = 20;

	struct AppleData
	{
		Vector2D position;
		sf::Sprite sprite;
	};

	class AppleFactory
	{
	public:
		void CreateApple(AppleData& appleData, ResourceData& resourceData);
	};
}
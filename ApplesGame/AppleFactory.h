#pragma once

#include <SFML/Graphics.hpp>
#include "Mathematics.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	const float APPLE_SIZE = 20.f;
	const int STANDARD_NUM_APPLES = 20, INCREASED_NUM_APPLES = 50;

	struct AppleData
	{
		Vector2D position;
		sf::Sprite sprite;
	};

	class AppleFactory
	{
	public:
		void CreateApple(AppleData& appleData, ResourceData& resourceData);
		void DestroyApple(AppleData& appleData);
	private:
		void InitAppleSprite(AppleData& appleData);
	};
}
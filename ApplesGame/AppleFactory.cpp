#include "AppleFactory.h"
#include "GameMain.h"

namespace ApplesGame
{
	void AppleFactory::CreateApple(AppleData& appleData, ResourceData& resourceData)
	{
		// init apple state
		appleData.position.x = (float)(rand() % (SCREEN_WIDTH + 1));
		appleData.position.y = (float)(rand() % (SCREEN_HEIGHT + 1));

		// Init sprite
		appleData.sprite.setTexture(resourceData.appleTexture);
		InitAppleSprite(appleData);
	}

	//Instead of actually "destroying" the apple, we move the apple out of the player's view
	void AppleFactory::DestroyApple(AppleData& appleData)
	{
		appleData.position.x = (float)SCREEN_WIDTH;
		appleData.position.y = (float)SCREEN_HEIGHT;

		InitAppleSprite(appleData);
	}

	void AppleFactory::InitAppleSprite(AppleData& appleData)
	{
		SetSpriteSize(appleData.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(appleData.sprite, 0.5f, 0.5f);
		appleData.sprite.setPosition(appleData.position.x, appleData.position.y);
	}
}
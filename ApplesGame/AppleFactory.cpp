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
		SetSpriteSize(appleData.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(appleData.sprite, 0.5f, 0.5f);
		appleData.sprite.setPosition(appleData.position.x, appleData.position.y);
	}
}
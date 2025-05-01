#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceLoader.h"
#include <cassert>

namespace ApplesGame
{
	void ApplesGame::ResourceLoader::LoadResources(ResourceData& resourceData)
	{
		LoadFont(FONT_URL, resourceData.font);

		LoadSound(APPLE_EAT_SOUND_URL, resourceData.eatAppleSoundBuffer, resourceData.eatAppleSound);
		LoadSound(DEATH_SOUND_URL, resourceData.gameOverSoundBuffer, resourceData.gameOverSound);

		LoadTexture(APPLE_IMAGE_URL, resourceData.appleTexture);
		LoadTexture(PLAYER_IMAGE_URL, resourceData.playerTexture);
		LoadTexture(ROCK_IMAGE_URL, resourceData.rockTexture);
	}

	void ResourceLoader::LoadFont(std::string resourceURL, sf::Font& font)
	{
		if (font.loadFromFile(RESOURCES_PATH + resourceURL))
		{
		}
	}

	void ResourceLoader::LoadSound(std::string resourceURL, sf::SoundBuffer& soundBuffer, sf::Sound& sound)
	{
		if (soundBuffer.loadFromFile(RESOURCES_PATH + resourceURL))
		{
			sound.setBuffer(soundBuffer);
		}
	}

	void ResourceLoader::LoadTexture(std::string resourceURL, sf::Texture& texture)
	{
		if (texture.loadFromFile(RESOURCES_PATH + resourceURL))
		{
		}
	}
}
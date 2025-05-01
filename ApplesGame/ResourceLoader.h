#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace ApplesGame
{
	const std::string RESOURCES_PATH = "Resources/";
	const std::string FONT_URL = "\\Fonts\\Roboto-Bold.ttf",
		APPLE_EAT_SOUND_URL = "\\AppleEat.wav", DEATH_SOUND_URL = "\\Death.wav",
		APPLE_IMAGE_URL = "\\Apple.png", PLAYER_IMAGE_URL = "\\Player.png", ROCK_IMAGE_URL = "\\Rock.png";

	struct ResourceData
	{
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::SoundBuffer eatAppleSoundBuffer;
		sf::SoundBuffer gameOverSoundBuffer;

		// Game objects
		sf::Sound eatAppleSound;
		sf::Sound gameOverSound;

		// Texts and fonts
		sf::Font font;
	};

	class ResourceLoader
	{
	public:
		void LoadResources(ResourceData& resourceData);
	private:
		void LoadFont(std::string resourceURL, sf::Font& font);
		void LoadSound(std::string resourceURL, sf::SoundBuffer& soundBuffer, sf::Sound& sound);
		void LoadTexture(std::string resourceURL, sf::Texture& texture);
	};
}
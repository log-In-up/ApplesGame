#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "ObstaclesFactory.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	const float GAMEOVER_TIMEOUT = 2.f;
	const int POINTS_PER_APPLE = 5;

	enum class GameOptions : std::uint32_t
	{
		InfiniteApples = 1 << 0,	  // 01
		WithAcceleration = 1 << 1,    // 10

		Default = InfiniteApples | WithAcceleration
	};

	enum class GameDifficulty
	{
		Easy = 1 << 0,  // 001
		Medium = 1 << 1,// 010
		Hard = 1 << 2   // 100
	};

	struct GameData
	{
		Player player;
		std::vector<AppleData> apples;
		ObstacleData* obstacles{};
		ResourceData resourceData;
		int numEatenApples = 0, numOfPoints = 0;
		uint32_t gameModeBitMask = 0, gameDifficultyMask = 0;
		float timeSinceGameOver = 0.f;
		bool isGameOver = false;
	};

	class Game
	{
	public:
		Game(GameData& gameData);
		~Game();
		void DrawGame(sf::RenderWindow& window);
		void Initialization();
		void Update(sf::RenderWindow& window);
	private:
		GameData& gameData;
	};
}
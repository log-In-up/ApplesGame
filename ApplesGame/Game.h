#pragma once
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ObstaclesFactory.h"
#include "Player.h"
#include "ResourceLoader.h"

namespace ApplesGame
{
	const float GAMEOVER_TIMEOUT = 2.f;
	const int POINTS_PER_APPLE = 5;
	const std::string PLAYER_NAME = "Player";

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
		using RecordsTable = std::map<std::string, int>;

		Player player;
		std::vector<AppleData> apples;
		ObstacleData* obstacles{};
		ResourceData resourceData;
		RecordsTable recordsTable;
		int numEatenApples = 0, numOfPoints = 0;
		uint32_t gameModeBitMask = static_cast<uint32_t>(ApplesGame::GameOptions::Default);
		uint32_t gameDifficultyMask = static_cast<uint32_t>(ApplesGame::GameDifficulty::Easy);
		bool isGameOver = false;
	};

	class Game
	{
	private:
		GameData& gameData;
	public:
		Game(GameData& gameData);
		~Game();
		void DrawGame(sf::RenderWindow& window);
		void HandleWindowEvents(sf::RenderWindow& window, sf::Event& event);
		void Initialization();
		void Update(sf::RenderWindow& window);
	};
}
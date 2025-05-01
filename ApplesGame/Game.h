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

	struct GameData
	{
		Player player;
		AppleData* apples{};
		ObstacleData* obstacles{};
		ResourceData resourceData;
		int numEatenApples = 0;
		int numOfPoints = 0;
		bool isGameOver = false;
		float timeSinceGameOver = 0.f;
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
		GameData& _gameData;
		void RestartGame();
		void UpdateGameOverState(float deltaTime);
		void UpdateOnPlayState(float deltaTime);
	};
}
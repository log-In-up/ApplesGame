#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "GameMain.h"

namespace ApplesGame
{
	static void HandleWindowEvents(sf::RenderWindow& window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
}

int main()
{
	// Init window
	sf::RenderWindow window(sf::VideoMode(ApplesGame::SCREEN_WIDTH, ApplesGame::SCREEN_HEIGHT), ApplesGame::TITLE_OF_THE_WINDOW);

	ApplesGame::GameData gameData;
	ApplesGame::Game game = ApplesGame::Game(gameData);
	game.Initialization();

	// Main loop
	while (window.isOpen())
	{
		ApplesGame::HandleWindowEvents(window);

		if (!window.isOpen())
		{
			break;
		}

		game.Update(window);

		window.clear();

		game.DrawGame(window);

		window.display();
	}

	return 0;
}
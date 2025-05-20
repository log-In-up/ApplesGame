#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "GameMain.h"

int main()
{
	// Init window
	sf::RenderWindow window(sf::VideoMode(ApplesGame::SCREEN_WIDTH, ApplesGame::SCREEN_HEIGHT), ApplesGame::TITLE_OF_THE_WINDOW);

	sf::Event event{};
	ApplesGame::GameData gameData;
	ApplesGame::Game game = ApplesGame::Game(gameData);
	game.Initialization();

	// Main loop
	while (window.isOpen())
	{
		game.HandleWindowEvents(window, event);

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
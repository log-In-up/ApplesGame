#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace ApplesGame
{
	const unsigned int LEADERBOARD_SIZE = 20;

	class LeaderboardDrawer
	{
	private:
		std::vector<sf::Text>* players;
		std::map<std::string, int>& recordsTable;
	public:
		LeaderboardDrawer(std::map<std::string, int>& recordsTable);
		~LeaderboardDrawer();
		void DrawLeaderboard(sf::RenderWindow& window);
		void Initialization(const sf::Font& font);
	};
}
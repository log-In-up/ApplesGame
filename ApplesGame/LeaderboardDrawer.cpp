#include "LeaderboardDrawer.h"
#include "Text.h"

namespace ApplesGame
{
	LeaderboardDrawer::LeaderboardDrawer(std::map<std::string, int>& recordsTable) : recordsTable(recordsTable)
	{
		players = new std::vector<sf::Text>();

		for (std::pair<std::string, int> record : recordsTable)
		{
			sf::Text text;
			players->push_back(text);
		}
	}
	LeaderboardDrawer::~LeaderboardDrawer()
	{
		players->clear();
		delete players;
	}

	void LeaderboardDrawer::DrawLeaderboard(sf::RenderWindow& window)
	{
		float y;
		for (int index = 0; index < players->size(); index++)
		{
			std::pair<std::string, int> record = *std::next(recordsTable.begin(), index);
			y = (float(LEADERBOARD_SIZE * index) + 10.f) + 20.f;

			players->at(index).setString(record.first + " " + std::to_string(record.second));
			players->at(index).setPosition(window.getSize().x / 2.f - 20.f, window.getSize().y / 2.f + y);

			window.draw(players->at(index));
		}
	}

	void LeaderboardDrawer::Initialization(const sf::Font& font)
	{
		for (int index = 0; index < recordsTable.size(); index++)
		{
			SetTextData(players->at(index), font, LEADERBOARD_SIZE, sf::Color::White);
		}
	}
}
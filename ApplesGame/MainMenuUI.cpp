#include "MainMenuUI.h"
#include "GameMain.h"

namespace ApplesGame
{
	sf::Text easyDifficulty;
	sf::Text mediumDifficulty;
	sf::Text hardDifficulty;
	sf::Text infiniteApples;
	sf::Text playerAcceleration;
	sf::Text hint;

	void MainMenuUI::DrawUI(sf::RenderWindow& window)
	{
		window.draw(easyDifficulty);
		window.draw(mediumDifficulty);
		window.draw(hardDifficulty);
		window.draw(infiniteApples);
		window.draw(playerAcceleration);

		hint.setPosition(window.getSize().x - 10.f, 10.f);
		window.draw(hint);
	}

	void MainMenuUI::InitUI(const sf::Font& font)
	{
		SetTextData(easyDifficulty, font, 24, { 10.f, 10.f });
		easyDifficulty.setString("1) Easy difficulty");

		SetTextData(mediumDifficulty, font, 24, { 10.f, 34.f });
		mediumDifficulty.setString("2) Medium difficulty");

		SetTextData(hardDifficulty, font, 24, { 10.f, 58.f });
		hardDifficulty.setString("3) Hard difficulty");

		SetTextData(infiniteApples, font, 24, { 10.f, 82.f });
		SetTextData(playerAcceleration, font, 24, { 10.f, 106.f });

		SetTextData(hint, font, 24, { 0.f, 0.f });
		hint.setString("Press Enter for play");
		hint.setOrigin(GetTextOrigin(hint, { 1.f, 0.f }));
	}

	void MainMenuUI::UpdateUI(GameData& gameData, float deltaTime)
	{
		UpdateDifficultyColor(gameData, easyDifficulty, GameDifficulty::Easy);
		UpdateDifficultyColor(gameData, mediumDifficulty, GameDifficulty::Medium);
		UpdateDifficultyColor(gameData, hardDifficulty, GameDifficulty::Hard);

		UpdateOptionData(gameData, infiniteApples, GameOptions::InfiniteApples, "4) Apple is infinite : ");
		UpdateOptionData(gameData, playerAcceleration, GameOptions::WithAcceleration, "5) Player has acceleration: ");
	}

	void MainMenuUI::SetTextData(sf::Text& text, const sf::Font& font, unsigned int size, sf::Vector2f position)
	{
		text.setFont(font);
		text.setCharacterSize(size);
		text.setPosition(position.x, position.y);
	}

	void MainMenuUI::UpdateDifficultyColor(GameData& gameData, sf::Text& text, GameDifficulty gameDifficulty)
	{
		bool difficultyFlag = gameData.gameDifficultyMask & static_cast<uint32_t>(gameDifficulty);
		text.setFillColor(difficultyFlag ? sf::Color::Yellow : sf::Color::White);
	}

	void MainMenuUI::UpdateOptionData(GameData& gameData, sf::Text& text, GameOptions gameOption, std::string startPartOfString)
	{
		bool flag = gameData.gameModeBitMask & static_cast<uint32_t>(gameOption);
		std::string result = flag ? "Yes" : "No";
		text.setString(startPartOfString + result);
	}
}
#include "GameMain.h"
#include "GameplayState.h"
#include "GameStateMachine.h"
#include "LeaderBoardState.h"
#include "MainMenuState.h"
#include "Menu.h"

namespace ApplesGame
{
	Menu* menu;

	MainMenuState::MainMenuState(GameData& gameData) : GameState(gameData)
	{
		menu = new Menu();
	}

	MainMenuState::~MainMenuState()
	{
		delete menu;
	}

	void MainMenuState::DrawGame(sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = (sf::Vector2f)window.getView().getSize();

		sf::Text* hintText = &menu->GetCurrentContext().hintText;
		hintText->setOrigin(GetTextOrigin(*hintText, { 0.5f, 0.f }));
		hintText->setPosition(viewSize.x / 2.f, 150.f);
		window.draw(*hintText);

		menu->Draw(window, viewSize / 2.f, { 0.5f, 0.f });
	}

	void MainMenuState::HandleWindowEvents(sf::RenderWindow& window, sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				menu->GoBack();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				menu->PressOnSelectedItem();
			}

			Orientation orientation = menu->GetCurrentContext().childrenOrientation;
			if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Up ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Left)
			{
				menu->SwitchToPreviousMenuItem();
			}
			else if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Down ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Right)
			{
				menu->SwitchToNextMenuItem();
			}
		}
	}

	void MainMenuState::Initialization()
	{
		auto setTextData = [](sf::Text& text, const std::string string, sf::Font& font, unsigned int size)
			{
				text.setString(string);
				text.setFont(font);
				text.setCharacterSize(size);
			};

		auto setTextColorData = [setTextData](sf::Text& text, const std::string string, sf::Font& font, unsigned int size, sf::Color color)
			{
				setTextData(text, string, font, size);
				text.setFillColor(color);
			};

		auto setChildrenData = [](MenuItem& item, Orientation orientation, Alignment alignment, float spacing)
			{
				item.childrenOrientation = orientation;
				item.childrenAlignment = alignment;
				item.childrenSpacing = spacing;
			};

		std::string currentDifficulty = GetDifficultyName();

		MenuItem chooseDifficulty;
		setTextData(chooseDifficulty.text, "Difficulty: " + currentDifficulty, gameData.resourceData.font, 24);
		chooseDifficulty.onPressCallback = [this](MenuItem& item)
			{
				if (gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Easy))
				{
					gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Medium);
				}
				else if (gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Medium))
				{
					gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Hard);
				}
				else if (gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Hard))
				{
					gameData.gameDifficultyMask = static_cast<uint32_t>(GameDifficulty::Easy);
				}

				item.text.setString("Difficulty: " + GetDifficultyName());
			};

		MenuItem play;
		setTextData(play.text, "Play", gameData.resourceData.font, 24);
		play.onPressCallback = [this](MenuItem& item)
			{
				gameStateMachine->SwitchCurrentStateTo(new GameplayState(gameData));
			};

		MenuItem startGame;
		setTextData(startGame.text, "Start Game", gameData.resourceData.font, 24);
		startGame.childrens.push_back(chooseDifficulty);
		startGame.childrens.push_back(play);

		const bool isInfiniteApples = gameData.gameModeBitMask & static_cast<uint32_t>(GameOptions::InfiniteApples);

		MenuItem optionsInfiniteApplesItem;
		setTextData(optionsInfiniteApplesItem.text, "Infinite Apples: " + std::string(isInfiniteApples ? "On" : "Off"), gameData.resourceData.font, 24);
		optionsInfiniteApplesItem.onPressCallback = [this](MenuItem& item)
			{
				gameData.gameModeBitMask ^= static_cast<uint32_t>(GameOptions::InfiniteApples);

				bool isInfiniteApples = gameData.gameModeBitMask & static_cast<uint32_t>(GameOptions::InfiniteApples);
				item.text.setString("Infinite Apples: " + std::string(isInfiniteApples ? "On" : "Off"));
			};

		const bool isWithAcceleration = gameData.gameModeBitMask & static_cast<uint32_t>(GameOptions::WithAcceleration);

		MenuItem optionsWithAccelerationItem;
		setTextData(optionsWithAccelerationItem.text, "With Acceleration: " + std::string(isWithAcceleration ? "On" : "Off"), gameData.resourceData.font, 24);
		optionsWithAccelerationItem.onPressCallback = [this](MenuItem& item)
			{
				gameData.gameModeBitMask ^= static_cast<uint32_t>(GameOptions::WithAcceleration);

				bool isWithAcceleration = gameData.gameModeBitMask & static_cast<uint32_t>(GameOptions::WithAcceleration);
				item.text.setString("With Acceleration: " + std::string(isWithAcceleration ? "On" : "Off"));
			};

		MenuItem options;
		setTextData(options.text, "Options", gameData.resourceData.font, 24);
		setTextColorData(options.hintText, "Options", gameData.resourceData.font, 48, sf::Color::Red);
		setChildrenData(options, Orientation::Vertical, Alignment::Middle, 10.f);
		options.childrens.push_back(optionsInfiniteApplesItem);
		options.childrens.push_back(optionsWithAccelerationItem);

		MenuItem recordsItem;
		setTextData(recordsItem.text, "Records", gameData.resourceData.font, 24);
		recordsItem.onPressCallback = [this](MenuItem& item)
			{
				gameStateMachine->SwitchCurrentStateTo(new LeaderBoardState(gameData));
			};

		MenuItem yesItem;
		setTextData(yesItem.text, "Yes", gameData.resourceData.font, 24);
		yesItem.onPressCallback = [](MenuItem& item)
			{
			};

		MenuItem noItem;
		setTextData(noItem.text, "No", gameData.resourceData.font, 24);
		noItem.onPressCallback = [this](MenuItem& item)
			{
				menu->GoBack();
			};

		MenuItem exitGameItem;
		setTextData(exitGameItem.text, "Exit Game", gameData.resourceData.font, 24);
		setTextColorData(exitGameItem.hintText, "Are you sure?", gameData.resourceData.font, 48, sf::Color::Red);
		setChildrenData(exitGameItem, Orientation::Horizontal, Alignment::Middle, 10.f);
		exitGameItem.childrens.push_back(yesItem);
		exitGameItem.childrens.push_back(noItem);

		MenuItem mainMenu;
		setTextColorData(mainMenu.hintText, TITLE_OF_THE_WINDOW, gameData.resourceData.font, 48, sf::Color::Red);
		setChildrenData(mainMenu, Orientation::Vertical, Alignment::Middle, 10.f);
		mainMenu.childrens.push_back(startGame);
		mainMenu.childrens.push_back(options);
		mainMenu.childrens.push_back(recordsItem);
		mainMenu.childrens.push_back(exitGameItem);

		menu->Initialization(mainMenu);
	}

	void MainMenuState::Update(float deltaTime, sf::RenderWindow& window)
	{
	}

	std::string MainMenuState::GetDifficultyName()
	{
		std::string difficulty = "";

		if (gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Easy))
		{
			difficulty = "Easy";
		}
		else if (gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Medium))
		{
			difficulty = "Medium";
		}
		else if (gameData.gameDifficultyMask & static_cast<uint32_t>(GameDifficulty::Hard))
		{
			difficulty = "Hard";
		}

		return difficulty;
	}
}
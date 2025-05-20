#pragma once
#include <functional>
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	enum class Orientation
	{
		Horizontal,
		Vertical
	};

	enum class Alignment
	{
		Min, // Left or Top
		Middle,
		Max // Right or Bottom
	};

	struct MenuItem
	{
		sf::Text text;
		sf::Text hintText; // Visible when child item is selected
		Orientation childrenOrientation = Orientation::Vertical;
		Alignment childrenAlignment = Alignment::Min;
		float childrenSpacing = 0.f;

		bool isEnabled = true;
		sf::Color selectedColor = sf::Color::Yellow;
		sf::Color deselectedColor = sf::Color::White;

		std::vector<MenuItem> childrens;

		std::function<void(MenuItem& item)> onPressCallback;

		MenuItem* parent = nullptr;
	};

	class Text
	{
	};

	void DrawTextList(sf::RenderWindow& window, const std::vector<sf::Text*>& items, float spacing, Orientation orientation, Alignment alignment, const sf::Vector2f& position, const sf::Vector2f& origin);
	void SetTextData(sf::Text& text, const sf::Font& font, unsigned int size, const sf::Color color);
}
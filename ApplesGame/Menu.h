#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"

namespace ApplesGame
{
	class Menu
	{
	private:
		MenuItem rootItem;
		MenuItem* selectedItem = nullptr;
	public:
		MenuItem& GetCurrentContext();
		void Draw(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f origin);
		void GoBack();
		void Initialization(const MenuItem& item);
		void PressOnSelectedItem();
		void SwitchToNextMenuItem();
		void SwitchToPreviousMenuItem();
	private:
		void InitMenuItem(MenuItem& item);
		void SelectMenuItem(MenuItem& item);
	};
}
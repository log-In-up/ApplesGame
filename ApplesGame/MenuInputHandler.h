#pragma once
#include "Game.h"

namespace ApplesGame
{
	class MenuInputHandler
	{
	private:
		GameData& gameData;
	public:
		MenuInputHandler(GameData& gameData);
		void Update();
	};
}
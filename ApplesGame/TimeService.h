#pragma once

namespace ApplesGame
{
	class TimeService
	{
	public:
		TimeService();
		float GetDeltaTime();
		void Initialization();
	};
}
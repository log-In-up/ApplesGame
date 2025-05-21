#pragma once

namespace ApplesGame
{
	const float ZERO_DELTA_TIME = 0.f;

	class TimeService
	{
	public:
		TimeService();
		float GetDeltaTime();
		void Initialization();
	};

	bool TimeIsPaused();
	void SetPause(bool value);
}
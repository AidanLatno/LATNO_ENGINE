#pragma once
#include "Component.h"
namespace Latno
{
	class Timer
	{
	private:
		std::chrono::steady_clock::time_point StartTime;
		std::chrono::steady_clock::time_point EndTime;
		std::chrono::steady_clock::time_point LastLap;

	public:
		Timer();

		~Timer();

		void Finish();
		void Reset();
		double GetTime();
		double Lap();
	};
}
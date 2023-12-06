#pragma once
#include "AudioManager.h"
namespace Latno
{
	/*
	* Class Name: Timer
	* Purpose: Counts time from initialization for debug (Would not recommend using for in-game timers but it could work)
	* 
	* Constructor: Starts the timer immediately
	* 
	* Destructor: Calls Finish()
	* 
	* Methods:
	*	Finish()
	*		- Stops timer
	*	Reset()
	*		- Resets timer and starts immediately after.
	*	GetTime()
	*		- Gets current time.
	*	Lap()
	*		- Returns time from the last lap (Or start time) to current time.
	*/
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
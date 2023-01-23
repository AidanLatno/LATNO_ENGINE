#include "../declarations/Timer.h"

Timer::Timer()
{
	StartTime = std::chrono::steady_clock::now();
	LastLap = std::chrono::steady_clock::now();
}

Timer::~Timer()
{
	Finish();
}

void Timer::Finish()
{
	using namespace std::chrono;
	EndTime = steady_clock::now();
	auto Duration = duration_cast<microseconds>(EndTime - StartTime);
	double Seconds = (double)(Duration.count() / 1000000.0);
}
void Timer::Reset()
{
	StartTime = std::chrono::steady_clock::now();
	LastLap = std::chrono::steady_clock::now();
}
double Timer::GetTime()
{
	using namespace std::chrono;
	auto Duration = duration_cast<microseconds>(steady_clock::now() - StartTime);
	return (double)(Duration.count() / 1000000.0);
}
double Timer::Lap()
{
	using namespace std::chrono;
	auto Duration = duration_cast<microseconds>(steady_clock::now() - LastLap);
	LastLap = steady_clock::now();
	return (double)(Duration.count() / 1000000.0);
}
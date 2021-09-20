#ifndef TIMING_H
#define TIMING_H

#include <iostream>
#include <chrono>

class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto m_EndTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(m_EndTimepoint).time_since_epoch().count();

		auto duration = end - start;

		std::cout << duration << " ms" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

#endif

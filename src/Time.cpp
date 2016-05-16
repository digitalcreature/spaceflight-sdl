#include "Time.hpp"

using namespace std::chrono;

steady_clock::time_point Time::startTime;
steady_clock::time_point Time::lastTime;
duration<float> Time::delta;

void Time::init() {
	startTime = steady_clock::now();
	lastTime = startTime;
}

void Time::update() {
	steady_clock::time_point time = steady_clock::now();
	delta = (time - lastTime);
	lastTime = time;
}

float Time::getDelta() {
	return delta.count();
}


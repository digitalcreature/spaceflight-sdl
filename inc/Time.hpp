#pragma once

#include <SDL.h>
#include <chrono>

#include "Application.hpp"

class Time {
	friend class Application;
	private:
		static std::chrono::steady_clock::time_point startTime;
		static std::chrono::steady_clock::time_point lastTime;
		static std::chrono::duration<float> delta;
		static void init();
		static void update();
	public:
		static float getDelta();
		static float getTime();
};

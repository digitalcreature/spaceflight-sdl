#pragma once

#include <SDL.h>
#include <iostream>

#include "State.hpp"
#include "Window.hpp"

class Application {
	private:
		static Window *window;
		static bool quitRequested;
		static State *state;
	public:
		static void init(std::string);
		static void run();
		static void close();
		static void quit();
		static void setState(State *);
};

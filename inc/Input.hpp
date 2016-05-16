#pragma once

#include <SDL.h>
#include <SDL_events.h>
#include <unordered_set>

#include "Application.hpp"

class Input {
	friend class Application;
	private:
		static const Uint8* keyBoardState;
		static std::unordered_set<SDL_Scancode> keysPressed;
		static std::unordered_set<SDL_Scancode> keysReleased;
		static void init();
		static void update();
	public:
		static bool keyIsDown(SDL_Scancode);
		static bool keyWasPressed(SDL_Scancode);
		static bool keyWasReleased(SDL_Scancode);
};

#pragma once

#include <SDL.h>
#include <iostream>

#include "State.hpp"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Application {
	private:
		static SDL_Window *window;
		static SDL_Surface *screen;
		static bool quitRequested;
		static State *state;
	public:
		static void init(std::string);
		static void run();
		static void exit();
		static void quit();
		static void setState(State *);
		static SDL_Window* getWindow() {
			return window;
		}
};

class ApplicationException : public std::exception {
	private:
		const char* message;
		const char* sdlError;
		const bool reportSDLError;
	public:
		ApplicationException(char* message, bool reportSDLError = true);
		virtual const char* what();
	friend std::ostream& operator<<(std::ostream& out, ApplicationException e);
};

std::ostream& operator<<(std::ostream& out, ApplicationException e);

#pragma once

#include <SDL.h>
#include <string>

class Window {
	friend class Application;
	private:
		SDL_Window *sdl_window;
		SDL_GLContext sdl_glcontext;
		unsigned int width;
		unsigned int height;
		void swapBuffers();
	public:
		Window(std::string, unsigned int width = 640, unsigned int height = 480);
		~Window();
};
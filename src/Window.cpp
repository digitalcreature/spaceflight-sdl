#include "Window.hpp"
#include "SDLException.hpp"

Window::Window(std::string title, unsigned int width, unsigned int height)
	: width(width), height(height) {
	sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!sdl_window) throw SDLException("Could not create SDL window!");
	sdl_glcontext = SDL_GL_CreateContext(sdl_window);
	if (!sdl_glcontext) throw SDLException("Could not initialize OpenGL context!");
}

Window::~Window() {
	if (sdl_window) SDL_DestroyWindow(sdl_window);
	if (sdl_glcontext) SDL_GL_DeleteContext(sdl_glcontext);
}

void Window::swapBuffers() {
	SDL_GL_SwapWindow(sdl_window);
}
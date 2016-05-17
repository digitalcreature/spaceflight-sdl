#pragma once

#include <exception>
#include <iostream>

#include <SDL_opengl.h>

class SDLException : public std::exception {
	private:
		const char* message;
		const char* sdlError;
		const bool reportSDLError;
	public:
		SDLException(char* message, bool reportSDLError = true);
		virtual const char* what() { return "SDL Exception"; }
		friend std::ostream& operator<<(std::ostream& out, SDLException& e);
};

std::ostream& operator<<(std::ostream& out, SDLException& e);

class GLEWException : public std::exception {
	private:
		const char* message;
		const char* glewError;
		const bool reportGLEWError;
	public:
		GLEWException(char* message, GLenum error ,bool reportGLEWError = true);
		virtual const char* what() { return "GLEW Exception"; }
	friend std::ostream& operator<<(std::ostream& out, GLEWException& e);
};

std::ostream& operator<<(std::ostream& out, GLEWException& e);
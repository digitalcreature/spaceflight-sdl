#pragma once

#include "LibraryException.hpp"

#include <GL\glew.h>
#include <SDL_opengl.h>

class GLEWException : public LibraryException {
public:
	GLEWException(const char *message, const GLenum error , const bool reportGLEWError = true)
		: LibraryException(message, (const char *) glewGetErrorString(error), reportGLEWError) {}
	virtual const char* what() { return "GLEW Exception"; }
};
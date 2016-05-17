#pragma once

#include <SDL.h>

#include "LibraryException.hpp"

class SDLException : public LibraryException {
public:
	SDLException(const char *message, const bool reportSDLError = true)
		: LibraryException(message, SDL_GetError(), reportSDLError) {}
	virtual const char* what() { return "SDL Exception"; }
};
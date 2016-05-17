#include "exceptions.hpp"
#include <SDL.h>

SDLException::SDLException(char* message, bool reportSDLError)
	: message(message), sdlError(SDL_GetError()), reportSDLError(reportSDLError) {}

std::ostream& operator<<(std::ostream& out, SDLException& e) {
	out << "SDL Exception: " << e.message;
	if (e.reportSDLError) out << " [" << e.sdlError << "]";
	return out;
}

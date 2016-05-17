#include <GL\glew.h>
#include "exceptions.hpp"

GLEWException::GLEWException(char* message, GLenum error, bool reportGLEWError)
	: message(message), glewError((const char *) glewGetErrorString(error)), reportGLEWError(reportGLEWError) {}

std::ostream& operator<<(std::ostream& out, GLEWException& e) {
	out << "GLEW Exception: " << e.message;
	if (e.reportGLEWError)
		out << " [" << e.glewError << "]";
	return out;
}
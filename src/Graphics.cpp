#include "GL.hpp"

#include "Graphics.hpp"
#include "Application.hpp"
#include "math.hpp"
#include "GLEWException.hpp"

#include "cml\vector.h"

SDL_GLContext Graphics::context;

void Graphics::init() {
	//set gl attributes
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	//initialize GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK) throw GLEWException("Error initializing GLEW!", error);
	//enable vsync
	SDL_GL_SetSwapInterval(1);

	glEnableClientState(GL_VERTEX_ARRAY);
}

void Graphics::clear(Color color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

std::ostream& operator<< (std::ostream& out, Color& color) {
	out << "["
		<< (int) (color.r * 255) << ", "
		<< (int) (color.g * 255) << ", "
		<< (int) (color.b * 255) << ", "
		<< (int) (color.a * 255)
		<< "]";
	return out;
}

Color Color::operator+(Color& that) {
	return Color(
		this->r + that.r,
		this->g + that.g,
		this->b + that.b,
		this->a + that.a
	);
}

Color Color::operator-(Color& that) {
	return Color(
		this->r - that.r,
		this->g - that.g,
		this->b - that.b,
		this->a - that.a
	);
}

Color Color::operator*(Color& that) {
	return Color(
		this->r * that.r,
		this->g * that.g,
		this->b * that.b,
		this->a * that.a
	);
}

Color Color::operator*(float scale) {
	return Color(
		this->r * scale,
		this->g * scale,
		this->b * scale,
		this->a * scale
	);
}

Color Color::random(float a) {
	return Color(math::random(), math::random(), math::random(), a);
}

const Color Color::black(0, 0, 0, 1);
const Color Color::white(1, 1, 1, 1);
const Color Color::clear(0, 0, 0, 0);
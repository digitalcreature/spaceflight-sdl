#pragma once

#include <SDL.h>

#include "GL.hpp"
#include "Application.hpp"

typedef GLuint guint;
typedef GLfloat gfloat;

class Color {
	public:
		float r;
		float g;
		float b;
		float a;
		Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
		Color(float r, float g, float b) : Color(r, g, b, 1) {}
		Color operator+(Color&);
		Color operator-(Color&);
		Color operator*(Color&);
		Color operator*(float);
		static Color random(float a = 1);

		//color constants
		static const Color black;
		static const Color white;
		static const Color clear;
};

std::ostream& operator<< (std::ostream&, Color&);

class Graphics {
	friend class Application;
private:
	static SDL_GLContext context;
	static void init();
public:
	static void clear(Color color = Color(0, 0, 0));
};
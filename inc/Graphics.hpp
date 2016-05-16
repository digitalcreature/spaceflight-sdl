#pragma once

#include <SDL.h>

#include "Application.hpp"

class Color;

class Graphics {
	friend class Application;
	private:
		static SDL_Renderer* renderer;
		static void init();
		static void present();
	public:
		static void clear();
		static void clear(Color);
};

class Color {
	public:
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 a;
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : r(r), g(g), b(b), a(a) {}
		Color(Uint8 r, Uint8 g, Uint8 b) : Color(r, g, b, 255) {}
};
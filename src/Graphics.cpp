#include "Graphics.hpp"
#include "Application.hpp"

SDL_Renderer *Graphics::renderer = NULL;

void Graphics::init() {
	renderer = SDL_CreateRenderer(Application::getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) throw ApplicationException("Could not initialize renderer!");
}

void Graphics::clear() {
	SDL_RenderClear(renderer);
}

void Graphics::clear(Color color) {
	clear();
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	const SDL_Rect rect{ 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	SDL_RenderFillRect(renderer, &rect);
}

void Graphics::present() {
	SDL_RenderPresent(renderer);
}

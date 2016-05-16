#include "Input.hpp"

const Uint8* Input::keyBoardState = NULL;
std::unordered_set<SDL_Scancode> Input::keysPressed;
std::unordered_set<SDL_Scancode> Input::keysReleased;

void Input::init() {
}

void Input::update() {
	SDL_PumpEvents();
	keyBoardState = SDL_GetKeyboardState(NULL);
	keysPressed.clear();
	keysReleased.clear();
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_KEYDOWN:
				if (!e.key.repeat) {
					keysPressed.insert(e.key.keysym.scancode);
				}
				break;
			case SDL_KEYUP:
				keysReleased.insert(e.key.keysym.scancode);
				break;
			case SDL_QUIT:
				Application::quit();
				break;
		}
	}
}

bool Input::keyIsDown(SDL_Scancode code) {
	return keyBoardState[code] != 0;
}

bool Input::keyWasPressed(SDL_Scancode code) {
	return keysPressed.count(code) != 0;
}

bool Input::keyWasReleased(SDL_Scancode code) {
	return keysReleased.count(code) != 0;
}

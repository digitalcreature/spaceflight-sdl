
#include "Application.hpp"
#include "Input.hpp"
#include "Time.hpp"
#include "Graphics.hpp"

SDL_Window* Application::window;
SDL_Surface* Application::screen;
bool Application::quitRequested = false;
State *Application::state = NULL;

void Application::init(std::string title) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) throw ApplicationException("Could not initialize application!");
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) throw ApplicationException("Could not create application window!");
	screen = SDL_GetWindowSurface(window);
	Time::init();
	Input::init();
	Graphics::init();
}

void Application::exit() {
	if (window) SDL_DestroyWindow(window);
	SDL_Quit();
}

void Application::quit() {
	quitRequested = true;
}

void Application::run() {
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_UpdateWindowSurface(window);
	while (!quitRequested) {
		Time::update();
		Input::update();
		if (state) {
			state->update(Time::getDelta());
			Graphics::clear();
			state->render();
			Graphics::present();
		}
	}
}

void Application::setState(State *state) {
	Application::state = state;
}

ApplicationException::ApplicationException(char* message, bool reportSDLError)
	: message(message), sdlError(SDL_GetError()), reportSDLError(reportSDLError) {}

const char* ApplicationException::what() {
	return "Application Exception";
}

std::ostream& operator<<(std::ostream& out, ApplicationException e) {
	out << "Application Exception: " << e.message;
	if (e.reportSDLError) out << " [" << e.sdlError << "]";
	return out;
}

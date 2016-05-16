#include <iostream>
#include <cstdlib>

#include "Application.hpp"
#include "State.hpp"
#include "Time.hpp"
#include "Graphics.hpp"

class GameState : public State {
	public:
		virtual void update(float dt) {
			printf("delta: %f fps: %d\n", dt, (unsigned int) (1 / dt));
		}

		virtual void render() {
			Graphics::clear(Color(rand() % 256, rand() % 256, rand() % 256));
		}
};

int main(int argc, char *argv[]) {
	try {
		Application::init("spaceflight");
		GameState state;
		Application::setState(&state);
		Application::run();
		Application::exit();
	}
	catch (ApplicationException& e) {
		std::cout << e << std::endl;
	}
	return 0;
}

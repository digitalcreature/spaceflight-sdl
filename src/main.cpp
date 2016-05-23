#include <iostream>
#include <cstdlib>

#include "Application.hpp"
#include "State.hpp"
#include "Time.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "math.hpp"
#include "LibraryException.hpp"
#include "Mesh.hpp"
#include "ShaderProgram.hpp"

class GameState : public State {
	private:
		Color color;
		Color startColor;
		Color endColor;
		float t;
		float fadeTime;
		Mesh mesh;
		ShaderProgram shader;
	public:
		GameState()
			: startColor(0, 0, 0), endColor(Color::random()), color(Color::random()),
			t(0), fadeTime(0.5f),
			mesh(), shader("shader/test") {
			puts(shader.error() ? "shader loading failed" : "shader loading succeeded");
			//initialize verts
			mesh.setVertCount(4);
			mesh.vert(0) = vec3(-0.5f, -0.5f, 0.0f);
			mesh.vert(1) = vec3(0.5f, -0.5f, 0.0f);
			mesh.vert(2) = vec3(0.5f, 0.5f, 0.0f);
			mesh.vert(3) = vec3(-0.5f, 0.5f, 0.0f);
			//initialize indices
			mesh.setIndexCount(6);
			mesh.index(0) = 0;
			mesh.index(1) = 1;
			mesh.index(2) = 2;
			mesh.index(3) = 0;
			mesh.index(4) = 2;
			mesh.index(5) = 3;
			//update VBOs and IBO
			mesh.update();
		}
			
		virtual void onenter() {
			math::srandomt();
		}

		virtual void update(float dt) {
			t += dt / fadeTime;
			t = math::clamp(t);
			if (t == 1) {
				fadeTime *= -1;
				t = 1;
				startColor = Color::random();
			}
			if (t == 0) {
				fadeTime *= -1;
				t = 0;
				endColor = Color::random();
			}
			color = math::lerp(startColor, endColor, t);
			if (Input::keyWasPressed(SDL_SCANCODE_SPACE)) {
				Application::quit();
			}
			float time = Time::getTime();
			mesh.vert(0)[0] = cos(time);
			mesh.vert(0)[1] = sin(time);
			mesh.update();
			//print framerate
			//printf("%dFPS\n",(int) (1 /dt));
		}

		virtual void render() {
			Graphics::clear(color);
			shader.use();
			mesh.render();
		}
};

int main(int argc, char *argv[]) {
	try {
		Application::init("spaceflight");
		GameState state;
		Application::setState(&state);
		Application::run();
		Application::close();
	}
	catch (LibraryException& e) {
		std::cout << e << std::endl;
		return -1;
	}
	return 0;
}

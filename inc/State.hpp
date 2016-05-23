#pragma once

class State {
	public:
		virtual void onenter() {}
		virtual void onexit() {}
		virtual void update(float) = 0;
		virtual void render() = 0;
};

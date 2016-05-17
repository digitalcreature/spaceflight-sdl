#pragma once

#include <math.h>

namespace math {

	float random();
	void srandomt();

	template<class T>
	T clamp(T n, T min = T(0), T max = T(1)) {
		if (n > max) return max;
		if (n < min) return min;
		return n;
	}

	template<class T>
	T lerp(T n, T m, float t) {
		t = clamp(t);
		return n + ((m - n) * t);
	}
}
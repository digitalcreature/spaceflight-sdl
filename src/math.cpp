#include "math.hpp"
#include <stdlib.h>
#include <time.h>

float math::random() {
	return (float) rand() / RAND_MAX;
}

void math::srandomt() {
	srand((unsigned int) time(NULL));
}
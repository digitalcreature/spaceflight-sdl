#include <iostream>
#include <exception>

#include "vec.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	vec3d a(6, 8, 0);
	vec3<string> b("hello", "world", "");
	cout << a << endl;
	cout << b << endl;
	return 0;
}

#pragma once

#include <cstdlib>
#include <cstdarg>
#include <cmath>

#include <ostream>
#include <exception>

using namespace std;

//vector component iteration
#define components size_t i = 0; i < O; i ++

template <class T, size_t O>
class vec {

	private:
		T v[O];

	public:
		//constructors (only initialize up to first 4 components)
		vec() {}
		vec(T x) : vec() { this->x() = x; }
		vec(T x, T y) : vec(x) { this->y() = y; }
		vec(T x, T y, T z) : vec(x, y) { this->z() = z; }
		vec(T x, T y, T z, T w) : vec(x, y, z) { this->w() = w; }

		//component accessors (accessing nonexistent components is undefined)
		T& operator[](size_t i) { return v[i]; }
		T& x() { return v[0]; }
		T& y() { return v[1]; }
		T& z() { return v[2]; }
		T& w() { return v[3]; }

		//zero vector constant (cached statically after first initialized)
		static vec<T, O> zero() {
			static vec<T, O> zero;
			static bool init = false;
			if (!init) {
				init = true;
				for (components) {
					zero[i] = T(0);
				}
			}
			return zero;
		}

		//one vector constant (cached statically after first initialized)
		static vec<T, O> one() {
			static vec<T, O> one;
			static bool init = false;
			if (!init) {
				init = true;
				for (components) {
					one[i] = T(1);
				}
			}
			return one;
		}

		//orthoganal vector constants (undefined if vector doesnt have enough dimensions)
		//left hand rule: x-right, y-up, z-forward (just like unity3d)
		static vec<T, O> right() { vec<T, O> vec = zero(); vec.x() = T(1); return vec; }
		static vec<T, O> left() { vec<T, O> vec = zero(); vec.x() = T(-1); return vec; }
		static vec<T, O> up() { vec<T, O> vec = zero(); vec.y() = T(1); return vec; }
		static vec<T, O> down() { vec<T, O> vec = zero(); vec.y() = T(-1); return vec; }
		static vec<T, O> forward() { vec<T, O> vec = zero(); vec.z() = T(1); return vec; }
		static vec<T, O> backward() { vec<T, O> vec = zero(); vec.z() = T(-1); return vec; }

		//get square euclidean length
		T len2() {
			T len2 = T();
			for (components) {
				len2 += v[i] * v[i];
			}
			return len2;
		}

		//get euclidean length
		T len() {
			return (T) sqrt((double) this->len2());
		}

		//get square euclidean distance to vector
		T dist2(vec<T, O> that) {
			return (that - *this).len2();
		}

		//get euclidean distance to vector
		T dist(vec<T, O> that) {
			return (that - *this).len();
		}

		//gret order of vector (dimensions)
		size_t order() {
			return O;
		}

		//addition
		vec<T, O> operator+(vec<T, O>& that) {
			vec<T, O> vec;
			for (components) {
				vec[i] = v[i] + that[i];
			}
			return vec;
		}

		//subtraction
		vec<T, O> operator-(vec<T, O>& that) {
			vec<T, O> vec;
			for (components) {
				vec[i] = v[i] - that[i];
			}
			return vec;
		}

		//unary inversion
		vec<T, O> operator-() {
			return *this * -1;
		}

		//scalar multiplication
		template<class S>
		vec<T, O> operator*(S scale) {
			vec<T, O> vec = *this;
			for (components) {
				vec[i] *= scale;
			}
			return vec;
		}

		//scalar division
		template<class S>
		vec<T, O> operator/(S scale) {
			vec<T, O> vec = *this;
			for (components) {
				vec[i] /= scale;
			}
			return vec;
		}

		//dot product
		T operator*(vec<T, O>& that) {
			T dot;
			for (components) {
				dot += v[i] * that[i];
			}
			return dot;
		}

		//cross product (only available for 3 dimensional vectors; undefined behaviour for lower orders)
		vec<T, O> operator^(vec<T, O>& that) {
			vec<T, O> vec;
			vec.x() = (this->y() * that.z()) - (this->z() * that.y());
			vec.y() = (this->z() * that.x()) - (this->x() * that.z());
			vec.z() = (this->x() * that.y()) - (this->y() * that.x());
			return vec;
		}


};

//scalar multiplication inverse order
template<class T, size_t O>
vec<T, O> operator* (T scale, vec<T, O> vec) {
	return vec * scale;
}

//print vector to a stream
template <class T, size_t O>
ostream& operator<<(ostream& stream, vec<T, O> vec) {
	stream << "<";
	for (components) {
		if (i > 0) stream << ", ";
		stream << vec[i];
	}
	stream << ">";
	return stream;
}

template<class T>
using vec2 = vec<T, 2>;
template<class T>
using vec3 = vec<T, 3>;
template<class T>
using vec4 = vec<T, 4>;

template<size_t O>
using vecf = vec<float, O>;
using vec2f = vecf<2>;
using vec3f = vecf<3>;
using vec4f = vecf<4>;

template<size_t O>
using vecd = vec<double, O>;
using vec2d = vecd<2>;
using vec3d = vecd<3>;
using vec4d = vecd<4>;

template<size_t O>
using veci = vec<int, O>;
using vec2i = veci<2>;
using vec3i = veci<3>;
using vec4i = veci<4>;

template<size_t O>
using vecu = vec<unsigned int, O>;
using vec2u = vecu<2>;
using vec3u = vecu<3>;
using vec4u = vecu<4>;

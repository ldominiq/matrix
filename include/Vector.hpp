#ifndef Vector_hpp
#define Vector_hpp

#include <vector>
#include <initializer_list>
#include <cassert>

/*
	If the mathematical operation is nonsensical (ie, summing a vector and a scalar, or vectors of different sizes),
	the result is undefined.
*/

template <typename K>
struct Vector {
	std::vector<K> data;

	Vector() = default;
	Vector(std::initializer_list<K> list) : data(list) {}

	size_t size() const {
		return data.size();
	}

	K& operator[](size_t i) {
		return data[i];
	}
	const K& operator[](size_t i) const {
		return data[i];
	}

	Vector<K>& operator+=(const Vector<K>& v) {
		assert(size() == v.size());
		for (size_t i = 0; i < size(); ++i) {
			data[i] += v[i];
		}
		return *this;
	}

	Vector<K>& operator-=(const Vector<K>& v) {
		assert(size() == v.size());
		for (size_t i = 0; i < size(); ++i) {
			data[i] -= v[i];
		}
		return *this;
	}

	Vector<K>& operator*=(const K a) {
		for (size_t i = 0; i < size(); ++i) {
			data[i] *= a;
		}
		return *this;
	}

	// Compute the addiction of 2 vectors
	void add(Vector<K>& v) { *this += v; }

	// Compute the substraction of a vector by another
	void sub(Vector<K>& v) { *this -= v; }

	// Compute the scaling of a vector by s scalar
	void scl(K a) { *this *= a; }

	// Print the vector on the standard output
	void print() const {
		std::cout << '[';
		for (size_t i = 0; i < size(); ++i)
			std::cout << data[i] << (i + 1 < size() ? ", " : "");
		std::cout << ']';
	}

	// TODO: • A function to reshape a vector into a matrix, and vice-versa.

};

#endif
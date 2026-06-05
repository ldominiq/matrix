#ifndef Vector_hpp
#define Vector_hpp

#include <vector>
#include <initializer_list>
#include <cassert>
#include <cmath>
#include <iostream>

/*
	If the mathematical operation is nonsensical (ie, summing a vector and a scalar, or vectors of different sizes),
	the result is undefined.
*/

template <typename K>
struct Vector {
	std::vector<K> data;

	Vector() = default;
	Vector(std::initializer_list<K> list) : data(list) {}
	Vector(size_t n) {
		data.assign(n, K{});
	}

	size_t size() const {
		return data.size();
	}

	K&			operator[](size_t i) {
		return data[i];
	}
	const K&	operator[](size_t i) const {
		return data[i];
	}

	// Time complexity	O(n)
	// Space complexity O(1)
	Vector<K>&	operator+=(const Vector<K>& v) {
		assert(size() == v.size());
		for (size_t i = 0; i < size(); ++i) {
			data[i] += v[i];
		}
		return *this;
	}

	// Time complexity	O(n)
	// Space complexity O(1)
	Vector<K>&	operator-=(const Vector<K>& v) {
		assert(size() == v.size());
		for (size_t i = 0; i < size(); ++i) {
			data[i] -= v[i];
		}
		return *this;
	}

	// Time complexity	O(n)
	// Space complexity O(1)
	Vector<K>&	operator*=(const K a) {
		for (size_t i = 0; i < size(); ++i) {
			data[i] *= a;
		}
		return *this;
	}

	// Compute the addiction of 2 vectors
	void add(Vector<K>& v) { *this += v; }

	// Compute the substraction of a vector by another
	void sub(Vector<K>& v) { *this -= v; }

	// Compute the scaling of a vector by a scalar
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

// Time complexity	O(n)
// Space complexity O(n)
// Compute a linear combination of the vectors provided using the correspondign scalar coefficients
// result = λ₁·u₁ + λ₂·u₂ + λ₃·u₃
template <typename K>
Vector<K> linear_combination(const std::vector<Vector<K>>& u, const std::vector<K>& coefs) {
	assert(u.size() == coefs.size());
	assert(!u.empty());

	size_t dim = u[0].size();
	Vector<K> result(dim); // zero filled vector of diemsion dim

	for (size_t i = 0; i < dim ; ++i) {				// i = which coordinate of the result
		for (size_t j = 0; j < u.size() ; ++j) {	// j = which vector in the list
			result[i] = std::fma(coefs[j], u[j][i], result[i]);
		}
	}
	return result;
}

#endif
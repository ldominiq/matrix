#ifndef Vector_hpp
#define Vector_hpp

#include <vector>
#include <initializer_list>
#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>

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
	void add(const Vector<K>& v) { *this += v; }

	// Compute the substraction of a vector by another
	void sub(const Vector<K>& v) { *this -= v; }

	// Compute the scaling of a vector by a scalar
	void scl(K a) { *this *= a; }

	// Print the vector on the standard output
	void print() const {
		std::cout << '[';
		for (size_t i = 0; i < size(); ++i)
			std::cout << data[i] << (i + 1 < size() ? ", " : "");
		std::cout << ']';
	}

	// Compute the dot product of u*v
	K dot(const Vector<K>& v) const {
		assert(size() == v.size());
		K result = K{};
		for (size_t i = 0; i < size(); ++i) {
			result += data[i] * v[i];
		}
		return result;
	}

	K abs_val(K x) const {
		return x < K(0) ? -x : x;
	}

	// Manhattan norm
	/*
		Measures the distance by summing the absolute differences of the vector's components.
		It is like walking city blocks where you can only move horizontally and vertically.
	*/
	float norm_1() const {
		float result = 0.0f;
		for (size_t i = 0; i < size(); ++i) {
			result += abs_val(data[i]);
		}
		return result; 
	}

	// Euclidean norm
	// Measures the shortest straight-line distance, as if a bird could fly directly to the destination.
	float norm() const {
		float result = 0.0f;
		for (size_t i = 0; i < size(); ++i) {
			result = std::fma(data[i], data[i], result);
		}
		return std::pow(result, 0.5); // pow 0.5 -> sqrt
	}

	// supremum norm
	// Evaluates the vector by finding its single component with the largest absolute magnitude (the "max" deviation).
	float norm_inf() const {
		float result = 0.0f;
		for (size_t i = 0; i < size(); i++) {
			result = std::max(result, abs_val(data[i]));
		}
		return result;
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

// compute cos(u, v), the cosine of the angle between the two vectors u and v.
// Cosine(θ)=A⋅B / ‖A‖ ‖B‖
template <typename K>
float angle_cos(const Vector<K>& u, const Vector<K>& v) {
	assert(u.size() == v.size());

	// calc dot product u⋅v
	K result = u.dot(v);

	// calc magnitude ‖A‖ ‖B‖
	float mag_A = u.norm();
	float mag_B = v.norm();

	// divide dot by miltiplied magnitudes
	result = result / (mag_A * mag_B);

	return result;
}

// computes the cross product u × v.
template <typename K>
Vector<K> cross_product(const Vector<K>& u, const Vector<K>& v) {
	assert(u.size() == 3 && v.size() == 3);
	Vector<K> result(3);
	result[0] = u[1] * v[2] - u[2] * v[1];
	result[1] = u[2] * v[0] - u[0] * v[2];
	result[2] = u[0] * v[1] - u[1] * v[0];

	return result;
}

#endif
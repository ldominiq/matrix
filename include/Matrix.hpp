#ifndef Matrix_hpp
#define Matrix_hpp

#include <vector>
#include <initializer_list>
#include <cassert>
#include <iostream>

/*
	If the mathematical operation is nonsensical (ie, summing a vector and a scalar, or vectors of different sizes),
	the result is undefined.
*/

template <typename K>
struct Matrix {

	std::vector<std::vector<K>> data;	// data[row][col]

	Matrix() = default;
	Matrix(std::initializer_list<std::initializer_list<K>> rows) {
		for (const auto& r : rows)
			data.emplace_back(r);
	}
	Matrix(size_t rows, size_t cols) {
		data.assign(rows, std::vector<K>(cols, K{})); // create a zeroed matrix of x rows and x cols
	}

	size_t	rows() const { return data.size(); }
	size_t	cols() const { return data.empty() ? 0 : data[0].size(); }
	bool	is_square() const { return rows() == cols(); }

	// element access
	K&			operator()(size_t i, size_t j)		{ return data[i][j]; }
	const K&	operator()(size_t i, size_t j) const	{ return data[i][j]; }


	// Time complexity	O(n*m)
	// Space complexity O(1)
	const Matrix<K>& operator+=(Matrix<K>& m) {
		assert(rows() == m.rows() && cols() == m.cols());
		for (size_t i = 0; i < rows(); ++i) {
			for (size_t j = 0; j < cols(); ++j) {
				data[i][j] += m(i, j);
			}
		}
		return *this;
	}

	// Time complexity	O(n*m)
	// Space complexity O(1)
	const Matrix<K>& operator-=(Matrix<K>& m) {
		assert(rows() == m.rows() && cols() == m.cols());
		for (size_t i = 0; i < rows(); ++i) {
			for (size_t j = 0; j < cols(); j++) {
				data[i][j] -= m(i, j);
			}
		}
		return *this;
	}

	// Time complexity	O(n*m)
	// Space complexity O(1)
	Matrix<K>&	operator*=(K a) {
		for (size_t i = 0; i < rows(); ++i) {
			for (size_t j = 0; j < cols(); ++j) {
				data[i][j] *= a;
			}
		}
		return *this;
	}

	void print() const {
		for (size_t i = 0; i < rows(); ++i) {
			std::cout << '[';
			for (size_t j = 0; j < cols(); j++) {
				K x = data[i][j];
				std::cout << x;
				if (j + 1 < cols()) std::cout << ", ";
			}
			std::cout << "]\n";
		}
	}

	// Compute the addiction of 2 matrices
	void add(Matrix<K>& m)	{ *this += m; }

	// Compute the substraction of a matrix by another
	void sub(Matrix<K>& m)	{ *this -= m; }

	// Compute the scaling of a matrix by a scalar
	void scl(K a)			{ *this *= a; }

	// compute Au (which returns a vector in Rm)
	// max time complexity O(nm)
	// max space complexity O(nm)
	Vector<K> mul_vec(const Vector<K> vec) {
		Vector<K> result(vec.size());

		for (size_t i = 0; i < vec.size(); ++i) {
			for (size_t j = 0; j < vec.size(); ++j) {
				result[i] += vec[j] * data[i][j];
			}
		}

		return result;
	}

	// compute AB (which returns a matrix in Rm×p)
	// max time complexity O(nmp)
	// max space complexity O(nm + mp + np)
	Matrix<K> mul_mat(const Matrix<K> mat) {

		size_t m = rows();
		size_t n = cols();
		size_t p = mat.cols();
		Matrix<K> result(m, p);

		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < p; ++j) {
				for (size_t k = 0; k < n; ++k) {
					// (*this)(i, k) -> element of A (the current matrix)  A[i][k]
					//     mat(k, j) -> element of B					   B[k][j]
					//	result(i, j) -> element of the result			   r[i][j]
					// 
					// fma(x, y , z) does x * y + z
					// result(i, j) = A[i][k] * B[k][j] + result(i, j)
					result(i, j) = std::fma((*this)(i, k), mat(k, j), result(i, j));
				}
			}
		}

		return result;
	}

	// TODO: • A function to reshape a vector into a matrix, and vice-versa.
};

#endif
#ifndef Matrix_hpp
#define Matrix_hpp

#include <vector>
#include <initializer_list>
#include <cassert>
#include <iostream>
#include <cmath> // for fma

#include "Vector.hpp"

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
	Matrix<K>& operator+=(const Matrix<K>& m) {
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
	Matrix<K>& operator-=(const Matrix<K>& m) {
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
	void add(const Matrix<K>& m)	{ *this += m; }

	// Compute the substraction of a matrix by another
	void sub(const Matrix<K>& m)	{ *this -= m; }

	// Compute the scaling of a matrix by a scalar
	void scl(K a)			{ *this *= a; }

	// compute Au (which returns a vector in Rm)
	// max time complexity O(nm)
	// max space complexity O(nm)
	Vector<K> mul_vec(const Vector<K>& vec) const {
		assert(cols() == vec.size());
		Vector<K> result(rows());

		for (size_t i = 0; i < rows(); ++i) {
			for (size_t j = 0; j < cols(); ++j) {
				result[i] = std::fma(data[i][j], vec[j], result[i]);
			}
		}

		return result;
	}

	// compute AB (which returns a matrix in Rm×p)
	// max time complexity O(nmp)
	// max space complexity O(nm + mp + np)
	Matrix<K> mul_mat(const Matrix<K>& mat) const {
		assert(cols() == mat.rows());

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

	// computes the trace of the given matrix
	// it will add the values on the diagonal of the matrix
	K trace() const {
		assert(is_square());
		K result = K{};

		for (size_t i = 0; i < cols(); ++i) {
			result += data[i][i];
		}

		return result;
	}

	// computes the transpose matrix of a given matrix
	// will swap the rows and cols of the matrix A is mxn -> result is nxm
	Matrix<K> transpose() const {
		Matrix<K> result(cols(), rows()); // we swap dimensions

		for (size_t i = 0; i < rows(); ++i) {
			for (size_t j = 0; j < cols(); ++j) {
				result(j, i) = data[i][j];
			}
		}

		return result;
	}

	// Computes the (reduced) row-echelon form of the given matrix. Gauss-Jordan elimination.
	// Time complexity  O(n^3)
	// Space complexity O(n^2) (the returned copy)
	Matrix<K> row_echelon() const {
		Matrix<K> result = *this;

		const size_t m = result.rows();
		const size_t n = result.cols();
		const K epsilon = static_cast<K>(1e-7);	// float pivots are never exactly 0 so we use an epsilon value

		auto abs_val = [](K x) { return x < K{} ? -x : x; };

		size_t pivot_row = 0;
		for (size_t col = 0; col < n && pivot_row < m; ++col) {

			// 1. partial pivoting: pick the row with the largest |value|
			//    in this column, at or below the current pivot row.
			size_t best = pivot_row;
			for (size_t i = pivot_row + 1; i < m; ++i) {
				if (abs_val(result(i, col)) > abs_val(result(best, col)))
					best = i;
			}

			// no usable pivot in this column -> move on without advancing row
			if (abs_val(result(best, col)) < epsilon)
				continue;

			// 2. bring the pivot row into position
			std::swap(result.data[pivot_row], result.data[best]);

			// 3. normalize the pivot row so the pivot becomes 1
			K pivot = result(pivot_row, col);
			for (size_t j = 0; j < n; ++j)
				result(pivot_row, j) /= pivot;

			// 4. eliminate this column from every other row (above and below)
			for (size_t i = 0; i < m; ++i) {
				if (i == pivot_row)
					continue;
				K factor = result(i, col);
				for (size_t j = 0; j < n; ++j)
					result(i, j) -= factor * result(pivot_row, j);
			}

			// 5. advance to the next pivot position
			++pivot_row;
		}

		return result;
	}

	// TODO: • A function to reshape a vector into a matrix, and vice-versa.
};

#endif
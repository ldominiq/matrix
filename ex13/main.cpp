// Exercise 13 - Rank

#include "Matrix.hpp"

void test_rank() {
	// full rank identity (square)
	Matrix<float> a = {
		{ 1., 0., 0. },
		{ 0., 1., 0. },
		{ 0., 0., 1. }
	};
	std::cout << "rank " << a.rank() << " expected 3\n\n";

	// rank-deficient square (row 2 = 2 * row 1)
	Matrix<float> b = {
		{ 1., 2., 0., 0. },
		{ 2., 4., 0., 0. },
		{ -1., 2., 1., 1. }
	};
	std::cout << "rank " << b.rank() << " expected 2\n\n";

	// tall non-square, full column rank
	Matrix<float> c = {
		{ 8., 5., -2. },
		{ 4., 7., 20. },
		{ 7., 6., 1. },
		{ 21., 18., 7. }
	};
	std::cout << "rank " << c.rank() << " expected 3\n\n";
}

int main() {

	test_rank();

	return 0;
}

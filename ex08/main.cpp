// Exercise 08 - Trace

#include "Matrix.hpp"

void test_trace() {
	// 1
	Matrix<float> u = { 
		{ 1., 0. },
		{ 0., 1. } 
	};

	std::cout << "trace " << u.trace();

	std::cout << " expected  2\n\n";

	// 2
	u = {
		{ 2., 5., 0. },
		{ 4., 3., 7. },
		{ -2., 3., 4. }
	};

	std::cout << "trace " << u.trace();

	std::cout << " expected  9\n\n";

	// 3
	u = {
		{ -2., -8., 4. },
		{ 1., -23., 4. },
		{ 0., 6., 4. }
	};

	std::cout << "trace " << u.trace();

	std::cout << " expected  -21\n\n";
}

int main() {

	test_trace();

	return 0;
}
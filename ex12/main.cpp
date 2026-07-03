// Exercise 12 - Inverse

#include "Matrix.hpp"

static void show_inv(const char* label, const Matrix<float>& m) {
	std::cout << label << "\n";
	m.print();
	try {
		Matrix<float> inv = m.inverse();
		std::cout << "inverse =\n";
		inv.print();
		// self-check: A * A^-1 should be (approximately) the identity
		std::cout << "A * A^-1 =\n";
		m.mul_mat(inv).print();
	} catch (const std::exception& e) {
		std::cout << "inverse = ERROR: " << e.what() << "\n";
	}
	std::cout << "\n";
}

void test_inverse() {
	// 1. identity -> identity
	Matrix<float> a = {
		{ 1., 0., 0. },
		{ 0., 1., 0. },
		{ 0., 0., 1. }
	};
	show_inv("A (identity)", a);

	// 2. diagonal 2,2,2 -> diagonal 0.5,0.5,0.5
	Matrix<float> b = {
		{ 2., 0., 0. },
		{ 0., 2., 0. },
		{ 0., 0., 2. }
	};
	show_inv("B (diag 2)", b);

	// 3. general 3x3 (subject example)
	Matrix<float> c = {
		{ 8., 5., -2. },
		{ 4., 7., 20. },
		{ 7., 6.,  1. }
	};
	show_inv("C (3x3)", c);

	// 4. singular -> must report an error
	Matrix<float> d = {
		{  1., -1. },
		{ -1.,  1. }
	};
	show_inv("D (singular 2x2)", d);
}

int main() {

	test_inverse();

	return 0;
}

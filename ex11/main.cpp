// Exercise 11 - Determinant

#include "Matrix.hpp"

static void show_det(const char* label, const Matrix<float>& m, float expected) {
	std::cout << label << "\n";
	m.print();
	std::cout << "det = " << m.determinant() << "  (expected " << expected << ")\n\n";
}

void test_determinant() {
	// 1. 2x2, singular -> 0
	Matrix<float> a = {
		{  1., -1. },
		{ -1.,  1. }
	};
	show_det("A (2x2)", a, 0.f);

	// 2. 3x3 diagonal -> 2*2*2
	Matrix<float> b = {
		{ 2., 0., 0. },
		{ 0., 2., 0. },
		{ 0., 0., 2. }
	};
	show_det("B (3x3)", b, 8.f);

	// 3. 3x3 general
	Matrix<float> c = {
		{ 8., 5., -2. },
		{ 4., 7., 20. },
		{ 7., 6.,  1. }
	};
	show_det("C (3x3)", c, -174.f);

	// 4. 4x4
	Matrix<float> d = {
		{  8.,  5., -2., 4. },
		{  4., 2.5, 20., 4. },
		{  8.,  5.,  1., 4. },
		{ 28., -4., 17., 1. }
	};
	show_det("D (4x4)", d, 1032.f);
}

int main() {

	test_determinant();

	return 0;
}

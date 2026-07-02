// Exercise 10 - row-echelon form

#include "Matrix.hpp"

// print a matrix with a label and its dimensions
static void show(const char* label, const Matrix<float>& m) {
	std::cout << label << "  (" << m.rows() << "x" << m.cols() << ")\n";
	m.print();
	std::cout << "\n";
}

void test_row_echelon() {
	// 1. identity stays the identity
	Matrix<float> a = {
		{ 1., 0., 0. },
		{ 0., 1., 0. },
		{ 0., 0., 1. }
	};
	show("A", a);
	show("rref(A)  expected: identity", a.row_echelon());

	// 2. full-rank 2x2 -> identity
	Matrix<float> b = {
		{ 1., 2. },
		{ 3., 4. }
	};
	show("B", b);
	show("rref(B)  expected: \n[1, 0]\n[0, 1]\n", b.row_echelon());

	// 3. rank-deficient (row 2 == 2*row 1)
	Matrix<float> c = {
		{ 1., 2. },
		{ 2., 4. }
	};
	show("C", c);
	show("rref(C)  expected: \n[1, 2]\n[0, 0]\n", c.row_echelon());

	// 4. non-square augmented-style matrix
	Matrix<float> d = {
		{ 8., 5., -2., 4., 28. },
		{ 4., 2.5, 20., 4., -4. },
		{ 8., 5., 1., 4., 17. }
	};
	show("D", d);
	show("rref(D)  expected: \n[1, 0.625, 0, 0, -12.1666667]\n"
		"[0, 0, 1, 0, -3.6666667]\n[0, 0, 0, 1, 29.5]\n", d.row_echelon());

	// 5. test
	Matrix<float> e = {
		{ 1., 5., 3., -4., 19. },
		{ 3., 16, 7., -9., 42. },
		{ -2., -8., -9., 3., -61. }
	};
	show("E", e);
	show("rref(D)  expected: \n[1, 0, 0, 124, 3]\n"
		"[0, 1, 0, -19, -1]\n[0, 0, 1, -11, 7]\n", e.row_echelon());
}

int main() {

	test_row_echelon();

	return 0;
}

// Exercise 09 - Transpose

#include "Matrix.hpp"

// print a matrix with a label and its dimensions
static void show(const char* label, const Matrix<float>& m) {
	std::cout << label << "  (" << m.rows() << "x" << m.cols() << ")\n";
	m.print();
	std::cout << "\n";
}

void test_transpose() {
	// 1. square matrix
	Matrix<float> a = {
		{ 1., 2. },
		{ 3., 4. }
	};
	show("A", a);
	show("A^T  expected (2x2): [1, 3] / [2, 4]", a.transpose());

	// 2. non-square 2x3 -> 3x2
	Matrix<float> b = {
		{ 1., 2., 3. },
		{ 4., 5., 6. }
	};
	show("B", b);
	show("B^T  expected (3x2): [1, 4] / [2, 5] / [3, 6]", b.transpose());

	// 3. transposing twice gives back the original
	show("(B^T)^T  expected == B (2x3)", b.transpose().transpose());
}

int main() {

	test_transpose();

	return 0;
}

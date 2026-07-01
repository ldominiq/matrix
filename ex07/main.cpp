// Exercise 07 - Linear map, Matrix multiplication

#include "Vector.hpp"
#include "Matrix.hpp"

void test_mul_vec() {
	// 1
	Matrix<float> u = { 
		{ 1., 0. },
		{ 0., 1. } 
	};
	Vector<float> v = { 4., 2. };

	Vector<float> r;

	std::cout << "mul_vec ";

	r = u.mul_vec(v);
	r.print();

	std::cout << " expected  [4, 2]\n\n";

	// 2
	u = {
		{ 2., 0. },
		{ 0., 2. }
	};
	v = { 4., 2. };

	std::cout << "mul_vec ";

	r = u.mul_vec(v);
	r.print();

	std::cout << " expected  [8, 4]\n\n";

	// 3
	u = {
		{ 2., -2. },
		{ -2., 2. }
	};
	v = { 4., 2. };

	std::cout << "mul_vec ";

	r = u.mul_vec(v);
	r.print();

	std::cout << " expected  [4, -4]\n\n";
}

void test_mul_mat() {
	// 1
	Matrix<float> u = {
		{ 1., 0. },
		{ 0., 1. }
	};
	Matrix<float> v = {
		{ 1., 0. },
		{ 0., 1. }
	};

	Matrix<float> r;

	std::cout << "mul_mat\n";

	r = u.mul_mat(v);
	r.print();

	std::cout << "expected\n[1, 0]\n[0, 1]\n\n";

	// 2
	u = {
		{ 1., 0. },
		{ 0., 1. }
	};
	v = {
		{ 2., 1. },
		{ 4., 2. }
	};

	std::cout << "mul_mat\n";

	r = u.mul_mat(v);
	r.print();

	std::cout << "expected\n[2, 1]\n[4, 2]\n\n";

	// 3
	u = {
		{ 3., -5. },
		{ 6., 8. }
	};
	v = {
		{ 2., 1. },
		{ 4., 2. }
	};

	std::cout << "mul_mat\n";

	r = u.mul_mat(v);
	r.print();

	std::cout << "expected\n[-14, -7]\n[44, 22]\n\n";

}

int main() {

	test_mul_vec();
	test_mul_mat();

	return 0;
}
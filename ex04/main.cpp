// Exercise 04 - Norm

#include "Vector.hpp"

void test_norm_1() {
	Vector<float> u = {0., 0., 0.};

	std::cout << "norm_1   " << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;

	std::cout << "expected 0, 0, 0\n\n";

}

void test_norm_2() {
	Vector<float> u = { 1., 2., 3. };

	std::cout << "norm_2   " << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;

	std::cout << "expected 6, 3.74165738, 3\n\n";
}

void test_norm_3() {
	Vector<float> u = { -1., -2. };

	std::cout << "norm_3   " << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << std::endl;

	std::cout << "expected 3, 2.236067977, 2\n\n";
}

int main() {

	test_norm_1();
	test_norm_2();
	test_norm_3();

	return 0;
}
// Exercise 05 - Cosine

#include "Vector.hpp"

void test_angle_cos_1() {
	Vector<float> u = { 1., 0. };
	Vector<float> v = { 1., 0. };

	std::cout << "angle_cos " << u.angle_cos(u, v) << std::endl;

	std::cout << "expected  1\n\n";

}

void test_angle_cos_2() {
	Vector<float> u = { 1., 0. };
	Vector<float> v = { 0., 1. };

	std::cout << "angle_cos " << u.angle_cos(u, v) << std::endl;

	std::cout << "expected 0\n\n";

}

void test_angle_cos_3() {
	Vector<float> u = { -1., 1. };
	Vector<float> v = { 1., -1. };

	std::cout << "angle_cos " << u.angle_cos(u, v) << std::endl;

	std::cout << "expected -1\n\n";

}

void test_angle_cos_4() {
	Vector<float> u = { 2., 1. };
	Vector<float> v = { 4., 2. };

	std::cout << "angle_cos " << u.angle_cos(u, v) << std::endl;

	std::cout << "expected 1\n\n";

}

void test_angle_cos_5() {
	Vector<float> u = { 1., 2., 3. };
	Vector<float> v = { 4., 5., 6. };

	std::cout << "angle_cos " << u.angle_cos(u, v) << std::endl;

	std::cout << "expected 0.974631846\n\n";

}

int main() {

	test_angle_cos_1();
	test_angle_cos_2();
	test_angle_cos_3();
	test_angle_cos_4();
	test_angle_cos_5();

	return 0;
}
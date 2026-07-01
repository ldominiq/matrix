// Exercise 06 - Cross product

#include "Vector.hpp"

void test_cross_product_1() {
	Vector<float> u = { 0., 0., 1. };
	Vector<float> v = { 1., 0., 0. };

	Vector<float> cross = cross_product(u, v);

	std::cout << "cross_product ";
	cross.print();

	std::cout << " expected  [0, 1, 0]\n\n";

}

void test_cross_product_2() {
	Vector<float> u = { 1., 2., 3. };
	Vector<float> v = { 4., 5., 6. };

	Vector<float> cross = cross_product(u, v);

	std::cout << "cross_product ";
	cross.print();

	std::cout << " expected [-3, 6, -3]\n\n";

}

void test_cross_product_3() {
	Vector<float> u = { 4., 2., -3. };
	Vector<float> v = { -2., -5., 16. };

	Vector<float> cross = cross_product(u, v);

	std::cout << "cross_product ";
	cross.print();

	std::cout << " expected [17, -58, -16]";

}

int main() {

	test_cross_product_1();
	test_cross_product_2();
	test_cross_product_3();

	return 0;
}
#include "Vector.hpp"

static void test1() {
	Vector<float> e1{ 1.f, 0.f, 0.f };
	Vector<float> e2{ 0.f, 1.f, 0.f };
	Vector<float> e3{ 0.f, 0.f, 1.f };

	std::vector<Vector<float>> u = { e1, e2, e3 };
	std::vector<float> coefs = { 10.f, -2.f, 0.5f };

	Vector<float> result = linear_combination(u, coefs);

	std::cout << "linear_combination: ";
	result.print();
	std::cout << "\tExpected [10, -2, 0.5]\n";
}

static void test2() {
	Vector<float> v1{ 1.f, 2.f, 3.f };
	Vector<float> v2{ 0.f, 10.f, -100.f };

	std::vector<Vector<float>> u{ v1, v2 };
	std::vector<float> coefs{ 10.f, -2.f };

	Vector<float> result = linear_combination(u, coefs);

	std::cout << "linear_combination: ";
	result.print();
	std::cout << "\tExpected [10, 0, 230]\n";
}

// Assertion failed: u.size() == coefs.size()
static void test_undefined() {
	Vector<float> v1{ 1.f, 2.f, 3.f };
	Vector<float> v2{ 0.f, 10.f, -100.f, 4.f };

	std::vector<Vector<float>> u{ v1, v2 };
	std::vector<float> coefs{ 10.f, -2.f, 1.f };

	Vector<float> result = linear_combination(u, coefs);

	std::cout << "linear_combination: ";
	result.print();
	std::cout << "\tExpected [10, 0, 230]\n";
}

int main() {

	test1();
	test2();
	test_undefined();

	return 0;
}
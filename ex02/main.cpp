// Exercise 02 - Linear interpolation

#include "Vector.hpp"
#include "Matrix.hpp"
#include "operations.hpp"

void test_lerp() {
	float r1 = lerp(0.f, 1.f, 0.f);
	float r2 = lerp(0.f, 1.f, 1.f);
	float r3 = lerp(0.f, 1.f, 0.5f);
	float r4 = lerp(21.f, 42.f, 0.3f);


	std::cout << "lerp " << r1 << "\texpected 0\n";
	std::cout << "lerp " << r2 << "\texpected 1\n";
	std::cout << "lerp " << r3 << "\texpected 0.5\n";
	std::cout << "lerp " << r4 << "\texpected 27.3\n";
}

void test_lerp_vector() {
	Vector<float> v1 = { 2.f, 1.f };
	Vector<float> v2 = { 4.f, 2.f };

	Vector<float> vr1 = lerp(v1, v2, 0.3f);

	std::cout << "lerp vector ";
	vr1.print();
	std::cout << "\texpected [2.6, 1.3]\n";
}

void test_lerp_matrix() {
	Matrix<float> m1 = { { 2.f, 1.f }, { 3.f, 4.f } };
	Matrix<float> m2 = { { 20.f, 10.f }, { 30.f, 40.f } };

	Matrix<float> mr = lerp(m1, m2, 0.5f);

	std::cout << "lerp matrix\n";
	mr.print();
	std::cout << "expected\n[11, 5.5]\n[16.5, 22]\n";
}

int main() {

	test_lerp();
	test_lerp_vector();
	test_lerp_matrix();

	return 0;
}
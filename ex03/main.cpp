// Exercise 03 - Dot product

#include "Vector.hpp"

/*
	let mut u = Vector::from([0., 0.]);
	let v = Vector::from([1., 1.]);
	println!("{}", u.dot(v));
	// 0.0
	let mut u = Vector::from([1., 1.]);
	let v = Vector::from([1., 1.]);
	println!("{}", u.dot(v));
	// 2.0
	let mut u = Vector::from([-1., 6.]);
	let v = Vector::from([3., 2.]);
	println!("{}", u.dot(v));
	// 9.0
*/
void test_dot() {
	Vector<float> u = {0., 0.};
	Vector<float> v = {1., 1.};

	std::cout << "dot " << u.dot(v) << "\texpected 0\n";

	u = {1., 1.};
	v = {1., 1.};

	std::cout << "dot " << u.dot(v) << "\texpected 2\n";

	u = {-1., 6.};
	v = {3., 2.};

	std::cout << "dot " << u.dot(v) << "\texpected 9\n";

}

int main() {

	test_dot();

	return 0;
}
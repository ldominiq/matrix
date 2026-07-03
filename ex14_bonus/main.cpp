// Exercise 14 - Bonus: Projection matrix

#include <fstream>
#include <cmath>

#include "projection.hpp"

// Writes the matrix to `path` in COLUMN-major order, one column per line,
// which is the format the provided display software expects.
// We store row-major, so printing the transpose row-by-row gives column-major.
static void write_proj(const Matrix<float>& p, const char* path) {
	Matrix<float> col_major = p.transpose();
	std::ofstream out(path);

	for (size_t i = 0; i < col_major.rows(); ++i) {
		for (size_t j = 0; j < col_major.cols(); ++j) {
			out << col_major(i, j);
			if (j + 1 < col_major.cols()) out << ", ";
		}
		out << '\n';
	}
}

int main() {
	const float pi    = 3.14159265358979323846f;
	const float fov   = 70.0f * (pi / 180.0f); // 70 degrees -> radians
	const float ratio = 16.0f / 9.0f;
	const float near  = 1.0f;
	const float far   = 100.0f;

	Matrix<float> p = projection(fov, ratio, near, far);

	// show it on stdout
	std::cout << "projection matrix (row-major):\n";
	p.print();

	// and write the proj file for the display tool (column-major)
	write_proj(p, "proj");
	std::cout << "\nwrote 'proj' (column-major) for the display software\n";

	return 0;
}

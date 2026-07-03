#ifndef projection_hpp
#define projection_hpp

#include <cmath> // std::tan

#include "Matrix.hpp"

/*
	This is the camera-to-screen matrix P
	from  s = P * V * M * p.

	Arguments:
		fov   : vertical field of view, in RADIANS (the cone-of-vision angle)
		ratio : window aspect ratio  w / h
		near  : distance to the near clipping plane (> 0)
		far   : distance to the far  clipping plane (> near)

	Conventions used to match the provided display software:
		- right-handed, camera looks down the -Z axis
		- Normalized Device Coordinates: X, Y in [-1, 1],  Z in [0, 1]

	The matrix below is written in the natural mathematical (row-major) form.
	main.cpp is responsible for writing it out in COLUMN-major order, which is
	what the display tool expects.
*/
inline Matrix<float> projection(float fov, float ratio, float near, float far) {
	const float f = 1.0f / std::tan(fov / 2.0f);

	Matrix<float> p(4, 4); // starts zeroed

	p(0, 0) = f / ratio;
	p(1, 1) = f;

	// depth mapping for NDC z in [0, 1] (right-handed)
	p(2, 2) = far / (near - far);
	p(2, 3) = -(far * near) / (far - near);
	p(3, 2) = -1.0f; // carries -z into the w component (perspective divide)

	return p;
}

#endif

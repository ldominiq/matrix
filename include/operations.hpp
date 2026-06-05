#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

// Time complexity	O(n)
// Space complexity O(n)
// Computes a linear interpolation between two objects of the same type
template <typename V>
V lerp(V u, V v, float t) {
	if (t == 0) return u;
	if (t == 1) return v;

	// v0 + t * (v1 - v0);
	v -= u;
	v *= t;
	u += v;

	return u;
}

#endif
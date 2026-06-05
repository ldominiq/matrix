/* Exercise 00 - Add, Subtract and Scale
 *
 * Reference (subject examples):
 *   Vector::from([2., 3.]) + [5., 7.]  ->  [7, 10]
 *   Vector::from([2., 3.]) - [5., 7.]  ->  [-3, -4]
 *   Vector::from([2., 3.]) * 2.        ->  [4, 6]
 *
 *   Matrix [[1,2],[3,4]] + [[7,4],[-2,2]]  ->  [[8,6],[1,6]]
 *   Matrix [[1,2],[3,4]] - [[7,4],[-2,2]]  ->  [[-6,-2],[5,2]]
 *   Matrix [[1,2],[3,4]] * 2.              ->  [[2,4],[6,8]]
 */

#include "Vector.hpp"
#include "Matrix.hpp"


static void test_add() {
    Vector<float> u{ 2.0f, 3.0f };
    Vector<float> v{ 5.0f, 7.0f };

    u.add(v);

    std::cout << "add  ";
    u.print();
    std::cout << "\texpected [7, 10]\n";
}

static void test_sub() {
    Vector<float> u{ 2.0f, 3.0f };
    Vector<float> v{ 5.0f, 7.0f };

    u.sub(v);

    std::cout << "sub  ";
    u.print();
    std::cout << "\texpected [-3, -4]\n";
}

static void test_scl() {
    Vector<float> u{ 2.0f, 3.0f };

    u.scl(2);

    std::cout << "scl  ";
    u.print();
    std::cout << "\texpected [4, 6]\n";
}

// Should do Assertion failed: size() == v.size()
static void test_undefined() {
    Vector<float> u{ 3.0f, 2.0f };
    Vector<float> v{ 1.0f, 4.0f, 2.0f };

    u += v;

    std::cout << "undefined ";
    u.print();
    std::cout << "\texpected [4, 6]\n";
}

static void test_matrix_add() {
    Matrix<float> u{ {1.0f, 2.0f}, {3.0f, 4.0f} };
    Matrix<float> v{ {7.0f, 4.0f}, {-2.0f, 2.0f} };

    u.add(v);

    std::cout << "matrix add  (expected [8, 6] / [1, 6])\n";
    u.print();
}

static void test_matrix_sub() {
    Matrix<float> u{ {1.0f, 2.0f}, {3.0f, 4.0f} };
    Matrix<float> v{ {7.0f, 4.0f}, {-2.0f, 2.0f} };

    u.sub(v);

    std::cout << "matrix sub  (expected [-6, -2] / [5, 2])\n";
    u.print();
}

static void test_matrix_scl() {
    Matrix<float> u{ {1.0f, 2.0f}, {3.0f, 4.0f} };

    u.scl(2);

    std::cout << "matrix scl  (expected [2, 4] / [6, 8])\n";
    u.print();
}

int main() {
    test_add();
    test_sub();
    test_scl();
    //test_undefined();

    test_matrix_add();
    test_matrix_sub();
    test_matrix_scl();

    return 0;
}

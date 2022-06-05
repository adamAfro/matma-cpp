#ifndef TEST
#define TEST

#include <iostream>

#include "matrix/vector.hpp"
#include "matrix/rect.hpp"

using namespace std;

namespace Test {

  namespace Vectors {

    void get() {

      Matrix::Vector v1(3, new double [] { 1,  2, 3 });
      Matrix::Vector v2(3, new double [] { 1, -2, 0 });

      cout << "get:" << endl;
      cout << "v1[0]" << "=" << v1[0] << endl;
      cout << "v2[1]" << "=" << v2[1] << endl;
    }

    void sum() {

      Matrix::Vector v1(3, new double [] { 1,  2, 3 });
      Matrix::Vector v2(3, new double [] { 1, -2, 0 });

      cout << "sum:" << endl;
      cout << v1 << "+" << v2 << "=" << "?" << endl;
      Matrix::Vector vplus = v1 + v2;
      cout << v1 << "+" << v2 << "=" << vplus << endl;
    }

    void product() {

      Matrix::Vector v1(3, new double [] { 1,  2, 3 });
      Matrix::Vector v2(3, new double [] { 1, -2, 0 });

      cout << "product:" << endl;
      cout << v1 << "*" << v2 << "=" << "?" << endl;
      Matrix::Vector vprod = v1 * v2;
      cout << v1 << "*" << v2 << "=" << vprod << endl;
    }
  }

  namespace Matrixes {

    void print() {

      Matrix::Rect m1(3,3, new double [] {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
      });

      Matrix::Rect m2(3,3, new double [] {
         9, 0,  8,
        -7, 1, -5,
         4, 2,  3
      });

      cout << "m1: " << m1.read() << endl;
      cout << "m2: " << m2.read() << endl;
      cout << "m2[1]: " << m2[1].read() << endl;
      cout << "m2.columns(0): " << m2.column(0).read() << endl;
    }

    void sum() {

      Matrix::Rect m1(3,3, new double [] {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
      });

      Matrix::Rect m2(3,3, new double [] {
         9, 0,  8,
        -7, 1, -5,
         4, 2,  3
      });

      cout << "sum:" << endl;
      cout << m1 << "+" << m2 << "=" << "?" << endl;
      Matrix::Rect mplus = m1 + m2;
      cout << m1 << "+" << m2 << "=" << mplus << endl;
    }

    void product() {

      Matrix::Rect m1(3,3, new double [] {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
      });

      Matrix::Rect m2(3,3, new double [] {
         9, 0,  8,
        -7, 1, -5,
         4, 2,  3
      });

      cout << "product:" << endl;
      cout << m1 << "*" << m2 << "=" << "?" << endl;
      Matrix::Rect mprod = m1 * m2;
      cout << m1 << "*" << m2 << "=" << mprod << endl;
    }
  }
}

#endif

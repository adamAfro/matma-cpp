#ifndef TEST
#define TEST

#include <iostream>
#include "vector/class.hpp"

using namespace std;

namespace Test {

  namespace Vectors {

    void sum() {

      Vector v1(3, new double [] { 1,  2, 3 });
      Vector v2(3, new double [] { 1, -2, 0 });

      cout << "sum:" << endl;
      cout << v1 << "+" << v2 << "=" << "?" << endl;
      Vector vplus = v1 + v2;
      cout << v1 << "+" << v2 << "=" << vplus << endl;
    };

    void product() {

      Vector v1(3, new double [] { 1,  2, 3 });
      Vector v2(3, new double [] { 1, -2, 0 });

      cout << "product:" << endl;
      cout << v1 << "*" << v2 << "=" << "?" << endl;
      Vector vprod = v1 * v2;
      cout << v1 << "*" << v2 << "=" << vprod << endl;
    }

    void get() {

      Vector v1(3, new double [] { 1,  2, 3 });
      Vector v2(3, new double [] { 1, -2, 0 });

      cout << "get:" << endl;
      cout << "v1[0]" << "=" << v1[0] << endl;
      cout << "v2[1]" << "=" << v2[1] << endl;
    }
  }
}

#endif

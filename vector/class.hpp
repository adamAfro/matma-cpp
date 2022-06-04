#ifndef VECTOR
#define VECTOR

#include <ostream>
#include <string>
#include <sstream>

class Vector {

  // output << operator
  friend std::ostream & operator << (std::ostream &stream, Vector &v) {

    stream << "[ ";
    for (unsigned int i = 0; i < v.count; i++)
      stream << v.values[i] << " ";
    stream << "]";

    return stream;
  }

  protected:

    unsigned int count;
    double *values;

  public:

    ~Vector() {

      double * address = this -> values;

      delete address;
    }

    Vector(unsigned int length = 1, double *values = new double[] { 0 }) {

      this -> count = length;
      this -> values = values;
    }

    Vector(const Vector &v) {

      this -> count = v.count;
      this -> values = new double[v.count];
      for (unsigned int i = 0; i < v.count; i++) {
        this -> values[i] = v.values[i];
      }
    }


    const unsigned int length() {

      return this -> count;
    }

    double operator [] (unsigned int index) {

      if (index >= (this -> count))
        throw "cannot get index from outside of a vector";

      return this -> values[index];
    }

    std::string read() {

      std::stringstream info;

      info << "vector(" << this -> count << "):";

      info << "[ ";
      for (unsigned int i = 0; i < this -> count; i++)
        info << this -> values[i] << " ";
      info << "]";

      return info.str();
    }


    // classic sum
    Vector operator + (Vector &v) {

      if (v.count != this -> count)
        throw "cannot sum vectors of not equal lengths";

      Vector sum(v);
      for (unsigned int i = 0; i < (this -> count); i++)
        sum.values[i] += this -> values[i];

      return sum;
    }

    // scalar product
    Vector operator * (Vector &v) {

      if (v.count != this -> count)
        throw "cannot sum vectors of not equal lengths";

      Vector sum(v);
      for (unsigned int i = 0; i < (this -> count); i++)
        sum.values[i] *= this -> values[i];

      return sum;
    }
};

#endif

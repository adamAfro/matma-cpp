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
      stream << v.row[i] << " ";
    stream << "]";

    return stream;
  }

  protected:

    unsigned int count;
    double *row;

  public:

    ~Vector() {

      double * address = this -> row;

      delete address;
    }

    Vector(unsigned int length = 1, double *values = new double[] { 0 }) {

      this -> count = length;
      this -> row = values;
    }

    Vector(const Vector &v) {

      this -> count = v.count;
      this -> row = new double[v.count];
      for (unsigned int i = 0; i < v.count; i++) {
        this -> row[i] = v.row[i];
      }
    }


    const unsigned int length() {

      return this -> count;
    }

    double operator [] (unsigned int index) {

      if (index >= (this -> count))
        throw "cannot get index from outside of a vector";

      return this -> row[index];
    }

    std::string read() {

      std::stringstream info;

      info << "vector(" << this -> count << "):";

      info << "[ ";
      for (unsigned int i = 0; i < this -> count; i++)
        info << this -> row[i] << " ";
      info << "]";

      return info.str();
    }


    // classic sum
    Vector operator + (Vector &v) {

      if (v.count != this -> count)
        throw "cannot sum vectors of not equal lengths";

      Vector sum(v);
      for (unsigned int i = 0; i < (this -> count); i++)
        sum.row[i] += this -> row[i];

      return sum;
    }

    // scalar product
    Vector operator * (Vector &v) {

      if (v.count != this -> count)
        throw "cannot sum vectors of not equal lengths";

      Vector sum(v);
      for (unsigned int i = 0; i < (this -> count); i++)
        sum.row[i] *= this -> row[i];

      return sum;
    }
};

#endif

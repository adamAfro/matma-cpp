#ifndef MATRIX
#define MATRIX

#include <ostream>
#include <string>
#include <sstream>

#include "vector.hpp"

namespace Matrix {

  class Rect : public Vector {

    // output << operator
    friend std::ostream & operator << (std::ostream &stream, Rect &m) {

      stream << "[ ";
      for (unsigned int i = 0; i < (m.count * m.amount); i++)
        stream << m.values[i] << " ";
      stream << "]";

      return stream;
    }

    protected:

      unsigned int amount; // of columns

    public:

      // basic constr
      Rect(
        unsigned int rows = 1,
        unsigned int columns = 1,
        double *values = new double[] {}
      ) : Vector(rows, values) {

        this -> amount = columns;
      }

      // clone constr
      Rect(const Rect &v) {

        this -> count = v.count;
        this -> amount = v.amount;
        this -> values = new double[v.count * v.amount];
        for (unsigned int i = 0; i < v.count; i++) {
          this -> values[i] = v.values[i];
        }
      }


      // checks if matrix dimension equals the given one
      bool dims(unsigned int dim[2]) {

        return (dim[0] == this -> count && dim[1] == this -> amount);
      }

      // yelds amount of elements in matrix
      const unsigned int length() {

        return this -> count * this -> amount;
      }

      // changes give position value
      double revalue (unsigned int row, unsigned int column, double value) {

        if (row >= (this -> count) || column >= (this -> amount))
          throw "cannot revalue element from outside of a matrix";

        unsigned int index = row * this -> amount + column;
        double previous = this -> values[index];
        this -> values[index] = value;

        return previous;
      }

      // gets whole row as a vector
      Vector operator [] (unsigned int row) {

        return this -> row(row);
      }

      // gets whole row as a vector
      Vector row (unsigned int index) {

        if (index >= (this -> count))
          throw "cannot get index from outside of a matrix";

        Vector v(this -> amount, new double[this -> amount]);
        for (unsigned int i = 0; i < this -> amount; i++) {

          v.values[i] = this -> values[index * this -> amount + i];
        }

        return v;
      }

      // gets whole column as a vector
      Vector column (unsigned int index) {

        if (index >= (this -> amount))
          throw "cannot get index from outside of a matrix";

        Vector v(this -> count, new double[this -> count]);
        for (unsigned int i = 0; i < this -> count; i++) {

          v.values[i] = this -> values[i * this -> count + index];
        }

        return v;
      }

      // dumps info
      std::string read() {

        std::stringstream info;

        info << "matrix(" << this -> count << "x" << this -> amount << "):";

        info << "[ ";
        for (unsigned int i = 0; i < (this -> count * this -> amount); i++)
          info << this -> values[i] << " ";
        info << "]";

        return info.str();
      }


      // classic sum
      Rect operator + (Rect &m) {

        unsigned int dim[2] = { m.count, m.amount };
        if (!this -> dims(dim))
          throw "cannot sum matrices of not equal dimensions";

        Rect sum(m);
        for (unsigned int i = 0; i < (this -> length()); i++)
          sum.values[i] += this -> values[i];

        return sum;
      }

      // matrices product
      Rect operator * (Rect &m) {

        if (m.count != this -> amount)
          throw "cannot product matrixes of different column-row dimensions";

        Vector *columns[m.amount];
        for (unsigned int j = 0; j < m.amount; j++) {

          Vector *point = new Vector(m.column(j));

          columns[j] = point;
        }

        Rect product(this -> count, m.amount, new double [9]);
        for (unsigned int i = 0; i < this -> count; i++) {

          Vector row = this -> row(i);
          for (unsigned int j = 0; j < m.amount; j++) {

            Vector vprod = row * *columns[j];

            product.revalue(i,j, vprod.sum());
          }
        }

        for (unsigned int j = 0; j < m.amount; j++)
          delete columns[j];

        return product;
      }
  };
}

#endif

#include "test.hpp"

int main(int argc, char const *argv[]) {

  Test::Vectors::get();
  Test::Vectors::sum();
  Test::Vectors::product();

  Test::Matrixes::print();
  Test::Matrixes::sum();

  return 0;
}

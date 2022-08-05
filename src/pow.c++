#include "pow.hpp"

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <base> <exponent>\n", argv[0]);
    return 1;
  }
  double value, exponent;
  printf("%g\n", pow(atof(argv[1]), atof(argv[2])));
  return 0;
}
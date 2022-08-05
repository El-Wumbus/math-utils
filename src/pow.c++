#include "pow.hpp"

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <number> <exponent>\n", argv[0]);
    return 1;
  }
  double value, exponent;
  // for (int optind = 1; optind < argc + 1; ++optind) {
  //   if (optind == 0) {
  //     continue;
  //   }
  //   if (optind == argc) {
  //     break;
  //   }
  //   values.push_back(atof(argv[optind]));
  // }
  printf("%g\n", pow(atof(argv[1]), atof(argv[2])));
  return 0;
}
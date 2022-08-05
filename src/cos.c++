#include "cos.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("%s::return value of cos() in radians \nUsage: %s <number> ...\n", argv[0], argv[0]);
    return 1;
  }
  for (int optind = 1; optind < argc + 1; ++optind) {
    if (optind == 0) {
      continue;
    }
    if (optind == argc) {
      break;
    }
    printf("%.18g\n", cos(atof(argv[optind])));
  }
  return 0;
}
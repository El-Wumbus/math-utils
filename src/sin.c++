#include "sin.h++"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("%s::return value of sin() in radians \nUsage: %s <number1> ...\n", argv[0], argv[0]);
    return 1;
  }
  for (int optind = 1; optind < argc + 1; ++optind) {
    if (optind == 0) {
      continue;
    }
    if (optind == argc) {
      break;
    }
    printf("%g\n", sin(atof(argv[optind])));
  }
  return 0;
}
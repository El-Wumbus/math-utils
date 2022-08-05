#include "cos.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("%s::return value of cos(num) in radians \nUsage: %s <num> ...\n", argv[0], argv[0]);
    return 1;
  }
  int i=0;

  for (int optind = 1; optind < argc + 1; ++optind) {
    if (optind == 0) {
      continue;
    }
    if (optind == argc) {
      break;
    }
    while (i < strlen(argv[optind])) {
      if (argv[optind][i] == '\n') {
        argv[optind][i] = '\0';
      }
      i++;
    }
    printf("%.18g\n", cos(atof(argv[optind])));

  }
  return 0;
}
#include "pow.hpp"

int main(int argc, char **argv) {
  int i=0;

  if (argc < 3) {
    printf("Usage: %s <base> <exponent>\n", argv[0]);
    return 1;
  }
  for (int optind = 1; optind < argc + 1; ++optind) {
    while (i < strlen(argv[optind])) {
      if (argv[optind][i] == '\n') {
        argv[optind][i] = '\0';
      }
      i++;
    }
  }
  double value, exponent;
  printf("%g\n", pow(atof(argv[1]), atof(argv[2])));
  return 0;
}
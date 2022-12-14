#include "tan.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("%s::returns the tangent of an angle (num) in radians\nUsage: %s "
           "<num> ...\n",
           argv[0], argv[0]);
    return 1;
  }
  for (int optind = 1; optind < argc + 1; ++optind) {
    if (optind == 0) {
      continue;
    }
    if (optind == argc) {
      break;
    }
    unsigned int i = 0;
    while (i < strlen(argv[optind])) {
      if (argv[optind][i] == '\n') {
        argv[optind][i] = '\0';
      }
      i++;
    }
    printf("%.18g\n", tan(atof(argv[optind])));
  }
  return 0;
}
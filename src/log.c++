#include "log.hpp"

int main(int argc, char **argv) {
    unsigned int i=0;
  if (argc < 2) {
    printf("%s::return value of log(num) in base-e \nUsage: %s <num> ...\n", argv[0], argv[0]);
    return 1;
  }
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
    printf("%.18g\n", log(atof(argv[optind])));
  }
  return 0;
}
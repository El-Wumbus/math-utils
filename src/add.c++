#include "add.hpp"
double add(std::vector<double> values) {
  double sum = 0;
  for (unsigned int i = 0; i < values.size(); i++) {
    sum += values[i];
  }
  return sum;
}

int main(int argc, char **argv) {
unsigned int i=0;
  if (argc < 3) {
    printf("Usage: %s <number1> <number2>...\n", argv[0]);
    return 1;
  }
  std::vector<double> values;
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
    values.push_back(atof(argv[optind]));
  }
  printf("%g\n", add(values));
  return 0;
}
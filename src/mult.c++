#include "mult.hpp"
double mult(std::vector<double> values) {
  // Multiplying all the values in the vector together.
  double result =1;
  for (int i = 0; i < values.size(); i++) {
    result = result * values[i];
  }
  return result;
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
  printf("%g\n", mult(values));
  return 0;
}
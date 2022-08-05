#include "div.hpp"
double div(std::vector<double> values) {
  double result = 0;
  // Iterating through the vector and dividing each element by the previous
  // element.
  for (int i = 0; i < values.size(); i++) {
    if (result == 0) {
      result = values[i];
    } else {
      result = result / values[i];
    }
  }

  return result;
}

int main(int argc, char **argv) {
int i=0;

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
    int i = 0;
    while (i < strlen(argv[optind])) {
      if (argv[optind][i] == '\n') {
        argv[optind][i] = '\0';
      }
      i++;
    }
    values.push_back(atof(argv[optind]));
  }
  printf("%g\n", div(values));
  return 0;
}
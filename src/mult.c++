#include "mult.h++"
double mult(std::vector<double> values) {
  double result =1;
  for (int i = 0; i < values.size(); i++) {
    result = result * values[i];
  }
  return result;
}

int main(int argc, char **argv) {

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
    values.push_back(atof(argv[optind]));
  }
  printf("%g\n", mult(values));
  return 0;
}
#include "div.h++"
double div(std::vector<double> values) {
  double result = 0;
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
    // if (strcmp(argv[optind], "0") == 0) {
    //   std::cout << "Error: division by zero" << std::endl;
    //   return 1;
    // }
    values.push_back(atof(argv[optind]));
  }
  printf("%g\n", div(values));
  return 0;
}
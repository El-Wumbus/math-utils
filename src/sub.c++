#include "sub.h++"

double sub(std::vector<double> values)
{
  double diff = 0;
  for (int i = 0; i < values.size(); i++) {
    diff = diff - values[i];
  }
  return diff;
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
  printf("%g\n", sub(values));
  return 0;
}
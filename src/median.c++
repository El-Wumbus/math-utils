#include "median.hpp"
double median(std::vector<double> values) {
  int size = values.size();
   sort(values.begin(), values.end());
   if (size % 2 != 0)
      return (double)values[size/2];
   return (double)(values[(size-1)/2] + values[size/2])/2.0;
}

int main(int argc, char **argv) {
int i=0;
  if (argc < 3) {
    printf("Usage: %s <num1> <num2>...\n", argv[0]);
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
  printf("%.20g\n", median(values));
  return 0;
}
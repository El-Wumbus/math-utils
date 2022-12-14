#include "abs.hpp"
double abs(double x) {
  /**
   * @brief It takes a value x and returns the absolute value of x
   * 
   */
  return (x < 0) ? -x : x;
}

int main(int argc, char **argv) {
unsigned int i=0;
  for (int optind =0 ; optind < argc; optind++) { // when some extra arguments are passed
    double absval = abs(atof(argv[optind]));
    if (absval == 0)
    {
      continue;
    }
    while (i < strlen(argv[optind])) {
      if (argv[optind][i] == '\n') {
        argv[optind][i] = '\0';
      }
      i++;
    }
    printf("%g\n",absval);
  }
  return 0;
}
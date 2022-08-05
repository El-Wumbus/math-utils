#include "pi.hpp"
// Defining a constant variable `e` with the value of `exp(1.0)`
const long double e = exp(1.0);
int main() {
  //  Setting the precision of the output to the maximum number of digits that
  //  can be represented by a double.
  cout.precision(dbl::max_digits10);
  cout << "" << e << endl;
  return 0;
}
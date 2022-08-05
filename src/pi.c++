#include "pi.hpp"
const long double PI = (long double)2 * (long double)acos(0.0);

int main() {
  cout.precision(dbl::max_digits10);
  cout << "" << PI << endl;
  return 0;
}
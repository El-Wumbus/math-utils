#include "dnorm.h++"

const long double EulerConstant = std::exp(1.0);
const long double PI =
    3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482392603729;

long double dnorm(double x, double mean = 0, double standard_deviation = 1) {
  /**
   * @brief It takes a value x, a mean, and a standard deviation, and returns
   * the value of the probability density function (pdf) of the normal
   * distribution given a continuous random variable: x being drawn from a
   * normal distribution with mean and standard deviation
   *
   * @return long double The value of the pdf of the normal distribution
   */
  /* Gaussian (standard) distribution
  https://introcs.cs.princeton.edu/java/11gaussian/
  */
  // Calculating the normalization constant of the normal distribution
  long double normalization_constant =
      (long double)1 / (sqrt(2 * PI * pow(standard_deviation, 2)));
  long double z_score = (x - mean) / standard_deviation;
  return normalization_constant * (pow(EulerConstant, -pow(z_score, 2) / 2));
}

int main(int argc, char **argv) {
  double std_dev = 1;
  double mean = 0;
  unsigned int sci = 1;

  // Parsing the command line arguments.
  while ((opt_char = getopt_long(argc, argv, "hm:s:vn:d", long_options,
                                 &option_index)) != -1) {
    switch (opt_char) {
    case 's':
      std_dev = atof(optarg);
      break;
    case 'm':
      mean = atof(optarg);
      break;
    case 'v':
      printf("%s version %s\n", PROGRAM_NAME, VERSION);
      return (0);
      break;
    case 'h':
      printf("%s version %s\n", PROGRAM_NAME, VERSION);
      printf("Usage: %s [OPTION]...\n", PROGRAM_NAME);
      printf("\n");
      printf("Options:\n");
      printf("  -h, --help\t\tdisplay this help and exit\n");
      printf("  -m, --mean\t\tmean of the normal distribution\n");
      printf("  -s, --standard_deviation\tstandard deviation of the normal "
             "distribution\n");
      printf("  -v, --version\t\tdisplay version and exit\n");
      printf("  -d, --disable_sientific\t\tdisable automatic scientific "
             "notation\n");
      return (0);
      break;
    case 'n':
      sci = 0;
    }
  }

  for (; optind < argc; optind++) { // when some extra arguments are passed
    if (sci) {
      printf("%.30Lg\n", dnorm(atof(argv[optind]), mean, std_dev));
    } else {
      printf("%.30Lf\n", dnorm(atof(argv[optind]), mean, std_dev));
    }
  }
  return 0;
}
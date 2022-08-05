#define VERSION "0.1"
#define PROGRAM_NAME "dnorm"
#ifndef dnorm_h
#define dnorm_h
#include <cmath>
#include <cstring>
#include <getopt.h>
#include <iostream>
#include <stdio.h>
long double dnorm(double x, double mean, double standard_deviation);
int opt_char;
int option_index;
static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"mean", required_argument, 0, 'm'},
    {"standard_deviation", required_argument, 0, 's'},
    {"version", no_argument, 0, 'v'},
    {"disable_sientific", no_argument, 0, 'd'},
    {0, 0, 0, 0}
};
#endif

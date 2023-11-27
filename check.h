#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

/// @brief Different codes of errors
enum CODES
{
    ERROR,
    OK
};

/// @brief Checking does openmp supports
void check_openmp_support();
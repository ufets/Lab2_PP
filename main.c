#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

/// @brief Different codes of errors
enum CODES
{
    ERROR,
    OK
};


/// @brief Checking does openmp supports
void check_openmp_support()
{
    #ifdef _OPENMP
        printf("\n== OpenMP vesion: %d ==\n", _OPENMP);
        return;
    #endif
        fprintf(stderr,RED_COLOR "OpenMP not suppoted\n\n" RESET_COLOR);
        exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    check_openmp_support();

    printf("WORK!");
    return 0;
}
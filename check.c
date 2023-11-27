
#include "check.h"

void check_openmp_support()
{
    #ifdef _OPENMP
        printf("\n== OpenMP vesion: %d ==\n", _OPENMP);
        return;
    #endif
        fprintf(stderr,RED_COLOR "OpenMP not suppoted\n\n" RESET_COLOR);
        exit(EXIT_FAILURE);
}
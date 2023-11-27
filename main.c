#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "functions.h"
#include "check.h"

int main(int argc, char *argv[])
{
    char predef_flag = predefine_target(argc, argv[1]);

    const int num = 10000000; ///< Number of array elements

    int threads = 12;

    double results[threads];
    for (int i = 0; i < threads; i++)
    {
        results[i] = 0;
    }

    int num_of_calcs = 50;
    //double interm_res;
    for (int count = 0; count < num_of_calcs; count++)
    {
        //interm_res = 0;
        int *array = generate_array(num);
        const int target = generate_target(predef_flag, array, num);
        for (int i = 0; i < threads; i++)
        {
            double start = omp_get_wtime();
            search(array, num, target, i + 1);
            double end = omp_get_wtime();

            results[i] += (end - start);
        }
        free(array);
    }
    
    for(int i=0; i < threads; i++)
    {
        printf("%lf\n", results[i]/num_of_calcs);
    }
    return 0;
}
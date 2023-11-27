#include "functions.h"

char predefine_target(int argc, char *value)
{
    if (argc < 2)
    {
        return 0;
    }
    if (strcmp(value, "POS") == 0)
        return 1;
    else if (strcmp(value, "NEG") == 0)
        return -1;
    return 0;
}

int *generate_array(const int num)
{
    srand(time(NULL));

    int *array = NULL; ///< The array we need to find the max in

    /* Generate the random array */
    array = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        array[i] = rand() % num + num/2;
    }
    return array;
}

const int generate_target(char predef_flag, int *array, int num)
{
    if (predef_flag > 0)
    {
        return array[rand() % num];
    }
    if (predef_flag < 0)
    {
        return num + 1;
    }
    return rand() % num;
}

void search(int *array, int count, int target, int cur_num_thread)
{
    int index = -1;
    int flag = 0;
#pragma omp parallel num_threads(cur_num_thread) shared(array, count, target, flag) reduction(max : index)
    {
        int range = (int)(count / cur_num_thread);
        for (int i = 0; i < range + cur_num_thread - 2; i++)
        {
            if (flag)
            {
                break;
            }
            if (array[range * omp_get_thread_num() + i] == target)
            {
                index = i;
                flag = 1;
                break;
            }
        }
    }
    //printf("|%d|", index + 1);
}
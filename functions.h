#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
char predefine_target(int argc, char* value);
int* generate_array(const int num);
const int generate_target(char predef_flag, int * array, int num);
void search(int *array, int num, int target, int cur_num_thread);
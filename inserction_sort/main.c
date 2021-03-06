#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "GenerateRandomArray.h"
#include "InsectionSort.h"

int SingleExperiment(int length, int max_instances)
{
    int t_tot = 0, t_end, t_elapsed, A[length];
    clock_t t_start;
    for (int instace = 1; instace < max_instances; instace++)
    {
        GenerateRandomArray(A, length);
        t_start = clock();
        InsectionSort(A, length);
        t_end = clock();
        t_elapsed = t_end - t_start;
        t_tot = t_tot + t_elapsed;
    }
    return t_tot / max_instances;
}

void proc_Experiment(int min_length, int max_length)
{
    int max_instaces = 5;
    int step = 10;
    float time;
    for (int length = min_length; length < max_instaces; length = step)
    {
        time = SingleExperiment(length, max_instaces);
        printf("%f\n", time);
    }
}

int main()
{
    proc_Experiment(3, 15);
    return 0;
}

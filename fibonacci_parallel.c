#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{
    int n, i;

    printf("Enter number of terms : ");
    scanf("%d", &n);

    int fibonacci_arr[n];
    fibonacci_arr[0] = 0;
    fibonacci_arr[1] = 1;
    omp_set_num_threads(2);
double start = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp single
        {
            printf("Thread ID involved in the computation of fibonacci numbers = %d\n", omp_get_thread_num());
            for (i = 2; i < n; i++)
            {
                fibonacci_arr[i] = fibonacci_arr[i - 2] + fibonacci_arr[i - 1];
            }
        }
#pragma omp single
        {
            printf("Thread ID involved in the displaying of fibonacci numbers = %d\n", omp_get_thread_num());
            printf("Fibonacci numbers : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", fibonacci_arr[i]);
            }
            printf("\n");
        }
    }
double end = omp_get_wtime();
printf("Time Taken to Execute : %f\n", (end - start));

}
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{
    int num, i;

    printf("Enter the number of steps : ");
    scanf("%d", &num);

    double step = 1.0 / (double)num;
    double pi = 0.0;

    omp_set_num_threads(num);
    double start = omp_get_wtime();

#pragma omp parallel for
    for (i = 0; i < num; i++)
    {
        double x = (i + 0.5) * step;
        double local_pi = (4.0 * step) / (1 + x * x);
#pragma omp atomic
        pi += local_pi;
    }
    double end = omp_get_wtime();

    printf("Time taken : %lf seconds\n", (end - start));
    printf("The value of PI : %lf\n", pi);
}
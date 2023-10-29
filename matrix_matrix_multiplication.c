#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void main()
{
    int n;
    printf("Enter the dimension of square matrices : ");
    scanf("%d", &n);
    int i = 0, j = 0, k = 0;
    int matrix_one[n][n];
    int matrix_two[n][n];
    int result_matrix[n][n];

#pragma omp parallel private(j)
    {
#pragma omp for
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {

                matrix_one[i][j] = rand() % 100;
                matrix_two[i][j] = rand() % 100;
            }
        }
    }

    double start_parallel = omp_get_wtime();
#pragma omp parallel private(j, k)
    {
#pragma omp for
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                result_matrix[i][j] = 0;
                for (k = 0; k < n; k++)
                {
                    result_matrix[i][j] += matrix_one[i][k] * matrix_two[k][j];
                }
            }
        }
    }
    double end_parallel = omp_get_wtime();
    printf("Time taken by parellel Algorithm : %lf\n", (end_parallel - start_parallel));

    double start = omp_get_wtime();

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            result_matrix[a][b] = 0;
            for (int c = 0; c < n; c++)
            {
                result_matrix[a][b] += matrix_one[a][c] * matrix_two[c][b];
            }
        }
    }
    double end = omp_get_wtime();

    printf("Time taken by sequential Algorithm : %lf\n", (end - start));
}

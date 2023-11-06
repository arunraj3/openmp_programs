#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{
    int matrix_row_size, vector_size;

    printf("Enter the size of Matrix : ");
    scanf("%d", &matrix_row_size);

    printf("Enter the size of Vector : ");
    scanf("%d", &vector_size);

    if (matrix_row_size != vector_size)
    {
        printf("Multiplication is not possible!");
        exit(0);
    }
    
    int matrix[matrix_row_size][matrix_row_size];
    int vector[vector_size], resultant[matrix_row_size];
double start = omp_get_wtime();
#pragma omp parallel
    {
        for (int row = 0; row < matrix_row_size; row++)
        {
            srand(row); // just to randomise the initial state of generating random numbers
            vector[row] = rand() % 100;
            for (int column = 0; column < matrix_row_size; column++)
            {
                matrix[row][column] = rand() % 100;
            }
        }
    }

#pragma omp parallel
    {
        for (int row = 0; row < matrix_row_size; row++)
        {
            resultant[row] = 0;
            for (int column = 0; column < matrix_row_size; column++)
            {
                resultant[row] += matrix[row][column] * vector[row];
            }
        }
    }
double end = omp_get_wtime();
    printf("Matrix * Vector = Resultant\n");
    for (int row = 0; row < matrix_row_size; row++)
    {
        printf("[");
        for (int column = 0; column < matrix_row_size; column++)
        {
            printf("%3d ", matrix[row][column]);
        }
        printf("]");
        printf(" * %3d = %6d\n", vector[row], resultant[row]);
    }
    printf("Time Taken to Execute : %ld\n",(double) (end - start));
}
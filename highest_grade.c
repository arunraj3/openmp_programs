#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{
    int n, i;
    printf("Enter number of students : ");
    scanf("%d", &n);
    double cgpa_arr[n];
    double max_cgpa = 0;
    double start = omp_get_wtime();

#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        cgpa_arr[i] = (double)(rand() % 100) / 10;
    }
    printf("CGPA of students : ");
    for (i = 0; i < n; i++)
    {
        printf("%lf ", cgpa_arr[i]);
    }
    printf("\n");
#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
#pragma omp critical
        if (max_cgpa < cgpa_arr[i])
        {
            max_cgpa = cgpa_arr[i];
        }
    }
    double end = omp_get_wtime();
    printf("Student with highest CGPA = %.2lf\n", max_cgpa);
    printf("Time taken : %lf seconds\n", (end - start));
}
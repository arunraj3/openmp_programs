#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{

    omp_set_num_threads(4);
    srand(10);
    int global_sum = 0, clothing_total = 0, gaming_total = 0, grocery_total = 0, stationary_total = 0;

    int clothing_items_count = rand() % 20;
    printf("Number of Clothing items : %d\n", clothing_items_count);
    int gaming_items_count = rand() % 20;
    printf("Number of Gaming items : %d\n", gaming_items_count);
    int grocery_items_count = rand() % 20;
    printf("Number of Grocery items : %d\n", grocery_items_count);
    int stationary_items_count = rand() % 20;
    printf("Number of Stationary items : %d\n", stationary_items_count);

    int clothing_items_cost[clothing_items_count], gaming_items_cost[gaming_items_count];
    int grocery_items_cost[grocery_items_count], stationary_items_cost[stationary_items_count];

    for (int i = 0; i < clothing_items_count; i++)
    {
        clothing_items_cost[i] = rand() % 100;
    }
    printf("Clothing items costs\n");

    for (int i = 0; i < clothing_items_count; i++)
    {
        printf("%d ", clothing_items_cost[i]);
    }
    printf("\n");

    for (int i = 0; i < gaming_items_count; i++)
    {
        gaming_items_cost[i] = rand() % 100;
    }
    printf("Gaming items costs\n");

    for (int i = 0; i < gaming_items_count; i++)
    {
        printf("%d ", gaming_items_cost[i]);
    }
    printf("\n");
    for (int i = 0; i < grocery_items_count; i++)
    {
        grocery_items_cost[i] = rand() % 100;
    }
    printf("Grocery items costs\n");

    for (int i = 0; i < grocery_items_count; i++)
    {
        printf("%d ", grocery_items_cost[i]);
    }
    printf("\n");
    for (int i = 0; i < stationary_items_count; i++)
    {
        stationary_items_cost[i] = rand() % 100;
    }
    printf("Stationary items costs\n");

    for (int i = 0; i < stationary_items_count; i++)
    {
        printf("%d ", stationary_items_cost[i]);
    }
    printf("\n");
    double start = omp_get_wtime();
#pragma omp parallel firstprivate(clothing_total, gaming_total, grocery_total, stationary_total)
    {
        int thread_num = omp_get_thread_num();

        if (thread_num == 0)
        {
            for (int i = 0; i < clothing_items_count; i++)
            {
                clothing_total += clothing_items_cost[i];
            }
            printf(" Thread id  %d, Total clothing_total = %d \n", omp_get_thread_num(), clothing_total);
        }
        if (thread_num == 1)
        {
            for (int i = 0; i < gaming_items_count; i++)
            {
                gaming_total += gaming_items_cost[i];
            }
            printf(" Thread id  %d, Total gaming_total = %d \n", omp_get_thread_num(), gaming_total);
        }
        if (thread_num == 2)
        {
            for (int i = 0; i < grocery_items_count; i++)
            {
                grocery_total += grocery_items_cost[i];
            }
            printf(" Thread id  %d, Total grocery_total = %d \n", omp_get_thread_num(), grocery_total);
        }
        if (thread_num == 3)
        {
            for (int i = 0; i < grocery_items_count; i++)
            {
                stationary_total += stationary_items_cost[i];
            }
            printf(" Thread id  %d, Total stationary_total = %d \n", omp_get_thread_num(), stationary_total);
        }

#pragma omp critical
        {
            global_sum += clothing_total + gaming_total + grocery_total + stationary_total;
        }
    }
    double end = omp_get_wtime();
    printf("The Total cost : %d\n", global_sum);
    printf("Time Taken to Execute : %f\n",(double)(end - start));
}
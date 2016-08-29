//
// Created by marcoslopez7 on 26/08/16.
//

#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

#define N 100000000

void fillArray(int *);
void sumArray(int *, int *, int *);
void printArray(int *);

int main(){

    double total_t, total_c;
    clock_t start_t, end_c, end_t;

    int *arrayA = (int *) malloc(sizeof(int) * N);
    int *arrayB = (int *) malloc(sizeof(int) * N);
    int *result = (int *) malloc(sizeof(int) * N);

    fillArray(arrayA);
    fillArray(arrayB);

    start_t = clock();
    sumArray(arrayA, arrayB, result);
    end_c = clock();

    printArray(result);

    total_c = (double) (end_c - start_t) / (CLOCKS_PER_SEC / 1000);
    printf("Tiempo total de la suma: %f milisegundos\n", total_c);

    free(arrayA);
    free(arrayB);
    free(result);

    end_t = clock();
    total_t = (double) (end_t - start_t) / (CLOCKS_PER_SEC / 1000);
    printf("Tiempo total del programa: %f milisegundos\n", total_t);
    return 0;
}

void fillArray(int *array){

    int *a = array;
    int i;

    for (i = 0; i < N; ++i) {
        *a = i + 1;
        a++;
    }

}

void sumArray(int *arrA, int *arrB, int *result) {

    #pragma omp parallel for
    for (int i = 0; i < N; ++i)
    {
        result[i] = arrA[i] + arrB[i];
    }

}

void printArray(int *arr) {

    int *a = arr;

    for (int i = 0; i < N; ++i) {
        printf("resultado[%d] = %d\n", i, *a);
        a++;
    }

}
/*
	A01020023 Marcos López
*/

#include <stdio.h>
#include <cstdlib>
#include <time.h>

#define N 500000000

void sumArray(int *, int *, int *);
void fillArray(int *);
void printArray(int *);

int main() {

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

    total_c = (double) (end_c - start_t) / (CLOCKS_PER_SEC / 1000);

//   printArray(result);

    printf("Tiempo del calculo de la suma: %f milisegundos\n", total_c);

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

    int i;
    int *a = arrA;
    int *b = arrB;
    int *r = result;

    for (i = 0; i < N; ++i) {
        *r = *a + *b;
        r++;
        a++;
        b++;
    }

}

void printArray(int *arr) {

    int *a = arr;

    for (int i = 0; i < N; ++i) {
        printf("resultado[%d] = %d\n", i, *a);
        a++;
    }

}

#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n = 1000000000;
    int* arr = malloc(n * sizeof(int));

    #pragma omp parallel for
    for (int i=0; i<n ; i++) {
        arr[i] = i;
    }

    free(arr);
}
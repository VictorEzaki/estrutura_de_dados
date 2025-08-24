#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int cmpDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);

    int *pares = malloc(N * sizeof(int));
    int *impares = malloc(N * sizeof(int));
    int p = 0, i = 0;

    for (int j = 0; j < N; j++) {
        int num;
        scanf("%d", &num);
        if (num % 2 == 0)
            pares[p++] = num;
        else
            impares[i++] = num;
    }

    qsort(pares, p, sizeof(int), cmpAsc);
    qsort(impares, i, sizeof(int), cmpDesc);

    for (int j = 0; j < p; j++) printf("%d\n", pares[j]);
    for (int j = 0; j < i; j++) printf("%d\n", impares[j]);

    free(pares);
    free(impares);

    return 0;
}
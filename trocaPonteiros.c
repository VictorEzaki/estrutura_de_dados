#include <stdio.h>

int main() {
    int a = 10;
    int *ptrA = &a;
    int b = 20;
    int *ptrB = &b;
    int aux;

    printf("A antes da troca: %d\n", a);
    printf("B antes da troca: %d\n", b);
    
    aux = *ptrB;
    *ptrB = *ptrA;
    *ptrA = aux;

    printf("A depois da troca: %d\n", a);
    printf("B depois da troca: %d\n", b);

    return 0;
}
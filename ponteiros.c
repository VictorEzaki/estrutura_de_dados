#include <stdio.h>

int main()
{
    int valor = 10;
    int *ptrValor = &valor;

    printf("Valor: %d\n", valor);
    printf("Endereco: %x\n", ptrValor);
}
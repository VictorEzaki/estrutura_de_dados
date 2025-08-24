#include <stdio.h>
#include <math.h>

int main() {
    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[6] = {100, 50, 25, 10, 5, 1};
    double input;
    int qtde, valor;

    scanf("%lf", &input);

    valor = round(input * 100);

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++)
    {
        qtde = valor / notas[i];
        printf("%d nota(s) de R$ %.2lf\n", qtde, (notas[i] / 100.0));
        valor %= notas[i];
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++)
    {
        qtde = valor / moedas[i];
        printf("%d moeda(s) de R$ %.2lf\n", qtde, (moedas[i] / 100.0));
        valor %= moedas[i];
    }

    return 0;
}
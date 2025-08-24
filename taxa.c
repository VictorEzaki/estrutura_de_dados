#include <stdio.h>

int main() {
    double salario;
    scanf("%lf", &salario);

    if (salario <= 2000.0) {
        printf("Isento\n");
    } else {
        double imposto = 0.0;

        if (salario > 4500.0) {
            imposto += (salario - 4500.0) * 0.28;
            salario = 4500.0;
        }
        if (salario > 3000.0) {
            imposto += (salario - 3000.0) * 0.18;
            salario = 3000.0;
        }
        if (salario > 2000.0) {
            imposto += (salario - 2000.0) * 0.08;
        }

        printf("R$ %.2lf\n", imposto);
    }

    return 0;
}

/*
beecrowd 1069
Diamantes e Areia
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>".
Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante,
novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados.
O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando
.<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém
até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
*/

#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++)
    {
        char mina[1001];
        fgets(mina, sizeof(mina), stdin);

        int j = 0, diamantes = 0, aberto = 0;

        while (mina[j] != '\0')
        {
            if (mina[j] == '<')
            {
                aberto++;
            }
            else if (mina[j] == '>')
            {
                if (aberto > 0)
                {
                    aberto--;
                    diamantes++;
                }
            }
            j++;
        }
        printf("%d\n", diamantes);
    }

    return 0;
}
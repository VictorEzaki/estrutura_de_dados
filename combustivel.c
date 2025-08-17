/*
Tipo de Combustível
Um Posto de combustíveis deseja determinar qual de seus produtos tem a preferência de seus clientes.
Escreva um algoritmo para ler o tipo de combustível abastecido (codificado da seguinte forma: 1.Álcool 2.Gasolina 3.Diesel 4.Fim).
Caso o usuário informe um código inválido (fora da faixa de 1 a 4) deve ser solicitado um novo código (até que seja válido).
O programa será encerrado quando o código informado for o número 4.

Entrada
A entrada contém apenas valores inteiros e positivos.

Saída
Deve ser escrito a mensagem: "MUITO OBRIGADO" e a quantidade de clientes que abasteceram cada tipo de combustível, conforme exemplo.

Exemplo de Entrada		Exemplo de Saída
8							MUITO OBRIGADO
1							Alcool: 1
7							Gasolina: 2
2							Diesel: 0
2
4
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("chcp 65001");

    int option = 0, ret, qtdeAbastecimentos[3] = {0, 0, 0};

    do
    {
        printf("+------------------------------+\n");
        printf("|             Posto            |\n");
        printf("+------------------------------+\n");
        printf("| [1] Álcool                   |\n");
        printf("| [2] Gasolina                 |\n");
        printf("| [3] Diesel                   |\n");
        printf("| [4] Fim                      |\n");
        printf("+------------------------------+\n");
        ret = scanf("%d", &option);

        if (ret != 1)
        {
            printf("Insira um valor válido!\n");
            while(getchar() != '\n');
        }
        else
        {
            switch (option)
            {
            case 1:
                qtdeAbastecimentos[0]++;
                break;

            case 2:
                qtdeAbastecimentos[1]++;
                break;

            case 3:
                qtdeAbastecimentos[2]++;
                break;

            case 4:
                printf("MUITO OBRIGADO\n");
                printf("Álcool: %d\n", qtdeAbastecimentos[0]);
                printf("Gasolina: %d\n", qtdeAbastecimentos[1]);
                printf("Diesel: %d\n", qtdeAbastecimentos[2]);
                break;

            default:
                printf("Insira uma opção válida!\n");
                break;
            }
        }
    } while (option != 4);
}
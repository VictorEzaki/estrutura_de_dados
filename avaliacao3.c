// Enunciado

// Elabore um programa que permita ao usuário inserir as notas dos alunos e, em seguida, organize essas notas em ordem crescente, utilizando o algoritmo de ordenação por seleção. O programa deve:

// Solicitar ao usuário que insira a quantidade de notas e, em seguida, as notas dos alunos.
// Ordenar as notas em ordem crescente, utilizando o algoritmo de ordenação por seleção.
// Exibir a lista de notas ordenadas.

// Requisitos

// Utilize o algoritmo de ordenação por seleção para ordenar as notas.
// O programa deve ser capaz de lidar com qualquer quantidade de notas inseridas pelo usuário.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TAM_NOME 50

typedef struct
{
    char nome[TAM_NOME];
    float nota;
} Aluno;

Aluno *selectionSort(Aluno *boletim, int tamanho)
{
    int menor;
    Aluno aux;

    for (int i = 0; i < tamanho - 1; i++)
    {
        menor = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (boletim[j].nota < boletim[menor].nota)
            {
                menor = j;
            }
        }

        aux = boletim[i];
        boletim[i] = boletim[menor];
        boletim[menor] = aux;
    }
}

void renderizarBoletim(Aluno *boletim, int tamanho)
{
    system("cls");
    printf("+-----------------------------------------------+\n");
    printf("|                   - Boletim -                 |\n");
    printf("+-----------------------------------------------+\n");
    printf("|             Aluno             |      Nota     |\n");
    printf("+-------------------------------+---------------+\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("| %-29s | %13.2f |\n", boletim[i].nome, boletim[i].nota);

        if (i < tamanho -1)
        {
            printf("+-------------------------------+---------------+\n");
        }else {

            printf("+-----------------------------------------------+\n");
        } 
    } 
}

int main()
{
    system("chcp 65001");

    int qtdNotas = 0;
    printf("Quantas notas serão lançadas?");
    scanf("%d", &qtdNotas);

    Aluno boletim[qtdNotas];

    for (int i = 0; i < qtdNotas; i++)
    {
        system("cls");

        printf("Digite o nome do aluno: ");
        scanf("%s", &boletim[i].nome);
        getchar();

        printf("Digite a nota do %s: ", boletim[i].nome);
        scanf("%f", &boletim[i].nota);
        getchar();
    }

    selectionSort(boletim, qtdNotas);
    renderizarBoletim(boletim, qtdNotas);

    return 0;
}
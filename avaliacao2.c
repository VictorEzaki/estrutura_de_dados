#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 50

typedef struct Node
{
    char pedido[TAM_STR];
    struct Node *prox;
} Node;

typedef struct
{
    Node *frente;
    Node *tras;
    int qtd;
} Pedidos;

void inicializarFila(Pedidos *p)
{
    p->frente = NULL;
    p->tras = NULL;
    p->qtd = 0;
}

void enqueue(Pedidos *p, const char *pedido)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL)
    {
        printf("Erro de alocação!\n");
        return;
    }
    strcpy(novo->pedido, pedido);
    novo->prox = NULL;

    if (p->tras == NULL)
    {
        p->frente = novo;
        p->tras = novo;
    }
    else
    {
        p->tras->prox = novo;
        p->tras = novo;
    }

    p->qtd++;
}

void dequeue(Pedidos *p)
{
    if (p->frente == NULL)
    {
        printf("A fila de pedidos está vazia, incapaz de processar!");
        return;
    }
    
    Node *remover = p->frente;
    printf("Pedido processado: %s", remover->pedido);
    p->frente = p->frente->prox;
    free(remover);

    p->qtd--;

    if (p->frente == NULL)
    {
        p->tras = NULL;
    }
    
}

void main()
{
    system("chcp 65001");

    int option = 0;
    char pedido[TAM_STR];

    Pedidos pedidos;
    inicializarFila(&pedidos);

    while (option != 4)
    {
        printf("+--------------------------------------+\n");
        printf("|                Pedidos               |\n");
        printf("+--------------------------------------+\n");
        printf("| [1] Adicionar pedido                 |\n");
        printf("| [2] Processar pedido                 |\n");
        printf("| [3] Exibir pedidos                   |\n");
        printf("| [4] Encerrar                         |\n");
        printf("+--------------------------------------+\n");

        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:

            system("cls");

            printf("+--------------------------------------+\n");
            printf("|                Pedido                |\n");
            printf("+--------------------------------------+\n");
            printf("Nome para o pedido: ");
            fgets(pedido, TAM_STR, stdin);

            enqueue(&pedidos, pedido);

            break;

        case 2:

            dequeue(&pedidos);

            break;

        case 3:

            system("cls");

            Node *atual = pedidos.frente;
            int i = 0;
            while (atual != NULL)
            {
                printf("Pedido %d: %s\n", i + 1, atual->pedido);
                atual = atual->prox;
                i++;
            }

            break;

        case 4:

            printf("Encerrando...");

            break;

        default:

            printf("Digite uma opção válida!");

            break;
        }
    }
}
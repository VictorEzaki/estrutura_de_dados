#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro
{
    char titulo[100];
    char autor[100];
    int ano;
    int emprestado;
    struct Livro *prox;
} Livro;

typedef struct Emprestimo
{
    char titulo[100];
    char usuario[100];
    char data[20];
    struct Emprestimo *prox;
} Emprestimo;

void cadastrarLivro(Livro **lista)
{
    Livro *novo = malloc(sizeof(Livro));

    printf("Título: ");
    scanf(" %[^\n]s", novo->titulo);

    printf("Autor: ");
    scanf(" %[^\n]s", novo->autor);

    printf("Ano: ");
    scanf("%d", &novo->ano);

    novo->emprestado = 0;
    novo->prox = *lista;
    *lista = novo;

    printf("Livro cadastrado!\n");
}

void ordenarLivros(Livro **lista)
{
    if (*lista == NULL || (*lista)->prox == NULL)
        return;

    int trocou;
    Livro *atual;
    Livro *prox;

    do
    {
        trocou = 0;
        atual = *lista;

        while (atual->prox != NULL)
        {
            prox = atual->prox;

            if (strcmp(atual->titulo, prox->titulo) > 0)
            {

                Livro temp = *atual;
                *atual = *prox;
                *prox = temp;

                Livro *tmp_prox = atual->prox;
                atual->prox = prox->prox;
                prox->prox = tmp_prox;

                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);

    printf("Livros ordenados por título!\n");
}

void emprestarLivro(Livro *lista, Emprestimo **emprestimos)
{
    char titulo[100];
    printf("Título do livro para empréstimo: ");
    scanf(" %[^\n]s", titulo);

    Livro *atual = lista;

    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            if (atual->emprestado == 1)
            {
                printf("Livro já está emprestado!\n");
                return;
            }

            atual->emprestado = 1;

            Emprestimo *novo = malloc(sizeof(Emprestimo));
            strcpy(novo->titulo, atual->titulo);

            printf("Nome do usuário: ");
            scanf(" %[^\n]s", novo->usuario);

            printf("Data do empréstimo: ");
            scanf(" %[^\n]s", novo->data);

            novo->prox = *emprestimos;
            *emprestimos = novo;

            printf("Empréstimo registrado!\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Livro não encontrado!\n");
}

void devolverLivro(Livro *lista, Emprestimo **emprestimos)
{
    char titulo[100];
    printf("Título do livro para devolução: ");
    scanf(" %[^\n]s", titulo);

    Livro *atual = lista;

    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            if (atual->emprestado == 0)
            {
                printf("Este livro não está emprestado!\n");
                return;
            }

            atual->emprestado = 0;

            Emprestimo *ant = NULL;
            Emprestimo *e = *emprestimos;

            while (e != NULL)
            {
                if (strcmp(e->titulo, titulo) == 0)
                {
                    if (ant == NULL)
                        *emprestimos = e->prox;
                    else
                        ant->prox = e->prox;

                    free(e);
                    printf("Livro devolvido e empréstimo removido!\n");
                    return;
                }
                ant = e;
                e = e->prox;
            }
        }
        atual = atual->prox;
    }

    printf("Livro não encontrado!\n");
}

void listarLivros(Livro *lista)
{
    if (lista == NULL)
    {
        printf("Nenhum livro cadastrado!\n");
        return;
    }

    Livro *atual = lista;
    printf("\n--- Lista de Livros ---\n");

    while (atual != NULL)
    {
        printf("Título: %s\n", atual->titulo);
        printf("Autor: %s\n", atual->autor);
        printf("Ano: %d\n", atual->ano);
        printf("Status: %s\n\n", atual->emprestado ? "Emprestado" : "Disponível");
        atual = atual->prox;
    }
}

void listarEmprestimos(Emprestimo *lista)
{
    if (lista == NULL)
    {
        printf("Nenhum empréstimo registrado.\n");
        return;
    }

    printf("\n--- Empréstimos ---\n");

    Emprestimo *atual = lista;
    while (atual != NULL)
    {
        printf("Título: %s\n", atual->titulo);
        printf("Usuário: %s\n", atual->usuario);
        printf("Data: %s\n\n", atual->data);
        atual = atual->prox;
    }
}

int main()
{
    system("chcp 65001");

    Livro *livros = NULL;
    Emprestimo *emprestimos = NULL;
    int option;

    do
    {
        printf("+---------------------------------------+\n");
        printf("|              - Biblioteca -           |\n");
        printf("+---------------------------------------+\n");
        printf("| [1] Cadastrar novo livro              |\n");
        printf("| [2] Listar livros                     |\n");
        printf("| [3] Ordenar livros por título         |\n");
        printf("| [4] Emprestar livro                   |\n");
        printf("| [5] Devolver livro                    |\n");
        printf("| [6] Listar empréstimos                |\n");
        printf("| [7] Sair                              |\n");
        printf("+---------------------------------------+\n");
        printf("Escolha: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            cadastrarLivro(&livros);
            break;

        case 2:
            listarLivros(livros);
            break;

        case 3:
            ordenarLivros(&livros);
            break;

        case 4:
            emprestarLivro(livros, &emprestimos);
            break;

        case 5:
            devolverLivro(livros, &emprestimos);
            break;

        case 6:
            listarEmprestimos(emprestimos);
            break;

        case 7:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Escolha uma opção válida!\n");
            break;
        }
    } while (option != 7);

    return 0;
}
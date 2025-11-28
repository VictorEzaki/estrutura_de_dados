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

int validarOptionMenu()
{
    char entrada[20];

    printf("Escolha: ");
    fgets(entrada, sizeof(entrada), stdin);

    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (entrada[i] == '\n')
            break;

        if (entrada[i] < '0' || entrada[i] > '9')
        {
            return -1;
        }
    }

    return atoi(entrada);
}

void validarString(char *destino, int max)
{
    char buffer[500];

    while (1)
    {
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) >= max)
        {
            printf("Entrada muito longa! Digite no máximo %d caracteres: ", max);
            continue;
        }

        strcpy(destino, buffer);
        break;
    }
}

void cadastrarLivro(Livro **lista)
{
    Livro *novo = malloc(sizeof(Livro));
    if (!novo)
    {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Título: ");
    validarString(novo->titulo, sizeof(novo->titulo));

    printf("Autor: ");
    validarString(novo->autor, sizeof(novo->autor));

    printf("Ano: ");
    while (scanf("%d", &novo->ano) != 1) {
        printf("Ano inválido! Digite novamente: ");
        while (getchar() != '\n');
    }

    novo->emprestado = 0;
    novo->prox = *lista;
    *lista = novo;

    printf("Livro cadastrado!\n");
}

Livro *merge(Livro *esq, Livro *dir)
{

    if (!esq)
        return dir;
    if (!dir)
        return esq;

    Livro *resultado = NULL;

    if (strcmp(esq->titulo, dir->titulo) <= 0)
    {

        resultado = esq;

        resultado->prox = merge(esq->prox, dir);
    }
    else
    {

        resultado = dir;

        resultado->prox = merge(esq, dir->prox);
    }

    return resultado;
}

void dividir(Livro *lista, Livro **esq, Livro **dir)
{

    if (lista == NULL || lista->prox == NULL)
    {
        *esq = lista;
        *dir = NULL;
        return;
    }

    Livro *lento = lista;
    Livro *rapido = lista->prox;

    while (rapido != NULL)
    {
        rapido = rapido->prox;
        if (rapido != NULL)
        {
            lento = lento->prox;
            rapido = rapido->prox;
        }
    }

    *esq = lista;
    *dir = lento->prox;
    lento->prox = NULL;
}

Livro *mergeSort(Livro *lista)
{

    if (!lista || !lista->prox)
        return lista;

    Livro *esq;
    Livro *dir;

    dividir(lista, &esq, &dir);

    esq = mergeSort(esq);
    dir = mergeSort(dir);

    return merge(esq, dir);
}

void ordenarLivros(Livro **lista)
{
    *lista = mergeSort(*lista);
    printf("Livros ordenados por título usando MergeSort!\n");
}

void emprestarLivro(Livro *lista, Emprestimo **emprestimos)
{
    char titulo[100];
    printf("Título do livro para empréstimo: ");
    validarString(titulo, sizeof(titulo));

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
            validarString(novo->usuario, sizeof(novo->usuario));

            printf("Data do empréstimo: ");
            validarString(novo->data, sizeof(novo->data));

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
    validarString(titulo, sizeof(titulo));

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

    Livro *atual;

    printf("\n===== LIVROS DISPONÍVEIS =====\n");
    atual = lista;
    int achouDisponivel = 0;

    while (atual != NULL)
    {
        if (atual->emprestado == 0)
        {
            printf("Título: %s\n", atual->titulo);
            printf("Autor: %s\n", atual->autor);
            printf("Ano: %d\n", atual->ano);
            printf("Status: Disponível\n\n");
            achouDisponivel = 1;
        }
        atual = atual->prox;
    }

    if (!achouDisponivel)
        printf("Nenhum livro disponível.\n");

    printf("\n===== LIVROS EMPRESTADOS =====\n");
    atual = lista;
    int achouEmprestado = 0;

    while (atual != NULL)
    {
        if (atual->emprestado == 1)
        {
            printf("Título: %s\n", atual->titulo);
            printf("Autor: %s\n", atual->autor);
            printf("Ano: %d\n", atual->ano);
            printf("Status: Emprestado\n\n");
            achouEmprestado = 1;
        }
        atual = atual->prox;
    }

    if (!achouEmprestado)
        printf("Nenhum livro emprestado.\n");
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
        printf("|             - Biblioteca -            |\n");
        printf("+---------------------------------------+\n");
        printf("| [1] Cadastrar novo livro              |\n");
        printf("| [2] Listar livros                     |\n");
        printf("| [3] Ordenar livros por título         |\n");
        printf("| [4] Emprestar livro                   |\n");
        printf("| [5] Devolver livro                    |\n");
        printf("| [6] Listar empréstimos                |\n");
        printf("| [7] Sair                              |\n");
        printf("+---------------------------------------+\n");
        option = validarOptionMenu();

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
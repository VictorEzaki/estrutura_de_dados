#include <stdio.h>

char vetor[1000][20];
int tamanho = 1000;

int menu();
void subMenuInserir();
void subMenuPesquisar();
void subMenuExcluir();
void posicaoLivre(char elemento[]);
void posicaoInformada();
void pesquisaPeloElemento();
void reordenaVetor(int posicao);
void pesquisaPelaPosicao();
void excluirPelaPosicao();
void excluirPeloElemento();
void imprimir();

void main()
{
    menu();
}

// Menus

int menu()
{
    int option;

    do
    {
        printf("+-------------------------------------+\n");
        printf("|         Manipulando um vetor        |\n");
        printf("+-------------------------------------+\n");
        printf("| [1] Inserir um elemento no vetor    |\n");
        printf("| [2] Pesquisar um elemento no vetor  |\n");
        printf("| [3] Excluir um elemento no vetor    |\n");
        printf("| [4] Imprimir o vetor                |\n");
        printf("| [5] Sair um elemento no vetor       |\n");
        printf("+-------------------------------------+\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            subMenuInserir();
            break;
        case 2:
            subMenuPesquisar();
            break;
        case 3:
            subMenuExcluir(); 
            break;
        case 4:
            imprimir();
            break;
        case 5:
            printf("Saindo...\n");
            break;

        default:
            printf("Escolha um opção válida!");
            break;
        }
    } while (option != 5);

    return 0;
}

void subMenuInserir()
{
    char elemento[20];
    int subOption;

    do
    {
        printf("+-------------------------------------+\n");
        printf("|         Manipulando um vetor        |\n");
        printf("+-------------------------------------+\n");
        printf("| [1] Na proxima posicao livre        |\n");
        printf("| [2] Na posicao informada            |\n");
        printf("| [3] Voltar ao menu principal        |\n");
        printf("+-------------------------------------+\n");

        scanf("%d", &subOption);

        switch (subOption)
        {
        case 1:
            printf("Digite uma palavra de ate 19 caracteres: ");
            scanf("%s", &elemento);
            posicaoLivre(elemento);
            break;
        case 2:
            posicaoInformada();
            break;
        case 3:
            printf("Voltando...\n");
            break;

        default:
            printf("Escolha um opção válida!");
            break;
        }
    } while (subOption != 3);
}

void subMenuPesquisar()
{
    int subOption;

    do
    {
        printf("+-------------------------------------+\n");
        printf("|         Manipulando um vetor        |\n");
        printf("+-------------------------------------+\n");
        printf("| [1] Pelo elemento                   |\n");
        printf("| [2] Pela posicao                    |\n");
        printf("| [3] Voltar ao menu principal        |\n");
        printf("+-------------------------------------+\n");

        scanf("%d", &subOption);

        switch (subOption)
        {
        case 1:
            pesquisaPeloElemento();
            break;
        case 2:
            pesquisaPelaPosicao();
            break;
        case 3:
            printf("Voltando...\n");
            break;

        default:
            printf("Escolha um opção válida!");
            break;
        }
    } while (subOption != 3);

}

void subMenuExcluir()
{
    int subOption;

    do
    {
        printf("+-------------------------------------+\n");
        printf("|         Manipulando um vetor        |\n");
        printf("+-------------------------------------+\n");
        printf("| [1] Pelo elemento                   |\n");
        printf("| [2] Pela posicao                    |\n");
        printf("| [3] Voltar ao menu principal        |\n");
        printf("+-------------------------------------+\n");

        scanf("%d", &subOption);

        switch (subOption)
        {
        case 1:
            excluirPeloElemento();
            break;
        case 2:
            excluirPelaPosicao();
            break;
        case 3:
            printf("Voltando...\n");
            break;

        default:
            printf("Escolha um opção válida!");
            break;
        }
    } while (subOption != 3);
}

// Funcionalidades

void posicaoLivre(char elemento[])
{
    int j = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i][0] == '\0')
        {
            while (elemento[j] != '\0')
            {
                vetor[i][j] = elemento[j];
                j++;
            }
            printf("\nPalavra inserida com sucesso!\n\n\n");
            break;
        }
        else if (i == (tamanho - 1))
        {
            printf("\nNao possui espaco suficiente!\n");
        }
    }
}

void posicaoInformada()
{
    int posicao;
    int j = 0;
    int i = 0;
    char elemento[20];
    char auxiliar[20];

    printf("Digite a posicao que deseja inserir de 1 ate 1000: ");
    scanf("%d", &posicao);

    printf("\n\nDigite a palavra que deseja inserir: ");
    scanf("%s", &elemento);

    if (vetor[posicao - 1][0] != '\0')
    {
        while (vetor[posicao - 1][i] != '\0')
        {
            auxiliar[i] = vetor[posicao - 1][i];
            vetor[posicao - 1][i] = elemento[i];

            i++;
        }
        posicaoLivre(auxiliar);
    }
    else
    {
        while (elemento[j] != '\0')
        {
            vetor[posicao - 1][j] = elemento[j];
            j++;
        }

        printf("\nPalavra inserida com sucesso!\n\n\n");
    }
}

void pesquisaPeloElemento()
{
    char elemento[20];
    int elementoExiste = 1;

    printf("\nDigite por qual elemento deseja buscar: ");
    scanf("%s", &elemento);

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; vetor[i][j] != '\0' || elemento[j] != '\0'; j++)
        {
            if (vetor[i][j] != elemento[j])
            {
                elementoExiste = 0;
                break;
            }
            else
            {
                elementoExiste = 1;
            }
        }

        if (elementoExiste)
        {
            printf("%s se encontra na posicao %d\n", vetor[i], (i + 1));
        }
    }
}

void pesquisaPelaPosicao()
{
    int posicao;

    printf("\nDigite a posicao que deseja pesquisar: ");
    scanf("%d", &posicao);

    if (vetor[posicao - 1][0] != '\0')
    {
        printf("\nna posicao %d tem o elemento %s\n", posicao, vetor[posicao - 1]);
    }
    else
    {
        printf("\nEssa posicao não possui nenhum elemento.\n");
    }
}

void excluirPeloElemento()
{
    char elemento[20];
    int elementoExiste = 1;
    int k = 0;

    printf("\nDigite por qual elemento deseja buscar: ");
    scanf("%s", &elemento);

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; vetor[i][j] != '\0' || elemento[j] != '\0'; j++)
        {
            if (vetor[i][j] != elemento[j])
            {
                elementoExiste = 0;
                break;
            }
            else
            {
                elementoExiste = 1;
                vetor[i][0] = '\0';
            }
        }

        if (elementoExiste)
        {
            reordenaVetor(i);
        }
    }
}

void reordenaVetor(int posicao)
{
    int j = 0;
    for (int i = posicao; i < tamanho; i++)
    {
        if (vetor[i][0] != '\0')
        {
            while (vetor[i][j] != '\0')
            {
                vetor[i - 1][j] = vetor[i][j];
                j++;
            }
            vetor[i][0] = '\0';
        }
    }
}

void excluirPelaPosicao()
{
    int posicao;

    printf("\nDigite a posicao que deseja pesquisar: ");
    scanf("%d", &posicao);

    if (vetor[posicao - 1][0] != '\0')
    {
        vetor[posicao - 1][0] = '\0';
        reordenaVetor(posicao - 1);
    }
    else
    {
        printf("\nEssa posicao não possui nenhum elemento.\n");
    }
}

void imprimir()
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i][0] != '\0')
        {
            printf("%d - %s \n", (i + 1), vetor[i]);
        }
    }
}
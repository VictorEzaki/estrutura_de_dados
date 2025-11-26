#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idLivro;
    char titulo[50];
    char autor[50];
    int anoPublicacao;
    int status; // 1 = disponível, 0 = emprestado
} livro;

typedef struct
{
    int idLivro;
    char tituloLivro[50];
    char usuario[50];
    char dataEmprestimo[11];
    char dataDevolucao[11];
} emprestimo;

int main()
{
    system("chcp 65001");

    int option = 0;

    do
    {
        printf("+-----------------------------------------+\n");
        printf("|               - Biblioteca -            |\n");
        printf("+-----------------------------------------+\n");
        printf("| [1] Cadastrar livro                     |\n");
        printf("| [2] Empréstimo                          |\n");
        printf("| [3] Devolução                           |\n");
        printf("| [4] Lista de livros                     |\n");
        printf("| [5] Sair                                |\n");
        printf("+-----------------------------------------+\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            
            break;
        
        case 2:
            
            break;
        
        case 3:
            
            break;
        
        case 4:
            
            break;
        
        case 5:
            printf("Encerrando o programa...\n");
            
            break;
        
        default:
            printf("Escolha uma opção válida!\n");
            break;
        }
    } while (option != 5);
    
    return 0;
}
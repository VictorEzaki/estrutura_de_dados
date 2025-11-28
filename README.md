# 📄 Relatório do Sistema de Gerenciamento de Biblioteca

## 1. Introdução
Este relatório descreve o funcionamento de um sistema de gerenciamento de biblioteca desenvolvido em linguagem C. O objetivo principal é permitir o cadastro de livros, controle de empréstimos e ordenação da lista de livros com base em seus títulos. O texto abrange a justificativa da escolha das estruturas de dados, o funcionamento geral do sistema e a explicação detalhada do algoritmo de ordenação utilizado.

---

## 2. Estrutura de Dados Utilizada

### 2.1 Lista Encadeada Simples
O sistema utiliza **listas encadeadas simples** para armazenar duas categorias de dados:

- **Livros**
- **Empréstimos**

Cada elemento (nó) contém informações relevantes e um ponteiro para o próximo da lista.

### 2.2 Estrutura `Livro`
```c
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
```

## 3. Justificativa da Escolha da Estrutura de Dados

A utilização de **listas encadeadas** (em vez de vetores estáticos ou dinâmicos) foi escolhida por diversos motivos:

- ✔ **Uso flexível de memória:** cresce dinamicamente com `malloc`.
- ✔ **Facilidade para percorrer elementos:** ideal para exibição, busca e ordenação.
- ✔ **Adequação ao problema:** o número de livros é variável e desconhecido.

---

## 4. Funcionamento do Sistema

O sistema funciona por meio de um **menu interativo**, onde o solicitante escolhe uma das operações disponíveis.

### 4.1 Cadastro de Livros
- Recebe título, autor e ano.  
- Valida tamanho da entrada com `validarString`.  
- Adiciona o livro no início da lista encadeada.

### 4.2 Listagem de Livros
A listagem separa os livros em:
- **Disponíveis**
- **Emprestados**

Percorrendo toda a lista encadeada.

### 4.3 Ordenação dos Livros
Os livros podem ser ordenados alfabeticamente por título utilizando **MergeSort**, ideal para listas encadeadas.

### 4.4 Empréstimo de Livro
- Busca pelo título usando `strcmp`.  
- Verifica se já está emprestado.  
- Marca como emprestado.  
- Registra o empréstimo na lista de empréstimos.

### 4.5 Devolução de Livro
- Busca o livro.  
- Marca como disponível.  
- Remove o empréstimo correspondente da lista.

### 4.6 Listagem de Empréstimos
Exibe todas as informações armazenadas na lista de empréstimos.

### 4.7 Validação do Menu
`validarOptionMenu` impede que caracteres inválidos causem falhas no programa.

---

## 5. Algoritmo de Ordenação Utilizado: MergeSort

### 5.1 Por que MergeSort?

Pensando que uma biblioteca pode possuir um grande acervo de livros, é importante utilizar um algoritmo de ordenação eficiente para lidar com um volume significativo de dados. Nesse contexto, o MergeSort se destaca como uma ótima escolha, pois utiliza a estratégia de dividir para conquistar e funciona de forma recursiva, mantendo um desempenho consistente mesmo em listas muito extensas.

Além disso, o MergeSort não exige realocação de memória durante o processo de ordenação e se adapta muito bem a listas encadeadas, que foram utilizadas neste projeto. Sua forma de dividir a lista e reorganizar nós apenas ajustando ponteiros torna o algoritmo especialmente eficiente e adequado para esse tipo de estrutura de dados.

## 6. Funcionamento do MergeSort no Sistema

### 6.1 Função `dividir`

Utiliza dois ponteiros:

- **lento:** avança 1 nó por vez.  
- **rápido:** avança 2 nós por vez.  

Quando o ponteiro rápido chega ao fim, o ponteiro lento aponta para o meio da lista, permitindo a divisão.

### 6.2 Função `merge`

Combina duas listas ordenadas em uma só:

- Compara os títulos usando `strcmp`.  
- Escolhe o menor alfabeticamente.  
- Liga os nós de forma ordenada.

### 6.3 Função `mergeSort`

Segue o paradigma *dividir para conquistar*:

1. Divide a lista ao meio.  
2. Ordena recursivamente cada metade.  
3. Junta tudo com `merge`.

---

## 7. Conclusão

O sistema desenvolvido implementa uma solução eficiente e organizada para gerenciamento de livros e empréstimos.  
A escolha de **listas encadeadas** oferece flexibilidade e uso eficiente da memória, enquanto o algoritmo **MergeSort** garante uma ordenação rápida e eficaz.

Além disso, o sistema conta com **validações importantes** que evitam erros comuns na linguagem C, tornando-o robusto e seguro para fins acadêmicos e práticos.
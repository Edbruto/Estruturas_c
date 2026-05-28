// ====================================================
// Prática: sistema de biblioteca parte1
// objetivo: Implementar um sistema de livros usando um 
// array estático.
// ====================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcspn()

// define constantes globais (o que faz o sistema no contador do final dar certo)
#define MAX_LIVROS 50
#define TAM_STRING 100

// Define estrutura de livro
struct livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// limpar buffer de entrada
void LimpezaBuffer(){
    int c;
    //atenção a sintaxe empregada
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal
int main(){

    struct livro biblioteca[MAX_LIVROS];

    int totalLivros = 0;
    int opcao;

    // Laço principal do Menu
    do {

        printf("===============================\n");
        printf("     Biblioteca - Parte 1\n");
        printf("===============================\n");
        printf("1 - cadastrar novo livro:\n");
        printf("2 - ver livros existentes:\n");
        printf("0 - sair:\n");
        printf("--------------------------------\n");
        printf("Escolha uma opcao:\n");

        // Lê a opção do usuário
        scanf("%d", &opcao);

        // Limpa o scanf deixado pelo \n
        LimpezaBuffer();

        // Processamento de opção
        switch (opcao)
        {

        case 1: // CADASTRO DE LIVRO

            printf("--- Cadastro de livro novo ---\n");

            if (totalLivros < MAX_LIVROS) {

                printf("Digite o nome do titulo:\n");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o nome do autor:\n");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite o nome da Editora:\n");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                // Remove o \n deixado pelo fgets() limpando o buffer.
                biblioteca[totalLivros].nome[
                    strcspn(biblioteca[totalLivros].nome, "\n")
                ] = '\0';

                biblioteca[totalLivros].autor[
                    strcspn(biblioteca[totalLivros].autor, "\n")
                ] = '\0';

                biblioteca[totalLivros].editora[
                    strcspn(biblioteca[totalLivros].editora, "\n")
                ] = '\0';

                printf("Digite a edicao:\n");
                scanf("%d", &biblioteca[totalLivros].edicao);

                LimpezaBuffer();

                totalLivros++;
                // totalLivros = totalLivros + 1

                printf("\nLivro cadastrado com sucesso!!!\n");
            }
            else {

                printf("Limite maximo de livros atingido!\n");
            }

            break;

        case 2: // Listagem de livros

            printf("\nLista de livros cadastrados:\n");

            if (totalLivros == 0) {

                printf("No existem livros cadastrados aqui...\n");

            } else {

                // sistema de loop para mostrar os livros
                for (int i = 0; i < totalLivros; i++) {

                    printf("-------------------------\n");
                    printf("LIVRO %d\n", i + 1);
                    printf("NOME: %s\n", biblioteca[i].nome);
                    printf("AUTOR: %s\n", biblioteca[i].autor);
                    printf("EDITORA: %s\n", biblioteca[i].editora);
                    printf("EDIÇÃO: %d\n", biblioteca[i].edicao);
                }

                printf("-----------------------------------\n");

                // pausa antes de ir para próxima tela
                printf("Pressione ENTER para continuar:\n");
                getchar();
            }

            break;

        case 0: // quando finalizar o programa

            printf("Finalizando serviço...\n");

            break;

        default:

            printf("Opcao invalida, tente novamente:\n");
            printf("Pressione ENTER para prosseguir:\n");

            getchar();

            break;
        }

    } while (opcao != 0);

    return 0;
}
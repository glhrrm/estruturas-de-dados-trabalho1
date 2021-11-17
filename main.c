#include <stdio.h>

#define MAX 20

int lista[MAX];
int qtdItens = 0;

main() {
    int posicao;
    int elemento;
    int opcao = -1;
    while (opcao != 0) {
        printf("\n\n*********************\n"
            "\tEscolha uma opcao:\n\n"
            " 1) Consultar posicao\n"
            " 2) Inserir elemento\n"
            " 3) Remover elemento\n"
            " 4) Consultar quantidade de elementos\n"
            " 5) Exibir todos os itens\n"
            " 0) Sair"
            "\n*********************\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                // Consultar posicao
                printf("Informe a posicao: ");
                scanf("%d", &posicao);
                elemento = consultarPosicao(posicao);
                clear();
                if (elemento != NULL) {
                    printf("A posicao [%d] contem o elemento %d.", posicao, elemento);
                } else {
                    printf("A posicao [%d] esta vazia.", posicao); 
                }
                break;
            case 2:
                // Inserir elemento
                printf("Informe a posicao: ");
                scanf("%d", &posicao);
                printf("Informe o elemento: ");
                scanf("%d", &elemento);
                inserir(posicao, elemento);
                clear();
                break;
            case 3:
                // Remover elemento
                printf("Informe a posicao: ");
                scanf("%d", &posicao);
                remover(posicao);
                clear();
                break;
            case 4:
                // Consultar quantidade de elementos
                clear();
                printf("A lista possui %d elementos.", qtdItens);
                break;
            case 5:
                // Exibir todos os itens
                clear();
                exibirItens();
                break;
            case 0:
                // Sair
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

int consultarPosicao(int posicao) {
    if (posicao > qtdItens - 1 || posicao < 0) {
        printf("Posicao invalida!\n");
        return NULL;
    }
    return lista[posicao];
}

void inserir(int posicao, int elemento) {
    if (posicao > MAX - 1 || posicao < 0) {
        printf("Posicao invalida!\n");
        return;
    }
    // TODO: inserir no meio da lista
    lista[posicao] = elemento;
    qtdItens++;
}

void remover(int posicao) {
    // TODO: aprimorar lógica
    lista[posicao] = 0; // Manter 0 como vazio?
    qtdItens--;
}

void exibirItens() {
    if (qtdItens == 0) {
        printf("Lista vazia!\n");
        return;
    }
    int i;
    printf("Itens da lista: [");
    for (i = 0; i < qtdItens; i++) {
        printf("%d", lista[i]);
        if (lista[i + 1] != 0) {
            printf(" ");
        }
    }
    printf("]\n");
}

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
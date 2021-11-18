#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define TRUE 1
#define FALSE 0

int lista[MAX];
int qtdItens = 0;
int comprimento = sizeof(lista);

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
                clear();
                inserir(posicao, elemento);
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
                // sair();
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
    int cont;
    int proximo = qtdItens;

    if (posicao > MAX || posicao < 0) {
        
        printf("Posicao invalida!\n");
        return;

    } else if (estaCheia() == TRUE) {
        
        printf("\n\tERRO: A lista esta cheia\n");
		return;

    } else if (estaVazia() == TRUE) {

         lista[0] = elemento;
         qtdItens++;
         return;

    }else if (lista[posicao] == NULL){

        // for (cont = qtdItens; cont < MAX; cont++)
        // {
        //     lista[cont] = lista[cont + 1];
        // }
        lista[proximo] = elemento; 
        
        //lista[cont]= elemento;//elemento é inserido na posição que o loop parou
	    qtdItens++;
	    printf("\nElemento inserido com sucesso!\n\n");
        printf("\nElemento inserido na posicao[%d]\n", proximo);
        }
        
    // if (posicao <= MAX && posicao >= 0) {
        
    //     for (cont = 0; cont <= MAX; cont++)
    //     {
    //         if(lista[proximo] == '\0'){
    //             lista[proximo] = elemento;
    //             qtdItens++;
    //             break;
    //         }
    //     }
    //     printf("Lista cheia!\n");
    //     return;

    // } else {
    //     printf("Posicao invalida!\n");
    //     return;
    // }

    // }
    // TODO: inserir no meio da lista
    // lista[posicao] = elemento;
    // qtdItens++;
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

int estaCheia(){

    if(qtdItens == MAX){
        printf(":: Lista esta cheia! ::");
        return TRUE;
    }
    return FALSE;
}

int estaVazia(){

    if(qtdItens == 0){
        printf(":: Lista vazia! ::");
        return TRUE;
    }
    return FALSE;
}

// void sair(){
//     exit(0);
// }
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define TRUE 1
#define FALSE 0

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
      " 5) Exibir todos os itens por posicao\n"
      " 0) Sair"
      "\n*********************\n");
    scanf("%d", &opcao);
    switch(opcao) {
      case 1:
        // Consultar posicao
        printf("Informe a posicao (0 a 19): ");
        scanf("%d", &posicao);
        clear();
        elemento = consultarPosicao(posicao);

        if (elemento != NULL || elemento != 0){
            printf("A posicao [%d] contem o elemento %d.", posicao, elemento);
        }
        break;
      case 2:
        // Inserir elemento
        printf("Informe a posicao: ");
        scanf("%d", &posicao);

        if(verificaSePosicaoValida(posicao) == FALSE){
            break;
        }
            printf("Informe o elemento: ");
            scanf("%d", &elemento);
            clear();
            inserir(posicao, elemento);
        break;
      case 3:
        // Remover elemento
        printf("Informe a posicao: ");
        scanf("%d", &posicao);
        clear();
        if (posicao >= MAX || posicao < 0) {
          printf("Posicao invalida!\n");
          break;
        }
        remover(posicao);
        break;
      case 4:
        // Consultar quantidade de elementos
        clear();
        printf("A lista possui %d elementos.", qtdItens);
        break;
      case 5:
        // Exibir todos os itens
        clear();
        exibirItensPorPosicao();
        break;
      case 0:
        // Sair
        break;
      default:
        clear();
        printf("Opcao invalida!\n");
    }
  }
}

int consultarPosicao(int posicao) {
  if (posicao > MAX - 1 || posicao < 0) {
      clear();
      printf("Posicao invalida!\n");
      return NULL;
  } else if (posicao >= qtdItens) {
     printf("A posicao [%d] esta vazia.", posicao);
     return 0; 
  }
  return lista[posicao];
}

int verificaSePosicaoValida(int posicao) {
    if (posicao > MAX - 1 || posicao < 0) {
      clear();
      printf("Posicao invalida!\n");
      return FALSE;
    }
    return TRUE;
}

void inserir(int posicao, int elemento) {
    int cont;
    int proximo = qtdItens;
    int anterior = qtdItens - 1; 

    if (posicao >= MAX || posicao < 0) {
        
        printf("Posicao invalida!\n");
        return;

    } else if (estaCheia()) {
        printf("Lista cheia\n");
		return;
    } else if (estaVazia()) {
         lista[0] = elemento;
         qtdItens++;
         printf("\nElemento inserido com sucesso no inicio da lista\n");
         return;
    } else if (posicao >= qtdItens) {
        lista[proximo] = elemento;
        qtdItens++;
        printf("\nElemento inserido com sucesso na posicao[%d].\n", proximo);
    } else if (&lista[posicao]) {
        for (cont = qtdItens; cont > posicao; cont--) {
            lista[proximo] = lista[anterior];
            proximo--;
            anterior--;
        }
        lista[posicao] = elemento;
        qtdItens++;
        printf("\nElemento inserido com sucesso na posicao[%d].\n", posicao);
    }
}

void remover(int posicao) {
  int cont;
  int proximo = posicao + 1;
  int anterior = qtdItens - 1;

  if (estaVazia()) {
      printf("Lista vazia!\n");
      return;
    } else if (&lista[posicao] && posicao < qtdItens) {
        for (cont = posicao; cont < qtdItens ; cont++) {
            lista[posicao] = lista[proximo];
            posicao++;
            proximo++;
    }
    lista[proximo] = NULL;
    qtdItens--;
    printf("\nElemento removido com sucesso!\n");
    } else {
        printf("\n\tPosicao vazia, nao possui elementos\n");
    }
}

void exibirItensPorPosicao() {
  if (estaVazia()) {
    printf("Lista vazia!\n");
    return;
  }
  int cont;
  printf("Itens da lista:\n");
  for (cont = 0; cont < qtdItens; cont++) {
    printf("\tPosicao [%d] = %d", cont, lista[cont]);
    if (cont + 1 != qtdItens) {
      printf("\n");
    }
  }
}

void clear() {
  #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
  #endif

  #if defined(_WIN32) || defined(_WIN64)
    system("cls");
  #endif
}

int estaCheia() {
  if (qtdItens == MAX) {
    return TRUE;
  }
  return FALSE;
}

int estaVazia() {
  if (qtdItens == 0) {
    return TRUE;
  }
  return FALSE;
}

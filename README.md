
# Estrutura de Dados I - IFRS Campus Porto Alegre


Você precisa armazenar uma lista de códigos numéricos, a capacidade desta lista é de no máximo 20 posições.
Os códigos numéricos são todos inteiros. Os códigos devem ser inseridos conforme informado pelo usuário.
Seu programa deverá permitir:

- **a.** Consultar a posição (0 a 19); imprimir o código numérico na tela.
- **b.** Inserção de um novo elemento na posição indicada pelo usuário; 

    Se o usuário indicar uma posição ocupada, os elementos devem "andar" para o final;
    \
    Se foi inserido na posição 5, o 5º deve ser o 6º, 6º deve ser o 7º.... assim sucessivamente.
    Se o usuário solicitar a inserção em posição ainda não ocupada, o item deverá ser inserido após a última posição ocupada.
- **c.** Retirar um elemento indicado pelo usuário; 
    \
    Se houver elementos posteriores, estes devem tomar a posição que ficou livre;
    \
    Se foi removido o 3º elemento, o 4º deve tomar o seu lugar, o 5º deve se tornar 4º e sucessivamente.
- **d.** Consultar a quantidade de elementos;
- **e.** Exibir todos os itens da lista.

#### Dica: 
i. Usar um vetor de inteiros de 20 posições; 
\
ii. armazenar em um número inteiro a quantidade de elementos ocupados; 
\
iii. se ocupados é igual a zero, significa que o vetor está vazio, se ocupados é igual a 20 significa que a lista está cheia;

#### Para entrega do trabalho:

1 – Implementar um programa que realize estas operações (a,b,c,d,e);

2 – Gravar vídeo de 8 a 15 minutos apresentando o código;

3 – Testar as diferentes possibilidades do programa.
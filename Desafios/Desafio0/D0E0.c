/* Exercício 0

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
devolve 1 se o vetor está em ordem crescente e 0 caso contrário.*/

#include <stdio.h>

#define MAXELEM 10


int checacrescente(int vetor[], int num_elem) {
    int i;
    for(i=1; i<num_elem;i++){
        if(vetor[i-1]>vetor[i]){
            return 0;
        }
    return 1;
    }
}

int main(int argc, char *argv[]) {
  int num_elem;
  int vetor[MAXELEM];
  int i;
  int resp;

  /* Ler numero de elementos. */
  printf("Escreva o numero de elementos do vetor(não pode ser maior que %d): ",MAXELEM);
  scanf("%d", &num_elem);

  if (num_elem <= MAXELEM) {
    /* Ler os elementos. */
    for (i = 0; i < num_elem; i++) {
        scanf("%d", &vetor[i]);
    }
    resp = checacrescente(vetor,num_elem);
    printf("%s\n", resp?"Esta em ordem crescente":"Não esta em ordem crescente");
}
    else{
        printf("Seu Vetor Excedeu o tamanho máximo. \n");
    }
}
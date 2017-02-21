/* Exercício 1

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
preenche o vetor com inteiros aleatórios, sobrescrevendo tudo o que estava nele antes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void preenchevetor (int vetor[],int n){
  int i;
  for(i=0; i< n ; i++){
      vetor[i]= rand() % MAX_NUMBER; //rand ()= Retorna um inteiro entre 0 e RAND_MAX [RAND_MAX is a constant defined in <cstdlib>.](More at: http://www.cplusplus.com/reference/cstdlib/rand/)
      // rand() % MAX_NUMBER = Truque para obter um inteiro aleatório entre 0 e (MAX_NUMBER – 1)
  }
}

int main(void) { 
  srand(time(NULL));//inicializa a maquina de geração de números aleátorios
  int n;
  int i;
  int vetor[MAX_NUMBER];
  /* Ler numero de elementos. */
  printf("Quantos números terão o vetor? (não pode ser maior que %d): ",MAX_NUMBER);
  scanf("%d",&n);
  if (n <= MAX_NUMBER) {
    preenchevetor(vetor, n);
      for(i=0; i< n ; i++){
        printf("%d \n", vetor[i]);
      }
    }
  else{
        printf("Seu Vetor Excedeu o tamanho máximo. \n");
    }
}
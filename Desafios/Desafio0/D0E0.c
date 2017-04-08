/* Exercício 0

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
devolve 1 se o vetor está em ordem crescente e 0 caso contrário.*/

#include <stdio.h>

#define MAXELEM 10


int checacrescente(int vetor[], int num_elem) {
    int i;
    
    for(i=1; i<num_elem;i++){// i=1 pois nao é necessario checar o par nas posiçoes 0 e -1 (se um vetor tem n posições  ele tem n-1 pares)
        if (num_elem<=1){
            return 1;              
        }
        else if(vetor[i-1]>vetor[i]){ //já retorna de imediato caso o segundo numero seja menor que o primeiro (ou seja não esta em ordem crescente)
            return 0;
        }
    }
    return 1;// return está fora do loop aqui pois ele deve checar todas as vezes antes de responder se o vetor INTEIRO está em ordem crescente
}

/*MAIN*/
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


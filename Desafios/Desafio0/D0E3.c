/* Exercício 3

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
ordena esse vetor de forma crescente utilizando uma implementação do Selection Sort.
*/

#include <stdio.h>

#define MAX_NUMBER 100
  
 
void selection_sort (int vetor[], int num_elem) {
  int temp; //guarda o maior valor até o momento
  int j;
  int indice;
  int k;
  int i;
  //printf("%d\n",vetor[0]); // teste
  for (k = 0; k < num_elem; k++){
    indice =k;// k na primeira iterada é zero
    temp = vetor[k];
    for (j = k; j < num_elem; j++) { // j =k pois ao fazer isso eliminamos o menor valor salvo da ultima iteração e fazemos a comparacao apeas com os numeros restantes no vetor
      if(vetor[j] < temp) {
        temp = vetor[j];
        indice =j;
        //printf("%d \n", temp); // teste
        //printf("%d \n", indice); // teste
      }
    }
    temp = vetor[k];// vetor[0]= o valor que esta na posicao zero do vetor   e k = indice de posicoes do vetor
    vetor[k] = vetor[indice]; // indice = um numero que indica a posicao que esta o valor
    vetor[indice] = temp; 
    //for(i=0; i< num_elem ; i++){
    //printf(" Este é: %d \n ", vetor[i]); // teste para checar cada iteração
    //}
  }
}
int checacrescente(int vetor[], int num_elem) {
    int i;
    
    for(i=1; i<num_elem;i++){
        if (num_elem<=1){
            return 1;              
        }
        else if(vetor[i-1]>vetor[i]){ //já retorna de imediato caso o segundo numero seja menor que o primeiro (ou seja não esta em ordem crescente)
            return 0;
        }
    }
    return 1;// return está fora do loop aqui pois ele deve checar todas as vezes antes de responder se o vetor INTEIRO está em ordem crescente
}


int main (int argc, char *argv[]) {
  int vetor[MAX_NUMBER];
    int i;
    int num_elem;
    int resp;

    /* Ler numero de elementos. */
    printf("Quantos números terão o vetor? (não pode ser maior que %d): ",MAX_NUMBER);
    scanf("%d",&num_elem);
    
    /* Ler os elementos. */
    for (i = 0; i <num_elem; i++) {
      scanf("%d", &vetor[i]);
    }
    selection_sort(vetor,num_elem);
    resp=checacrescente(vetor,num_elem);

  printf( "Vetor Novo: \n");    
      /* Printar o vetor. */
  for(i=0; i< num_elem ; i++){
    printf("%d \n ", vetor[i]);
  }
    printf("%s\n", resp?"Esta em ordem crescente":"Não esta em ordem crescente");
}
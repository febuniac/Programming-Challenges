/* Exercício 2

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
ordena esse vetor de forma crescente utilizando uma implementação do Bubble Sort que seja melhor que a apresentada em sala.

Na entrega, você deve justificar porque ela é melhor.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMBER 100

void bubble_sort(int vetor[], int num_elem) {
  for(int j = num_elem - 1; j >= 1; j--) { // laço externo (entra o numero de vezes de acordo com o tamanho do vetor)
    bool flag=true;//Parte do principio que esta ordenado (flag = indicador de que algo aconteceu)
    printf(" rodada: %d \n",(j+1));
    for(int i = 1; i <= j; i++) { // laço interno(é uma soma de PA que é a quantidade de vezes que passa pelos pares que são comparados)
      if(vetor[i - 1] > vetor[i]) {
        int temp = vetor[i - 1];
        vetor[i - 1] = vetor[i];
        vetor[i] = temp;
        flag =false; // se entrar neste if e fizer uma mudança significa que nao estva ordenado de primeira
      }
    }
    if (flag == true){
      //printf(" break: %d \n",v[j]); printa o ultimo numero
      break; // caso nao tenha entrado no if e a flag seja true não há mais nada a ser feito
    }
  }
}
int main(int argc, char *argv[]) { 
	int vetor[MAX_NUMBER];
	int num_elem;
  int i;
  printf("Quantos números terão o vetor? (não pode ser maior que %d): ",MAX_NUMBER);
  scanf("%d",&num_elem);
  /* Ler os elementos. */
  for (i = 0; i <num_elem; i++) {
    scanf("%d", &vetor[i]);
  }

	bubble_sort(vetor,num_elem);
  
  printf("Resposta ordenada:\n ");
  
  /* Printar o vetor. */
  for(i=0; i< num_elem ; i++){
    printf("%d \n ", vetor[i]);
  }
}
// melhorá: Ao algoritmo checar e perceber que o vetor ja esta ordenado em certo ponto ele deve parar de checar e printar o código.

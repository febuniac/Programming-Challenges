/* Exercício 4

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
ordena esse vetor de forma crescente utilizando uma implementação do Insertion Sort.
*/


#include <stdio.h>

#define MAX_NUMBER 100
  
 
void insertion_sort (int vetor[], int num_elem) {
  int temp; //guarda o maior valor até o momento
  int j;
  int indice =0;
  int k;
  for (k = 1; k < num_elem; k++){ //loop externo começa do 1 pois quando há apenas um valor no vetor este valor ja está ordenado
  	indice =k;//utilizado para percorrer
  	temp = vetor[k];//guarda o valor que estava em k
    while (vetor[indice-1]>temp && indice >0){//compara para ver se o indice é maior que zero e ve se o valor de indice menos 1 sempre andando para esquerda é maior que o valorselecionado na temp.
    	vetor[indice]=vetor[indice-1];//se for copia o valor mais alto para a posição que estava o valor salvo na temp
      indice--;// anda o indice uma posição para a esquerda até que as condições do while sejam falsas
    }
      vetor[indice]=temp;// ao encontrar a posição que o valor no indice-1 é menor  que o salvo na temp copiamos o vaor da temp para o valor de indice
      //anda p esquerda até achar um cara menor que ele
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
    insertion_sort(vetor,num_elem);
    resp=checacrescente(vetor,num_elem);

  printf( "Vetor Novo: \n");    
      /* Printar o vetor. */
  for(i=0; i< num_elem ; i++){
    printf("%d \n ", vetor[i]);
  }
    printf("%s\n", resp?"Esta em ordem crescente":"Não esta em ordem crescente");
}
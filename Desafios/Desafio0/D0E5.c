/*Exercício 5

Usando as funções dos exercícios anteriores, escreva um programa que:

gere 100 vetores com 1000 inteiros aleatórios cada um;
ordene cada vetor usando cada algoritmo;
verifique se cada uma das 300 ordenações foi bem-sucedida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void preenchevetor (int vetor[],int num_elem){
  int i;
  for(i=0; i< num_elem ; i++){
      vetor[i]= rand() % MAX_NUMBER; //rand ()= Retorna um inteiro entre 0 e RAND_MAX [RAND_MAX is a constant defined in <cstdlib>.](More at: http://www.cplusplus.com/reference/cstdlib/rand/)
      // rand() % MAX_NUMBER = Truque para obter um inteiro aleatório entre 0 e (MAX_NUMBER – 1)
      //para cada campo do vetor é colocado um valor aleatório nele.
  }
}


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


void bubble_sort(int vetor[], int num_elem) {
  for(int j = num_elem - 1; j >= 1; j--) { // laço externo
    for(int i = 1; i <= j; i++) {   // laço interno
      if(vetor[i - 1] > vetor[i]) {
        int temp = vetor[i - 1];
        vetor[i - 1] = vetor[i];
        vetor[i] = temp;
      }

    }
  }
}


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
      vetor[indice]=temp;// ao encontrar a posiçã que o valor no indice-1 é menor  que o salvo na temp copiamos o vaor da temp para o valor de indice
      //anda p esquerda até achar um cara menor que ele
  }
}



int main(void) { 
  srand(time(NULL));//inicializa a máquina de geração de números aleátorios
  int n;
  int i;
  int num_elem;
  int resp;
  int vetor[MAX_NUMBER];
  int vetores;
  int j;
 

  //Lendo quantidde de vetores
  printf("Quantos vetores serão calculados: ");
  scanf("%d",&vetores);

  
  /* Ler numero de elementos. */
  printf("Quantos números terão os vetores? (não podem ser maior que %d): ",MAX_NUMBER);
  scanf("%d",&num_elem);
 


  for (int j = 0; j < vetores; ++j)
  {
  	  if (n <= MAX_NUMBER) {
    preenchevetor(vetor, num_elem);
      for(i=0; i< num_elem ; i++){
        printf("%d \n", vetor[i]);
      }
    }
  else{
        printf("Seu Vetor Excedeu o tamanho máximo. \n");
    }


    bubble_sort(vetor,num_elem);
    
    resp=checacrescente(vetor,num_elem);
  printf( "Vetor Novo: \n");    
      /* Printar o vetor. */
  printf("BUBBLE \n");
  for(i=0; i< num_elem ; i++){
    printf("%d \n ", vetor[i]);
  }
    printf("%s\n", resp?"Esta em ordem crescente":"Não esta em ordem crescente");
}




for (int j = 0;  j <vetores; ++j)
  {
      if (n <= MAX_NUMBER) {
    preenchevetor(vetor, num_elem);
      for(i=0; i< num_elem ; i++){
        printf("%d \n", vetor[i]);
      }
    }
  else{
        printf("Seu Vetor Excedeu o tamanho máximo. \n");
    }

    
    selection_sort(vetor,num_elem);
    //insertion_sort(vetor,num_elem);
    resp=checacrescente(vetor,num_elem);
  printf( "Vetor Novo: \n");    
      /* Printar o vetor. */
  printf("SELECT \n");
  for(i=0; i< num_elem ; i++){
    printf("%d \n ", vetor[i]);
  }
    printf("%s\n", resp?"Esta em ordem crescente":"Não esta em ordem crescente");
}



for (int j = 0;  j <vetores; ++j)
  {
      if (n <= MAX_NUMBER) {
    preenchevetor(vetor, num_elem);
      for(i=0; i< num_elem ; i++){
        printf("%d \n", vetor[i]);
      }
    }
  else{
        printf("Seu Vetor Excedeu o tamanho máximo. \n");
    }

    
    insertion_sort(vetor,num_elem);

    resp=checacrescente(vetor,num_elem);
  printf( "Vetor Novo: \n");    
      /* Printar o vetor. */
  printf("INSERT \n");
  for(i=0; i< num_elem ; i++){
    printf("%d \n ", vetor[i]);
  }
    printf("%s\n", resp?"Esta em ordem crescente":"Não esta em ordem crescente");
}
 }
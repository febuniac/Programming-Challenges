/*QUICKSORT*/
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
        else if(vetor[i-1]<vetor[i]){ //já retorna de imediato caso o segundo numero seja menor que o primeiro (ou seja não esta em ordem crescente)
        	return 0;
        }
    }
    return 1;// return está fora do loop aqui pois ele deve checar todas as vezes antes de responder se o vetor INTEIRO está em ordem crescente
}  

//Conquista
//l=left,r=right
//essa funcao vai particionar o vetor em 2 tendo uma partev com os menores numeros e uma com os maiores numeros isto é feito com comparacoes com o pivot
int partition (int vetor[], int l, int r){
	int pivot = vetor[l];//pivot é o elemento de comparação
	int i =l;//i igual ao primeiro elemento do vetor
	int temp;

	for (int j=l+1;j<=r; j++){//j= primeiro elemento do vetor+1
		if(vetor[j]>=pivot){//se o primeiro valor do vetor for menor ou igual ao pivot
			i++;//incremeta um no i 
			temp=vetor[i];//guarda a prox posição do i
			vetor[i]=vetor[j];//A primeira posição se torna a proxima
			vetor[j]=temp;// a segunda posicao se torna a primeira
//colocando menores de um lado e maiores do outro
		}
	}
	temp =vetor[l];//temp é o primeiro valor do vetor(pivot)
	vetor[l]=vetor[i];// no final da primeira metade
	vetor[i]= temp;//

	return i;
}


//Divisão
	//recebe um vetor e sua extremidade da esquerda e da direita
void quick_sort_r(int vetor[], int l, int r) {
	if (l < r){//se l e r são iguais, ou seja o vetor tem apenas um digito, nao entra pois ja esta ordenado.
		int p = partition(vetor,l,r);
		quick_sort_r(vetor,l,p-1);
		quick_sort_r(vetor,p+1,r);
	}
}
//Embrulho
void quick_sort(int vetor[], int num_elem){
	quick_sort_r(vetor,0,num_elem-1);//passa o vetor inicio do vetor e fim do vetor.
}
int main(int argc, char *argv[]) {
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
  		printf( "Vetor Velho: \n");   
  		for(i=0; i< num_elem ; i++){
  			printf("%d \n", vetor[i]);
  		} 
  	}
  	else{
  		printf("Seu Vetor Excedeu o tamanho máximo. \n");
  	}


  	quick_sort(vetor,num_elem);
  	
  	resp=checacrescente(vetor,num_elem);
  	printf( "Vetor Novo: \n");    
      /* Printar o vetor. */
  	for(i=0; i< num_elem ; i++){
  		printf("%d \n ", vetor[i]);
  	}
  	printf("%s\n", resp?"Esta em ordem decrescente":"Não esta em ordem descrescente");
  }

}
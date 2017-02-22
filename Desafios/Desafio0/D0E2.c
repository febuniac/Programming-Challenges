/* Exercício 2

Escreva uma função que:

recebe um vetor de inteiros e o tamanho desse vetor;
ordena esse vetor de forma crescente utilizando uma implementação do Bubble Sort que seja melhor que a apresentada em sala.

Na entrega, você deve justificar porque ela é melhor.
*/

#include <stdio.h>
#define MAX_NUMBER 100

void bubble_sort(int v[], int n) {
  for(int j = n - 1; j >= 1; j--) { // laço externo
    for(int i = 1; i <= j; i++) {   // laço interno
      if(v[i - 1] > v[i]) {
        int temp = v[i - 1];
        v[i - 1] = v[i];
        v[i] = temp;
      }
    }
  }
}
int main(void) { 
	int b_s;
	int v[MAX_NUMBER];
	int n;
	b_s=bubble_sort(v,n);
	printf("%d\n",b_s );
}

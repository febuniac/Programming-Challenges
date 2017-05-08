/*QUICKSORT*/

#include <stlib.h>

//Embrulho
void quick_sort(int v[],int n){
	quick_sort_r(v,0,n-1)//passa o vetor inicio do vetor e fim do vetor.
}    

//Conquista
//l=left,r=right
//essa funcao vai particionar o vetor em 2 tendo uma partev com os menores numeros e uma com os maiores numeros isto é feito com comparacoes com o pivot
int partition (int v[], int l, int r){
	int pivot = v[l];//pivot é o elemento de comparação
	int i =l;//i igual ao primeiro elemento do vetor
	int temp;

	for (int j=l+1;j<=r, j++){//j= primeiro elemento do vetor+1
		if(v[j]<=pivot){//se o primeiro valor do vetor for menor ou igual ao pivot
			i++;//incremeta um no i 
			temp=v[i];//guarda a prox posição do i
			v[i]=v[j];//A primeira posição se torna a proxima
			v[j]=temp;// a segunda posicao se torna a primeira
//colocando menores de um lado e maiores do outro
		}
	}
	temp =v[l];//temp é o primeiro valor do vetor(pivot)
	v[l]=v[i];// no final da primeira metade
	v[i]= temp;//

	return i;
}


//Divisão
	//recebe um vetor e sua extremidade da esquerda e da direita
void quick_sort_r(int v[], int l, int r) {
	if (l < r){//se l e r são iguais, ou seja o vetor tem apenas um digito, nao entra pois ja esta ordenado.
		int p = partition(v,l,r);
		quick_sort_r(v,l,p-1);
		quick_sort_r(v,p+1,r);
	}
}

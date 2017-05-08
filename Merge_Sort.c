/*MERGE SORT*/
#include <stlib.h>

//Embrulho
void merge_sort(int v[],int n){
	merge_sort_r(v,0,n-1)//passa o vetor inicio do vetor e fim do vetor.
}    

//Conquista
//l=left,m=middle,r=right
void merge (int v[], int l, int m, int r){
	//O merge sabendo que tem duas metades ordenadas e através de comparaçoes monta o vetor final.
	int n = r-l + 1;//Definindo o tamanho ultimo - primeiro +1 funciona
	int b[n];//vetor de tamanho n

	int i=l;//i =extrema esquerda
	int j =m+1;// j= extrema esquerda da segunda metade

	for (int k=0; k<n;k++){
		if(i>m){//se extrema esquerda maior que o meio
			b[k]=v[j];//b[contador] = primeiro membro da outra metade
			j++;//passa para o proximo mebro da segunda metade
		}
		else if(j>r){//se o primeiro membro da segunda metade for aior que o ultimo da segunda metade(para checar se o r passou do limite)
			b[k]=v[i];//b[contador]=primeiro membro da primeira metade
			i++;//passa sempre para o proximo da primeira metade
		}
		else{
			if(v[i]<v[j]){//se membro da primeira metade menor que mebro da segunda metade
				b[k]=v[i];//b[contador]=membro da primera metade
				i++;//passa sempre para o proximo da primeira metade
			}
		}
		else{
			b[k]=v[j];//b[contador]=membro da segunda metade
			j++;//passa sempre para o proximo da segunda metade
		}
	}
}
	for (int k=0; k<n; k++){
		v[l+k]=b[k];//v[extrema esquerda+contador]=b[contador]
	}
}

//Divisão
	//recebe um vetor e sua extremidade da esquerda e da direita
void merge_sort_r(int v[], int l, int r) {
	if (l < r){//se l e r são iguais, ou seja o vetor tem apenas um digito, nao entra pois ja esta ordenado.
		int m = (l+r)/2;//m é o meio do vetor v
		merge_sort_r(v,l,m);//recursão chamando o vetor, a extrema esquerda e o meio (ordena a primeira parte(metade) do vetor)
		merge_sort_r(v,m+1,r);//recursão chamando o vetor, o meio (ordena a segunda parte do vetor), a extrema direita
		merge(v,l,m,r);//Chama o merge para ordenar o vetor inteiro(junta as metades do vetor)
	}
//Utilizamos o merge pois o merge dá certeza que vetor o esta dividido e para cada uma das partes esta ordenada.
	//Ordena o vetor inteiro partindo do pressuposto que duas metades ja estão ordenadas.

#include<stdio.h>

// função para organizar duas sub-listas ordenadas
void merge(int vet[], int l, int m, int r){
	int i, j, k;
	int n1 = m -1 +1;
	int n2 = r - m;
	
	// su-listas temporárias
	int L[n1], R[n2];
	
	// prrencher as sub-listas esquesda e direita
	for(i=0; i<n1; i++)
	
		L[i] = vet[l+1];

	for(j=0; j<n2; j++)
		R[j] = vet[m+1+j];
	
	//construindo a lista originl a partir das sub-listas	
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			vet[k] = L[i];
			i++;
		}
		else{
			vet[k] = R[j];
			j++;
		}
		k++;
	}
	// copia, se restar, os elementos de L[].
	while(i<n1){
		vet[k] = L[i];
		i++;
		k++;
	}
	// copia, se restar, os elementos de R[].
	while(j<n2){
		vet[k] = R[j];
		j++;
		k++;
	}
}
// função principal que irá implementar a MergeSort
void mergesort(int vet[], int l, int r){
	if(l < r){
		// encontra o ponto médio do vetor
		int m = l + (r-l)/2;
		// Faz a odernação recursivamente da primeira e segunda metade
		mergesort(vet, l, m);
		mergesort(vet, m+1, r);
		//junta recursivamente as partes que já foram ordenada
		merge(vet, l, m, r);
	}
}
// Função para imprimir o vetor
void imprimevetor(int A[], int size){
	int i;
	for(i=0; i<size; i++)
	printf("[%d]",A[i]);
	printf("\n");
}
// programa principal
main(){
	int vet[] = {12,11,13,5,6,7,1,78,4,9,10,23};
	int vetSize = sizeof(vet)/sizeof(vet[0]);
	
	printf("Vetor Original: \n");
	imprimevetor(vet, vetSize);
	// chamando a função mergesort
	mergesort(vet,0,vetSize - 1);
	printf("Vetor Ordenado: \n");
	imprimevetor(vet, vetSize);
}

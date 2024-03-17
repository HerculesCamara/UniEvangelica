#include<stdio.h>

void insertionsort (int vet[], int n){
	int i, key, j;
	for (i = 1; i<n; i++){
		key = vet[i];
		j = i - 1;
		while(j>=0 && vet [j]>key){
			vet[j+1] = vet[j];
			j = j - 1;
		}
		vet[j+1] = key;
	}
}

void imprimeVet(int vet[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("[%d]", vet[i]);
	}
	printf("\n");
}

main(){
	int vet[] = {12,11,15,5,6,9,1,18};
	int n = sizeof(vet)/sizeof(vet[0]);
	
	printf("Vetor Original: \n");
	imprimeVet(vet, n);
	printf("\n");
	insertionsort(vet, n);
	printf("Vetor Ordenado: \n");
	imprimeVet(vet, n);
}

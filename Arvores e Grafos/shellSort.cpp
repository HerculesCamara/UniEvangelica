#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int array[], int n) {
    int gap, i, j, temp;
    
    // Inicializa o tamanho do gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Faz uma série de inserções de acordo com o gap
        for (i = gap; i < n; i++) {
            // Pega o elemento a ser inserido em seu lugar correto
            temp = array[i];
            
            // Move os elementos que são maiores que temp para frente da sua posição atual
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            
            // Insere temp na posição correta
            array[j] = temp;
        }
    }
}

void preencherVetorAleatorio(int vetor[], int tamanho, int type) {
    if(type == 1){
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = i;
        }
    } else if(type == 2) {
        for (int i = tamanho; i >= 0; i--){
            vetor[i] = i;
        }
    } else if(type == 3){
        // Inicializa o gerador de números aleatórios com o tempo atual
        srand(time(NULL));
        
        // Preenche o vetor com números aleatórios
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = rand() % tamanho;
        }
    }
    
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}


int main() {
    int type = 1;
    int tam = 100;
    int array[tam];
    preencherVetorAleatorio(array, tam, type);
    shellSort(array, tam);

    printf("Array crescente (100):\n");
    printArray(array, tam);
    

    type = 2;
    preencherVetorAleatorio(array, tam, type);
    shellSort(array, tam);

    printf("Array decrescente (100):\n");
    printArray(array, tam);
    
    
    type = 3;
    preencherVetorAleatorio(array, tam, type);
    shellSort(array, tam);

    printf("Array aleatório (100):\n");
    printArray(array, tam);
    printf("\n\n\n");
    

  //Vetor 1000  
    type = 1;
    tam = 1000;
    int array2[tam];
    preencherVetorAleatorio(array2, tam, type);
    shellSort(array2, tam);

    printf("Array crescente (1000):\n");
    printArray(array2, tam);
    

    type = 2;
    preencherVetorAleatorio(array2, tam, type);
    shellSort(array2, tam);

    printf("Array decrescente (1000):\n");
    printArray(array2, tam);
    
    
    type = 3;
    preencherVetorAleatorio(array2, tam, type);
    shellSort(array2, tam);

    printf("Array aleatório (1000):\n");
    printArray(array2, tam);
    printf("\n\n\n");



//Vetor 10000
    type = 1;
    tam = 10000;
    int array3[tam];
    preencherVetorAleatorio(array3, tam, type);
    shellSort(array3, tam);

    printf("Array crescente (10000):\n");
    printArray(array3, tam);
    

    type = 2;
    preencherVetorAleatorio(array3, tam, type);
    shellSort(array3, tam);

    printf("Array decrescente (10000):\n");
    printArray(array3, tam);
    
    
    type = 3;
    preencherVetorAleatorio(array3, tam, type);
    shellSort(array3, tam);

    printf("Array aleatório (10000):\n");
    printArray(array3, tam);
    printf("\n\n\n");

    
    return 0;
}

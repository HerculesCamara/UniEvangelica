#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vet[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = vet[i];
        j = i - 1;
        /* Move os elementos de arr[0..i-1] que s�o
           maiores que o elemento chave para uma posi��o � frente
           de sua posi��o atual */
        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}

void imprimeVet(int vet[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

// Fun��o para mesclar duas sub-listas ordenadas
void merge(int vet[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria sub-listas tempor�rias
    int L[n1], R[n2];

    // Copia dados para as sub-listas tempor�rias L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vet[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[m + 1 + j];
    // Mescla as sub-listas de volta na lista original
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        }
        else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
}

// Fun��o principal que implementa o Merge Sort
void mergeSort(int vet[], int l, int r) {
    if (l < r) {
        // Encontra o ponto m�dio
        int m = l + (r - l) / 2;
        // Ordena recursivamente a primeira e a segunda metade
        mergeSort(vet, l, m);
        mergeSort(vet, m + 1, r);
        // Mescla recursivamente as partes ordenadas
        merge(vet, l, m, r);
    }
}

// Função para trocar dois elementos de posição em um array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô correto no array e particioná-lo
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // seleciona o último elemento como pivô
    int i = (low - 1); // índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]); // troca arr[i] e arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]); // troca arr[i + 1] e arr[high] (ou seja, coloca o pivô na posição correta)
    return (i + 1); // retorna a posição do pivô
}

// Implementação do algoritmo Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é a posição do pivô após particionamento
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado usando Quick Sort:\n");
    printArray(arr, n);
    return 0;
} */

void criarVetor(int vetor[], int tamanho) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
    }
}


main() {
	int tamanho = 100;
    int vetor[tamanho];
    int vetor2[tamanho];
    int vetor3[tamanho];
	criarVetor(vetor, tamanho);
	criarVetor(vetor2, tamanho);
	criarVetor(vetor3, tamanho);

    /* int vet2[] = {12, 11, 13, 5, 6,9,1,19};
    int vet3[] = {12, 11, 13, 5, 6+,9,1,20};
    int n = sizeof(vet2) / sizeof(vet2[0]); */

    insertionSort(vetor, tamanho);
	mergeSort(vetor2, 0, tamanho - 1);
	quickSort(vetor3, 0, tamanho - 1);
    printf("Vetor Ordenado: \n");
    imprimeVet(vetor, tamanho);
    imprimeVet(vetor2, tamanho);
    imprimeVet(vetor3, tamanho);

}

// Fun��o para imprimir um array
/* void imprimeVet(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 */
/* // Programa principal para testar o Merge Sort
int main() {
    int vet[] = {12, 11, 13, 5, 6, 7, 17, 78, 1, 4, 3, 10};
    int vet_size = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor de entrada:\n");
    imprimeVet(vet, vet_size);
// chamando a fun��o merge
    mergeSort(vet, 0, vet_size - 1);

    printf("\nVetor ordenado:\n");
    imprimeVet(vet, vet_size);
    return 0;
} */

//Hércules Gabriel Araujo Câmara, Gustavo Henrique Couto Antunes, Gabriel Martins, Gabriel Vitor Sousa, Warner de Melo Filho, Felipe de Oliveira Leite, Daniel Rodrigues Chaves, José Vitor Santos

//Aplicativo de combate a violencia doméstica
//Esse código pega a quantidade de incidentes de violencia em um período de dias, e mostra esses valores ordenados
//Utilizamos o Bubble Sort

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Últimos i elementos já estão ordenados, então precisamos apenas verificar os primeiros (n-i) elementos
        for (j = 0; j < n-i-1; j++) {
            // Comparar elementos adjacentes e trocar se estiverem na ordem errada
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Digite o tanto de dias que voce quer registrar: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite a quantidade de registros %d dias:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("Vetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

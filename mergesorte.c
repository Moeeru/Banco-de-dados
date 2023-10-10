#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30;

// Funções de ordenação Merge Sort
void merge(int *V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100;
    }

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    time_t start_time = time(NULL);

    mergeSort(array, 0, tamanho - 1);

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);

    printf("\nArray ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    printf("\nTempo de execução: %f segundos\n", elapsed_time);

    return 0;
}

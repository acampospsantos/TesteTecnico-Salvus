#include <stdio.h>

// Função que imprime os elementos de um array
void imprimir_array(int array[], int tamanho) {
    printf("Elementos do array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%i ", array[i]); // Imprime cada elemento do array
    }
    printf("\n");
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    // Chamando a função para imprimir os elementos do array numeros
    imprimir_array(numeros, tamanho);
    
    return 0;
}
#include <stdio.h>

// Função para realizar uma operação matemática (soma ou multiplicação)
int operacao(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

// Função de soma
int soma(int a, int b) {
    return a + b;
}

// Função de multiplicação
int multiplicacao(int a, int b) {
    return a * b;
}

int main() {
    int num1 = 5, num2 = 3;
    int resultado;

    // Chamando a função operacao com a função soma
    resultado = operacao(num1, num2, soma);
    printf("Resultado da soma: %d\n", resultado);

    // Chamando a função operacao com a função multiplicacao
    resultado = operacao(num1, num2, multiplicacao);
    printf("Resultado da multiplicacao: %d\n", resultado);

    return 0;
}

#include <stdio.h>

void imprimir_matriz(int N) {
    int i, j, valor;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            // Calcula o valor a ser colocado na matriz
            valor = i < j ? i : j;
            valor = valor < N - i + 1 ? valor : N - i + 1;
            valor = valor < N - j + 1 ? valor : N - j + 1;

            printf("%3d", valor);
            if (j < N) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int N;

    // Lê valores de N até que 0 seja inserido
    while (1) {
       
        scanf("%d", &N);

        if (N == 0) break;

        imprimir_matriz(N);
    }

    return 0;
}


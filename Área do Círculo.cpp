#include <stdio.h>

int main() {
    double raio, area;
    const double PI = 3.14159;

    // L� o valor do raio
   
    scanf("%lf", &raio);

    // Calcula a �rea da circunfer�ncia
    area = PI * raio * raio;

    // Imprime a �rea com 4 casas decimais
    printf("A=%.4lf\n", area);

    return 0;
}


#include <stdio.h>

int main() {
    double raio, area;
    const double PI = 3.14159;

    // Lê o valor do raio
   
    scanf("%lf", &raio);

    // Calcula a área da circunferência
    area = PI * raio * raio;

    // Imprime a área com 4 casas decimais
    printf("A=%.4lf\n", area);

    return 0;
}


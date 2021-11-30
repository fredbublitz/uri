#include <stdio.h>

int main()
{

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

    char nome[61];
    double salario;
    double vendas;

    scanf("%s", nome);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);

    double total = salario + (vendas * 0.15);

    printf("TOTAL = R$ %0.2lf\n", total);

return 0;
}
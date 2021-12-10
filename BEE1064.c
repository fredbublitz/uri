#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */

    float numero, soma = 0;
    int totalPositivos = 0;

    //laço que recebe os 6 valores
    int i;
    for (i = 0; i < 6; i++)
    {
        
        scanf("%f", &numero);
        //caso o númeo seja positivo é incrementado o total de
        //números positivos e a soma total destes.
        if (numero > 0)
        {
            totalPositivos++;
            soma += numero;
        }        
    }

    printf("%d valores positivos\n", totalPositivos);
    printf("%.1f\n", soma/totalPositivos);
    
 
    return 0;
}
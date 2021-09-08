#include <stdio.h>
/**
     * Questão 1578 - Matriz de Quadrados
     */

/**
 * Função que conta o total de dígitos de um número
 * utilizado para formatar a matriz
 */

int contaDigitos(unsigned long long valor)
{
    int totalDigitos = 1;

    while (valor > 9)
    {
        totalDigitos++;
        valor /= 10;
    }

    return totalDigitos;
}

int main()
{

    // Número de matrizes cujos “quadrados” ainda não foram calculados
    int N;

    // Número de linhas e o número de colunas da matriz
    int M;

    scanf("%d", &N);

    //Laço para avaliar cada instância de jogo
    int i;
    /** Comece a contagem em x = 4, afinal, Atrapalhilton
     * já calculou os “quadrados” das 3 primeiras matrizes 
     */
    for (i = 4; i <= N + 3; i++)
    {
        // Ordem da matriz
        scanf("%d", &M);
        // Matriz solução com valores (2ˆ32)-1
        unsigned long long matrizQuadrada[M][M];
        // Número que quarda o total de dígitos de cada coluna maior número da matriz solução
        int digitosMaiorNumero[M];
        int l;
        for (l = 0; l < M; l++)
        {
            digitosMaiorNumero[l] = 1;
        }
        
        unsigned long long valor = 0;
        int j, k;
        for (j = 0; j < M; j++)
        {
            
            for (k = 0; k < M; k++)
            {
                
                scanf("%llu", &valor);
                
                matrizQuadrada[j][k] = (valor * valor);
                //total de dígitos do número atual
                int digitosNumero = contaDigitos(matrizQuadrada[j][k]);
                if(digitosNumero > digitosMaiorNumero[k])
                {
                    digitosMaiorNumero[k] = digitosNumero;
                }
            }
        }

        /**  Imprima também uma linha em branco entre “quadrados” de matrizes consecutivas.*/
        if (i != 4)
            printf("\n");
        
        
        printf("Quadrado da matriz #%d:\n", i);
        for (j = 0; j < M; j++)
        {
            for (k = 0; k < M; k++)
            {                
                /** Adicione tantos espaços em branco à esquerda de cada valor quanto necessários 
                 * para que os valores de uma mesma coluna fiquem todos alinhados à direita, 
                 * de modo que haja ao menos um valor em cada coluna não precedido por espaços em branco
                 *  além do espaço em branco obrigatório que separa colunas consecutivas
                 * 
                 * "%*""                    - permite a adição de espaços em branco
                 * "digitosMaiorNumero[k]"  - especifica a quantidade de espaços em branco
                 * "+(k>0)"                 - teste lógico que adiciona +1 espaço a partir da 2 coluna
                 */
                printf("%*llu", digitosMaiorNumero[k]+(k>0), matrizQuadrada[j][k]);               
            }
            printf("\n");
        }


        
    }

    return 0;
}
// material sobre alocação dinâmica:
// https://www.inf.ufpr.br/roberto/ci067/14_alocmat.html

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função que aloca os valores de uma matriz dinâmica (ponteiros)
 *
 * @return int**
 */
int **alocaMatriz(int LIN, int COL)
{
    int **matriz;
    // aloca um vetor de l (linhas) ponteiros para linhas
    matriz = malloc(LIN * sizeof(int *));
    // aloca cada uma das linhas (vetores de c (colunas) inteiros)
    int k;
    for (k = 0; k < LIN; k++)
        matriz[k] = malloc(COL * sizeof(int));



    int i, j;
    for (i = 0; i < LIN; i++)
    {
        for (j = 0; j < COL; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}

/**
 * @brief Denotando por Ai,j o elemento na i-ésima linha e j-ésima coluna da matriz A,
 * dizemos que uma matriz é “legal” se a condição  A1,1 + Alin,col ≤ A1,col+ Alin,1
 * é verdadeira para todo lin > 1 e col > 1.
 *
 * @param A matriz
 * @return int
 */
int ehLegal(int LIN, int COL, int **A)
{
    int i, j;
    for (i = 1; i < LIN; i++)
    {
        for (j = 1; j < COL; j++)
        {
            //printf( "-> (A[0][0] + A[i][j]) = %d (A[0][j] + A[i][0]) = %d)\n", (A[0][0] + A[i][j]), (A[0][j] + A[i][0]));

            if ( (A[0][0] + A[i][j]) > (A[0][j] + A[i][0]) ) 
            {
                //printf("não é legal");
                return 0;
            }
        }
    }
    return LIN * COL;
}

int **subMatriz(int li, int ci, int M, int N, int **Matriz)
{
    int **subMatriz;
    // aloca um vetor de M  ponteiros para linhas
    subMatriz = malloc(M * sizeof(int *));
    // aloca cada uma das linhas (vetores de N (colunas) inteiros)
    int k;
    for (k = 0; k < M; k++)
        subMatriz[k] = malloc(N * sizeof(int));

    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            subMatriz[i][j] = Matriz[li + i][ci + j];
        }
    }    
    return subMatriz;
}

/**
 * @brief função que exibe uma matriz dinâmica de ordem lxc
 *
 * @param l
 * @param c
 * @param matriz
 */
void exibeMatriz(int LIN, int COL, int **matriz)
{
    int i, j;
    for (i = 0; i < LIN; i++)
    {
        printf("|");
        for (j = 0; j < COL; j++)
        {
            printf("(%d,%d) %3d |", i, j, matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{

    int L, C;
    scanf("%d%d", &L, &C);
    int **matrizPrincipal = alocaMatriz(L,C);

    exibeMatriz(L, C, matrizPrincipal);
    //printf("%d\n", ehLegal(L, C, matrizPrincipal));
    // percorre as submatrizes
    int **submatriz;

    /**
     * @brief ordem MxN
     * li = Linha inicial
     * ci = coluna inicial
     */
    int li, ci, M, N;

    int maiorLegal = 0;
    // todas as possíveis ordens de matriz (MxN)
    for (M = 2; M <= L; M++)
    {
        for (N = 2; N <= C; N++)
        {
            printf("%d x %d\n", M, N);
            //  percorre todas as submatrizes de cada ordem
            for (li = 0; li <= L - M; li++)
            {
                for (ci = 0; ci <= C - N; ci++)
                {
                    printf("  (%d,%d)\n", li, ci);
                    submatriz = subMatriz(li, ci, M, N, matrizPrincipal);
                    exibeMatriz(M,N,submatriz);
                    int legal = ehLegal(M, N, submatriz);
                    if (legal > maiorLegal)
                    {
                        maiorLegal = legal;
                    }
                    // // libera a memória da matriz
                    int k;
                    for (k = 0; k < M; k++)
                        free(submatriz[k]) ;
                    free(submatriz);
                }
            }
        }
    }

   printf("%d\n", maiorLegal);

    return 0;
}
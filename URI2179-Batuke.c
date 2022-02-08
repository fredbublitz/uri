/** 
* Questão 2179 - BATUKE
*/
#include <stdio.h>

//N é o número de linhas na vizinhança
int N;

// F e C indica linha e coluna aonde Batuke inicia o seu percurso.
int F, C;

//Indica o total de casas visitadas por Batuke
int casasVisitadas = 0;

int casasPercorridas = 0;

int passo = 1;

void exibeMatriz()
{
    int i, j, valor;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            valor = (i * N) + (j + 1);
            printf("%3d", valor);
        }
        printf("\n");
    }
}

int main()
{

    scanf("%d", &N);
    //exibeMatriz();
    scanf("%d%d", &F, &C);

    //visita casa inicial
    if (C >= 0 && C < N && F >= 0 && F < N)
    {
        printf("%d ", ((F * N) + (C + 1)));
        casasVisitadas++;
    }
    casasPercorridas++;

        while (casasVisitadas < (N * N))
    {
        /**
         * Se passo é impar movimento para DIR > BAIXO
         * Caso Contrário ESQ > CIMA
         */
        int k;
        //caso passo é impar
        if (passo % 2 != 0)
        {

            //mover para direita

            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    C++;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }

            //mover para baixo
            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    F++;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }

            //incrementa o passo
            passo++;
        }
        else
        {
            //mover para esquerda
            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    C--;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }
            //mover para cima
            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    F--;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }
            //incrementa o passo
            passo++;
        }
    }

    printf("\n%d", casasPercorridas);

    return 0;
}
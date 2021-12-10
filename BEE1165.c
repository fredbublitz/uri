#include <stdio.h>

int main()
{
    int X, numero, contador;
    int totalDiv = 0;

    scanf("%d", &X);

    int i;
    for (i = 0; i < X; i++)
    {
        scanf("%d", &numero);
        totalDiv = 0;
        //Laço que vai verificar as divisões
        for (contador = 1; contador <= numero; contador++)
        {
            if (numero % contador == 0)
            {
                totalDiv++;
            }
        }

        if (totalDiv > 2)
        {
            printf("%d nao eh primo\n", numero);
        }
        else
        {
            printf("%d eh primo\n", numero);
        }
    }

    return 0;
}

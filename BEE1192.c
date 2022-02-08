#include <stdio.h>

int main()
{
    int N, n1, n2;
    char letra;
    int totalDiv = 0;

    scanf("%d", &N);

    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d%c%d", &n1, letra, &n2);
        //verificando se a entrada está correta.
        printf("n1: %d\n", n1);
        printf("letra: %c\n", &letra);
        printf("n2: %d\n", n2);
        //se os DÍGITOS forem iguais, deve-se desconsiderar a letra e mostrar o produto entre os dois dígitos
        if (n1 == n2)
        {
            printf("%d\n", n1 * n2);
        }
        // Se a letra for minúscula, deve-se somar ambos os dígitos
        //
        else if (letra == "a" || "b" || "c" || "d" || "e" || "f" || "g" || "h" || "i" || "j" || "k" || "l" || "m" || "n" || "o" || "p" || "q" || "r" || "s" || "t" || "u" || "v" || "w" || "x" || "y" || "z")
        {
            printf("%d\n", n1 + n2);
        }
        else
        {
            printf("%d\n", n1 - n2);
        }
    }

    return 0;
}

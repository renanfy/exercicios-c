#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int num_sorteio, i;
    FILE *f;

    f = fopen("arquivo.txt", "w");
    if (f == NULL)
    {
        printf("Erro!\n");
        system("pause");
        exit(1);
    }

    printf("Insira um numero:");
    scanf("%d", &num_sorteio);

    if (num_sorteio > 500)
    {
        printf("Infelizmente o limite de entrada e 500. Tente novamente com outro valor!\n");
        system("pause");
        exit(1);
    }

    srand(time(NULL));
    fprintf(f, "%d\n", num_sorteio);

    for (i = 0; i < num_sorteio; i++)
    {
        int sorteio = rand() % 101;
        fprintf(f, "%d\n", sorteio);
    }

    return 0;
}
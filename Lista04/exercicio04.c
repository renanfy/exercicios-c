#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void substituirVogais(FILE *entrada, FILE *saida)
{
    char caractere;

    while ((caractere = fgetc(entrada)) != EOF)
    {
        if (strchr("aeiouAEIOU", caractere) != NULL)
        {
            fputc('*', saida);
        }
        else
        {
            fputc(caractere, saida);
        }
    }
}

int main()
{
    FILE *f, *g;
    char arquivo[50], copia[50];

    printf("Informe o nome do arquivo:");
    scanf("%s", arquivo);

    f = fopen(arquivo, "r");
    if (f == NULL)
    {
        printf("Erro na leitura!\n");
        system("pause");
        exit(1);
    }

    printf("Digite o nome do arquivo copia: (com extensao .txt):");
    scanf("%s", copia);

    if (strstr(copia, ".txt") == NULL)
    {
        strcat(copia, ".txt");
    }

    g = fopen(copia, "w");
    if (g == NULL)
    {
        printf("Erro na criacao");
        system("pause");
        exit(1);
    }

    substituirVogais(f, g);
    fclose(f);
    fclose(g);

    return 0;
}

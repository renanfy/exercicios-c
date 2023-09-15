#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void copiaConteudo(FILE *, FILE *);
typedef struct
{
    char x;
} dados;

int main()
{
    FILE *f, *g;
    char arquivo[50], copia[50];

    printf("Informe o nome do arquivo:");
    scanf("%s", &arquivo);

    f = fopen(arquivo, "r");
    if (f == NULL)
    {
        printf("Erro na leitura!\n");
        system("pause");
        exit(1);
    }

    printf("Digite o nome do arquivo copia: (com extensao .txt):");
    scanf("%s", &copia);

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

    copiaConteudo(g, f);
    fclose(f);
    fclose(g);

    return 0;
}

void copiaConteudo(FILE *g, FILE *f)
{
    dados aux;
    fread(&aux, sizeof(aux), 1, f);
    while (!feof(f))
    {
        fwrite(&aux, sizeof(aux), 1, g);
        fread(&aux, sizeof(aux), 1, f);
    }
}
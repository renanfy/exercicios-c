#include <stdio.h>

int main()
{
    int contador = 0;
    FILE *f;
    char arquivo[50], caractere, contadorChar;

    printf("Informe o nome do arquivo:");
    scanf("%s", &arquivo);

    printf("Insira um caractere para procurar dentro do arquivo:");
    scanf(" %c", &caractere);

    f = fopen(arquivo, "r");
    if (f == NULL)
    {
        printf("Falha ao carregar arquivo!\n");
        system("pause");
        exit(1);
    }

    while ((contadorChar = fgetc(f)) != EOF)
    {
        if (contadorChar == caractere)
        {
            contador++;
        }
    }

    printf("O caractere '%c' foi inserido %d vezes", caractere, contador);

    fclose(f);

    return 0;
}
#include <stdio.h>

int menorElemento(int lista[], int tamanho)
{
    int menor = lista[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (lista[i] < menor)
        {
            menor = lista[i];
        }
    }

    return menor;
}

float calcularMedia(int lista[], int tamanho)
{
    int soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma = soma + lista[i];
    }

    return (float)soma / tamanho;
}

int main()
{
    FILE *f;
    int lista[101], i = 0, j = 0, menor = 0;

    f = fopen("arquivo.txt", "r");
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo.");
        system("pause");
        exit(1);
    }

    while (fscanf(f, "%d", &lista[i]) != EOF)
    {
        i++;
    }

    fclose(f);

    int menorValor = menorElemento(lista, i);
    float media = calcularMedia(lista, i);

    printf("O menor elemento do vetor e: %d\n", menorValor);
    printf("A media dos valores do vetor e: %.2f", media);

    return 0;
}
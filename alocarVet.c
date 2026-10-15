#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "busca.c"

int gerarNumeroAleatorio(int min, int max);
int PesqSeq(int *numeros, int x, int tam);

void alocarVetor(int *numeros, int tam){
    
    int numAleatorio, n = 0;

    while (n < tam)
    {
        numAleatorio = gerarNumeroAleatorio(1, 512);
        if (PesqSeq(numeros, numAleatorio, tam) == -1)
        {
            numeros[n] = numAleatorio;
            n++;
        }
    }

    for (int i = 0; i <= tam - 1; i++)
    {
        numeros[i] = gerarNumeroAleatorio(1, 512);
    }

    printf("\nNumeros no Vetor: {");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("}");

    sleep(5);

}

int gerarNumeroAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}


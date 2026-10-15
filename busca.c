#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int PesqSeq(int *numeros, int x, int tam)
{
    int i = 0;
    while ((numeros[i] != x) && (i < tam))
        i = i + 1;
    if (i < tam)
        return i;
    else
        return -1;
}

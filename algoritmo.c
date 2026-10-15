#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "metricas.h"

void BubbleSort(int *numeros, int tam, Metricas *m)
{
    int i, continua, aux;
    do
    {
        continua = 0;
        for (i = 0; i < tam - 1; i++)
        {
            m->comparacoes++;
            if (numeros[i] > numeros[i + 1])
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
                m->trocas++;
                continua = 1;
            }
        }
    } while (continua);

}

void InsertionSort(int *numeros, int tam, Metricas *m){
    for (int i = 1; i < tam; i++)
    {
        int chave = numeros[i];
        int j = i - 1;

        // Desloca elementos maiores que a chave para abrir espaço
        m->comparacoes++;
        while (j >= 0 && numeros[j] > chave)
        {
            numeros[j + 1] = numeros[j];
            m->trocas++;
            j = j - 1;
        }
        numeros[j + 1] = chave; // Insere a chave na posição correta
    }
}

// MergerSort Interativo
int Menor(int a, int b){
    return (a < b) ? a : b;
}

void Intercalar(int *numeros, int esquerda, int meio, int direita, Metricas *m)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Vetores temporários locais
    int V_Esquerda[n1];
    int V_Direita[n2];

    // Copia os dados usando apenas índices
    for (i = 0; i < n1; i++)
        V_Esquerda[i] = numeros[esquerda + i];
    for (j = 0; j < n2; j++)
        V_Direita[j] = numeros[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;

    // Junta as duas partes de forma ordenada no vetor original
    while (i < n1 && j < n2)
    {
        m->comparacoes++;
        if (V_Esquerda[i] <= V_Direita[j])
        {
            numeros[k] = V_Esquerda[i];
            i++;
        }
        else
        {
            numeros[k] = V_Direita[j];
            j++;
        }
        m->trocas++; 
        k++;
    }

    // Copia os elementos restantes, se houver
    while (i < n1)
    {
        numeros[k] = V_Esquerda[i];
        m->trocas++; 
        i++;
        k++;
    }
    while (j < n2)
    {
        numeros[k] = V_Direita[j];
        m->trocas++; 
        j++;
        k++;
    }
}

void MergesortIterativo(int *numeros, int tamanho, Metricas *m){
    // tamanho_atual controla o tamanho dos subvetores que serão mesclados (1, 2, 4, 8...)
    for (int tamanho_atual = 1; tamanho_atual <= tamanho - 1; tamanho_atual = 2 * tamanho_atual)
    {

        // esquerda identifica o início do subvetor da esquerda que será mesclado
        for (int esquerda = 0; esquerda < tamanho - 1; esquerda += 2 * tamanho_atual)
        {

            // Encontra o ponto médio e o ponto final dos dois subvetores adjacentes
            int meio = Menor(esquerda + tamanho_atual - 1, tamanho - 1);
            int direita = Menor(esquerda + 2 * tamanho_atual - 1, tamanho - 1);

            // Junta as duas partes criadas
            Intercalar(numeros, esquerda, meio, direita, m);
        }
    }
}

// MergeSort Recursivo
// Parte recursiva: só ordena, não imprime nada
void MergesortRec(int *numeros, int esquerda, int direita, Metricas *m)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        MergesortRec(numeros, esquerda, meio, m);
        MergesortRec(numeros, meio + 1, direita, m);

        Intercalar(numeros, esquerda, meio, direita, m);
    }
}

// Função chamada pelo menu: ordena e imprime uma única vez
void MergesortRecursivo(int *numeros, int tam, Metricas *m)
{
    MergesortRec(numeros, 0, tam - 1, m);
}

// QuickSort pivo inicio
// Função de particionamento usando o PRIMEIRO elemento como pivo
int particionarInicio(int *numeros, int inicio, int fim, Metricas *m)
{
    int pivo = numeros[inicio]; // Define o pivo como o primeiro elemento
    int i = fim + 1;            // Limite para os elementos maiores que o pivo

    // Percorre o vetor de trás para frente, até o elemento logo após o pivo
    for (int j = fim; j >= inicio + 1; j--)
    {
        m->comparacoes++;
        if (numeros[j] > pivo)
        {
            i--;
            // Troca direta usando uma variável temporária
            int temp = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = temp;
            m->trocas++; 
        }
    }

    // Troca o pivo para a sua posição correta (i - 1)
    int temp = numeros[i - 1];
    numeros[i - 1] = numeros[inicio];
    numeros[inicio] = temp;
    m->trocas++; 

    return (i - 1); // Retorna a posição correta do pivo
}

void QuickSortPivoInicio(int *numeros, int inicio, int fim, Metricas *m)
{
    if (inicio < fim)
    {
        int pivo = particionarInicio(numeros, inicio, fim, m);
        QuickSortPivoInicio(numeros, inicio, pivo - 1, m);
        QuickSortPivoInicio(numeros, pivo + 1, fim, m);
    }
}

// QuickSort Pivo Inicio chamada main
void QuickSortInicioMain(int *numeros, int tam, Metricas *m)
{
    QuickSortPivoInicio(numeros, 0, tam - 1, m);
}

// QuickSort Pivo Fim
// Função de particionamento usando apenas índices do vetor
int particionarFim(int vetor[], int inicio, int fim, Metricas *m) {
    int pivo = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        m->comparacoes++;
        if (vetor[j] < pivo) {
            i++;
            // Troca direta usando uma variável temporária e índices
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            m->trocas++; 
        }
    }
    // Troca o pivovô para a posição correta
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    m->trocas++; 

    return (i + 1);
}

void QuickSortPivoFim(int *numeros, int inicio, int fim, Metricas *m)
{
    if (inicio < fim)
    {
        int pivo = particionarFim(numeros, inicio, fim, m);
        QuickSortPivoFim(numeros, inicio, pivo - 1, m);
        QuickSortPivoFim(numeros, pivo + 1, fim, m);
    }
}

// QuickSort Pivo Fim chamada main
void QuickSortFimMain(int *numeros, int tam, Metricas *m)
{
    QuickSortPivoFim(numeros, 0, tam - 1, m);
}

// SelectionSort
void SelectionSort(int *numeros, int tam, Metricas *m){
    int i, j, posMenor, aux;
    for(i=0;i<tam-1;i++){
        posMenor = i;
        for(j=i+1;j<tam;j++){
            m->comparacoes++;
            if(numeros[j]<numeros[posMenor])
                posMenor = j;
        }
        if(i!= posMenor){
            aux=numeros[i];
            numeros[i]=numeros[posMenor];
            numeros[posMenor]=aux;
            m->trocas++;
        }
    }
}
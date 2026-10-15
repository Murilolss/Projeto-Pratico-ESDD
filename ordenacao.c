#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "algoritmo.c"
#include "metricas.h"

void menuSelecao(int *vetor, int tam)
{
    int escolha;
    do
    {
        system("cls");
        printf("---- Selecionee o tipo de Algoritmo que deseja utilizar ----\n");
        printf("1 - BubbleSort\n");
        printf("2 - InsertionSort\n");
        printf("3 - MergSort Interativo\n");
        printf("4 - MergeSort Recursivo\n");
        printf("5 - QuickSort Pivo Inicio\n");
        printf("6 - QuickSort Pivo Ultimo\n");
        printf("7 - SelectionSort\n");
        printf("8 - Voltar\n");
        printf("9 - Encerrar Programa\n");
        printf("-----------------------------------------------------------\n");
        printf("Digite uma das Opcoes: ");
        scanf("%d", &escolha);
        while (getchar() != '\n');

        switch (escolha)
        {
        case 1:
        {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));

            Metricas m;
            IniciarMetricas(&m, "Bubble Sort");

            clock_t inicio = clock();
            BubbleSort(copia, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);

            free(copia);
            sleep(5);
        }
        break;

        case 2:
        {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));

            Metricas m;
            IniciarMetricas(&m, "InsertionSort");

            clock_t inicio = clock();
            InsertionSort(copia, tam, &m);
            clock_t fim = clock();
            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
            
            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            sleep(5);
        }
            break;

        case 3:
        {

            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "Mergesort Iterativo");
            
            clock_t inicio = clock();
            MergesortIterativo(vetor, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
            
            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            sleep(5);
        }
            break;

        case 4:
        {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "Mergesort Recursivo");
            
            clock_t inicio = clock();
            MergesortRecursivo(vetor, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
            
            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            sleep(5);
        }
            break;

        case 5:
        {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "QuickSort Inicio");

            clock_t inicio = clock();
            QuickSortInicioMain(vetor, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            sleep(5);
        }

            break;

        case 6:
            {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "QuickSort Fim");

            clock_t inicio = clock();
            QuickSortFimMain(vetor, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            sleep(5);
        }
            break;

        case 7:
            {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "SelectionSort");

            clock_t inicio = clock();
            SelectionSort(vetor, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            sleep(5);
        }
            break;

        case 8:
            return;

        case 9:
            system("cls");
            printf("\nEncerrando o programa.\n");
            exit(0);
            break;

        default:
            system("cls");
            printf("\nOpcao errada! Digite novamente.\n");
            sleep(3);
            break;
        }
    } while (escolha != 9);
}
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

            printf("\nPressione ENTER para continuar...");
            getchar();
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
            free(copia);
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
            break;

        case 3:
        {

            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "Mergesort Iterativo");
            
            clock_t inicio = clock();
            MergesortIterativo(copia, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
            
            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            free(copia);
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
            break;

        case 4:
        {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "Mergesort Recursivo");
            
            clock_t inicio = clock();
            MergesortRecursivo(copia, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
            
            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            free(copia);
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
            break;

        case 5:
        {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "QuickSort Inicio");

            clock_t inicio = clock();
            QuickSortInicioMain(copia, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            free(copia);
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

            break;

        case 6:
            {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "QuickSort Fim");

            clock_t inicio = clock();
            QuickSortFimMain(copia, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            free(copia);
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
            break;

        case 7:
            {
            int *copia = malloc(tam * sizeof(int));
            memcpy(copia, vetor, tam * sizeof(int));
            
            Metricas m;
            IniciarMetricas(&m, "SelectionSort");

            clock_t inicio = clock();
            SelectionSort(copia, tam, &m);
            clock_t fim = clock();

            m.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

            ImprimirVetor(copia, tam);
            ExibirMetricas(&m, tam);
            free(copia);
            printf("\nPressione ENTER para continuar...");
            getchar();
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
            printf("\nPressione ENTER para continuar...");
            getchar();
            break;
        }
    } while (escolha != 9);
}

// Metricas: roda todos os algoritmos com o mesmo vetor e mostra o resultado de todos juntos
void menuMetricas(int *vetor, int tam)
{
    Metricas resultados[7];
    clock_t inicio, fim;

    int *copia = malloc(tam * sizeof(int));

    // BubbleSort
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[0], "BubbleSort");
    inicio = clock();
    BubbleSort(copia, tam, &resultados[0]);
    fim = clock();
    resultados[0].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // InsertionSort
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[1], "InsertionSort");
    inicio = clock();
    InsertionSort(copia, tam, &resultados[1]);
    fim = clock();
    resultados[1].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // Mergesort Iterativo
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[2], "Mergesort Iterativo");
    inicio = clock();
    MergesortIterativo(copia, tam, &resultados[2]);
    fim = clock();
    resultados[2].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // Mergesort Recursivo
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[3], "Mergesort Recursivo");
    inicio = clock();
    MergesortRecursivo(copia, tam, &resultados[3]);
    fim = clock();
    resultados[3].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // QuickSort Pivo Inicio
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[4], "QuickSort Pivo Inicio");
    inicio = clock();
    QuickSortInicioMain(copia, tam, &resultados[4]);
    fim = clock();
    resultados[4].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // QuickSort Pivo Fim
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[5], "QuickSort Pivo Fim");
    inicio = clock();
    QuickSortFimMain(copia, tam, &resultados[5]);
    fim = clock();
    resultados[5].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    // SelectionSort
    memcpy(copia, vetor, tam * sizeof(int));
    IniciarMetricas(&resultados[6], "SelectionSort");
    inicio = clock();
    SelectionSort(copia, tam, &resultados[6]);
    fim = clock();
    resultados[6].tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    free(copia);

    ExibirTabelaMetricas(resultados, 7, tam);
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

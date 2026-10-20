#include <stdio.h>
#include <string.h>
#include "metricas.h"

void IniciarMetricas(Metricas *m, const char *nome) {
    strncpy(m->nome, nome, sizeof(m->nome) - 1);
    m->nome[sizeof(m->nome) - 1] = '\0';
    m->comparacoes = 0;
    m->trocas = 0;
    m->tempo_ms = 0.0;
}

void ImprimirVetor(const int *numeros, int tam) {
    printf("\nNumeros no Vetor Ordenado: {");
    for (int i = 0; i < tam; i++) {
        printf("%d ", numeros[i]);
    }
    printf("}\n");
}

void ExibirMetricas(const Metricas *m, int tam) {
    printf("\n===== Relatorio de Desempenho =====\n");
    printf("Algoritmo:    %s\n", m->nome);
    printf("Itens:        %d\n", tam);
    printf("Tempo:        %.3f ms\n", m->tempo_ms);
    printf("Comparacoes:  %lld\n", m->comparacoes);
    printf("Trocas:       %lld\n", m->trocas);
    printf("===================================\n");
}

void ExibirTabelaMetricas(const Metricas *lista, int qtd, int tam) {
    printf("\n=================== Metricas dos Metodos de Ordenacao ===================\n");
    printf("Itens no vetor: %d\n\n", tam);
    printf("%-22s %12s %15s %15s\n", "Algoritmo", "Tempo (ms)", "Comparacoes", "Trocas");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("%-22s %12.3f %15lld %15lld\n",
               lista[i].nome, lista[i].tempo_ms, lista[i].comparacoes, lista[i].trocas);
    }
    printf("=========================================================================\n");
}

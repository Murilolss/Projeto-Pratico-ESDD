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

void ExibirMetricas(const Metricas *m, int tam) {
    printf("\n===== Relatorio de Desempenho =====\n");
    printf("Algoritmo:    %s\n", m->nome);
    printf("Itens:        %d\n", tam);
    printf("Tempo:        %.3f ms\n", m->tempo_ms);
    printf("Comparacoes:  %lld\n", m->comparacoes);
    printf("Trocas:       %lld\n", m->trocas);
    printf("===================================\n");
}
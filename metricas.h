#ifndef METRICAS_H
#define METRICAS_H

typedef struct {
    char nome[30];
    long long comparacoes;
    long long trocas;
    double tempo_ms;
} Metricas;

void IniciarMetricas(Metricas *m, const char *nome);
void ExibirMetricas(const Metricas *m, int tam);
void ImprimirVetor(const int *numeros, int tam);

#endif
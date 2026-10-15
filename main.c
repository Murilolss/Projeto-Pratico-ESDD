#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alocarVet.c"
#include "ordenacao.c"

void menu(int *vetor, int tam);

int main()
{
    int tam;
    int *numeros = (int *)malloc(tam * sizeof(int));

    if (numeros == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite o Tamanho do vetor: ");
    scanf("%d", &tam);
    alocarVetor(numeros, tam);

    menu(numeros, tam);
    return 0;
}

// Menu de Seleção
void menu(int *vetor, int tam)
{
    int escolha;
    do
    {
        system("cls");
        printf("---- Selecione uma Da Opcoes ----\n");
        printf("1 - Metodos de Ordenacao\n");
        printf("2 - Metodos de Busca\n");
        printf("3 - Mostrar Vetor\n");
        printf("4 - Encerrar Programa\n");
        printf("------------------------------\n");
        printf("Digite uma das Opcoes: ");
        scanf("%d", &escolha);
        while (getchar() != '\n');

        switch (escolha)
        {
        case 1:
            system("cls");
            menuSelecao(vetor, tam);
            break;

        case 2:
            system("cls");
            break;

        case 3:
            system("cls");
            printf("\nNumeros no Vetor: {");
            for (int i = 0; i < tam; i++)
            {
                printf("%d ", vetor[i]);
            }
            printf("}");

            sleep(3);
            break;

        case 4:
            system("cls");
            printf("\nEncerrando o programa.\n");
            break;

        default:
            system("cls");
            printf("\nOpcao errada! Digite novamente.\n");
            sleep(3);
            break;
        }
    } while (escolha != 4);
}

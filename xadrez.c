#include <stdio.h>

#define CASAS_BISPO   5   /* Bispo: 5 casas na diagonal */
#define CASAS_TORRE   5   /* Torre: 5 casas para a direita */
#define CASAS_RAINHA  8   /* Rainha: 8 casas para a esquerda */

void main() {
    /* --- Bispo: 5 casas na diagonal superior direita --- */
    printf("\n[Bispo] 5 casas - diagonal superior direita:\n");
    for (int i = 0; i < CASAS_BISPO; i++) {
        printf("  Cima\n");
        printf("  Direita\n");
    }

    /* --- Torre: 5 casas para a direita --- */
    printf("\n[Torre] 5 casas para a direita:\n");
    int t = 0;
    while (t < CASAS_TORRE) {
        printf("  Direita\n");
        t++;
    }

    /* --- Rainha: 8 casas para a esquerda --- */
    printf("\n[Rainha] 8 casas para a esquerda:\n");
    int r = 0;
    do {
        printf("  Esquerda\n");
        r++;
    } while (r < CASAS_RAINHA);
}


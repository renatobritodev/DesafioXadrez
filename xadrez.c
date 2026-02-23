/*
 * ============================================================
 *  MateCheck - Desafio de Xadrez
 *  Níveis: Novato | Aventureiro | Mestre
 * ============================================================
 */

#include <stdio.h>

/* CONSTANTES */
#define CASAS_BISPO 5  /* Bispo: 5 casas na diagonal */
#define CASAS_TORRE 5  /* Torre: 5 casas para a direita */
#define CASAS_RAINHA 8 /* Rainha: 8 casas para a esquerda */

/* Movimentação do Cavalo em L */
#define CAVALO_VERTICAL 2   /* 2 casas na vertical */
#define CAVALO_HORIZONTAL 1 /* 1 casa na horizontal */

void nivel_novato()
{
  printf("\n[Bispo] 5 casas - diagonal superior direita:\n");
  for (int i = 0; i < CASAS_BISPO; i++)
  {
    printf("  Cima\n");
    printf("  Direita\n");
  }

  printf("\n[Torre] 5 casas para a direita:\n");
  int t = 0;
  while (t < CASAS_TORRE)
  {
    printf("  Direita\n");
    t++;
  }

  /* --- Rainha: 8 casas para a esquerda ---
   * Usamos loop DO-WHILE conforme requisito. */
  printf("\n[Rainha] 8 casas para a esquerda:\n");
  int r = 0;
  do
  {
    printf("  Esquerda\n");
    r++;
  } while (r < CASAS_RAINHA);
}

void nivel_aventureiro()
{
  printf("\n[Cavalo] Movimento em L - Baixo e Esquerda:\n");

  int horizontal = 0; /* contador do passo horizontal, declarado fora do for */

  for (int vertical = 0; vertical < CAVALO_VERTICAL; vertical++)
  {
    printf("  Baixo\n");
    while (vertical == CAVALO_VERTICAL - 1 && horizontal < CAVALO_HORIZONTAL)
    {
      printf("  Esquerda\n");
      horizontal++;
    }
  }
}

/* Recursão: Bispo - 5 casas diagonal superior direita */
void bispo_recursivo(int casas)
{
  if (casas <= 0)
    return; /* Caso base: para quando não há mais casas */
  printf("  Cima\n");
  printf("  Direita\n");
  bispo_recursivo(casas - 1); /* Chamada recursiva */
}

/* Recursão: Torre - 5 casas para a direita */
void torre_recursiva(int casas)
{
  if (casas <= 0)
    return;
  printf("  Direita\n");
  torre_recursiva(casas - 1);
}

/* Recursão: Rainha - 8 casas para a esquerda */
void rainha_recursiva(int casas)
{
  if (casas <= 0)
    return;
  printf("  Esquerda\n");
  rainha_recursiva(casas - 1);
}

void nivel_mestre()
{
  /* --- Bispo: recursão --- */
  printf("\n[Bispo] 5 casas - diagonal superior direita (recursivo):\n");
  bispo_recursivo(CASAS_BISPO);

  /* --- Torre: recursão --- */
  printf("\n[Torre] 5 casas para a direita (recursivo):\n");
  torre_recursiva(CASAS_TORRE);

  /* --- Rainha: recursão --- */
  printf("\n[Rainha] 8 casas para a esquerda (recursivo):\n");
  rainha_recursiva(CASAS_RAINHA);

  printf("\n[Cavalo] Movimento em L - Cima e Direita:\n");

  int v, h;
  for (v = 1; v <= CAVALO_VERTICAL; v++)
  {
    /* Apenas imprime "Cima" nos 2 passos verticais */
    if (v > CAVALO_VERTICAL)
      continue; /* guarda para demonstrar continue */
    printf("  Cima\n");

    /* Passo horizontal apenas no último passo vertical */
    if (v == CAVALO_VERTICAL)
    {
      for (h = 1; h <= 3; h++)
      { /* loop propositalmente maior */
        if (h > CAVALO_HORIZONTAL)
          break; /* break: só 1 casa horizontal */
        printf("  Direita\n");
      }
    }
  }
}

int main()
{
  printf("\n╔══════════════════════════════════════╗\n");
  printf("║     MATECHECK - DESAFIO DE XADREZ    ║\n");
  printf("╚══════════════════════════════════════╝\n");

  nivel_novato();
  nivel_aventureiro();
  nivel_mestre();

  return 0;
}
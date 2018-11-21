#include "insercao.h"
#include "particiona.h"


/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort com inserção e devolve v       */

int *quicksort_insercao(int v[], int a, int b, unsigned int m) {
  
    if ((b - a + 1) <= m)                           // quando tamanho das particoes do vetor (n) eh menor ou igual a m (valor calculado na bateria de testes)
        return insercao(v, a, b);                   // entra na base e chama insercao (Insertion Sort) para v[a..b] para ordenar esses pedacos

    unsigned int n = particiona(v, a, b, v[b]);     // n recebe resultado da funcao particiona: indice correto, em ordenacao, do elemento pivo (ultimo elemento de v)
    quicksort_insercao(v, a, n - 1, m);             // chama, recursivamente, quicksort_insercao para v[a..n - 1] e passa tambem o m
    quicksort_insercao(v, n + 1, b, m);             // chama, recursivamente, quicksort_insercao para v[n + 1..b] e passa tambem o m
}

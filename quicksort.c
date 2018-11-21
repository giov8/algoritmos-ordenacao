#include "particiona.h"
#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort e devolve v */

int *quicksort(int v[], int a, int b) {
    if (a >= b)                                     // quando os indices do vetor se invertem ou sao iguais (n == 1)  
        return v;                                   // cai na base e devolve o vetor

    unsigned int m = particiona(v, a, b, v[b]);     // m recebe resultado da funcao particiona: indice correto, em ordenacao, do elemento pivo (ultimo elemento de v)
    quicksort(v, a, m - 1);                         // chama, recursivamente, quicksort para v[a..m - 1]
    quicksort(v, m + 1, b);                         // chama, recursivamente, quicksort para v[m + 1..b]
}

#include "biblioteca.h"


/* -------------------------------------------------------------------------- */
/* modifica v e devolve um índice m de forma que */
/* a-1 <= m <= b */
/* v[i] <= x, para todo a <= i <=m */
/* x < v[i], para todo m < i <=b */

int particiona(int v[], int a, int b, int x) {
    
    int m = a - 1;                              // m recebe a - 1 (uma posicao antes do inicio do vetor)
    for (unsigned int i = a; i <= b; i++)       // de a até b, i eh incrementado de 1 em 1
        if (compara(v[i], x) < 1) {             // se (v[i] <= x) 
            m++;                                // m eh incrementado em 1
            troca(v, m, i);                     // chama funcao que troca v[m] e v[i]
        }
    return m;                                   // devolve o indice m
}


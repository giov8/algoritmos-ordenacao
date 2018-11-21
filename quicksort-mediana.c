#include "particiona.h"
#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */

static int mediana(int a, int b, int c) {
    int x = compara(a, b);
    int y = compara(b, c);
    int z = compara(a, c);
    
    if (((x <= 0) && (y <= 0)) || ((x >= 0) && (y >= 0)))   // if (((a <= b) && (b <= c)) || ((c <= b) && (b <= a)))
        return b;
    if (((y >= 0) && (z <= 0)) || ((z >= 0) && (x <= 0)))   // if (((b <= a) && (a <= c)) || ((c <= a) && (a <= b))) 
        return a;
    return c;
    
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b) {
  
    if (a >= b)                                     // quando os indices do vetor se invertem ou sao iguais (n == 1)  
        return v;                                   // cai na base e devolve o vetor

    int x = sorteia(a, b);                          // x recebe resultado da funcao sorteia, um num. pseudo-aleatorio entre a e b (indices de inicio e de fim de v)
    int y = sorteia(a, b);                          // y recebe resultado da funcao sorteia, um num. pseudo-aleatorio entre a e b (indices de inicio e de fim de v)
    int z = sorteia(a, b);                          // z recebe resultado da funcao sorteia, um num. pseudo-aleatorio entre a e b (indices de inicio e de fim de v)

    int n = mediana(v[x], v[y], v[z]);              // n recebe a mediana entre v[x], v[y], v[z]

    unsigned int p;                                 // variavel p sera o pivo e recebera o indice da mediana entre os valores das tres posicoes do vetor sorteadas
    
    if (compara(n, v[x]) == 0)                      // se (n == v[x]) p = x
        p = x;
    else if (compara(n, v[y]) == 0)                 // se (n == v[y]) p = y
            p = y;
        else                                        // se (n == v[z]) p = z;
            p = z;              
    
    troca(v, p, b);                                 // usa funcao troca para trocar o valor da ultima posicao do vetor (v[b]) com o valor da posicao pivo (v[p]) 

    unsigned int m = particiona(v, a, b, v[b]);     // m recebe resultado da funcao particiona: indice correto, em ordenacao, do elemento pivo (ultimo elemento de v)
    quicksort_mediana(v, a, m - 1);                 // chama, recursivamente, quicksort_mediana para v[a..m - 1]
    quicksort_mediana(v, m + 1, b);                 // chama, recursivamente, quicksort_mediana para v[m + 1..b]
}







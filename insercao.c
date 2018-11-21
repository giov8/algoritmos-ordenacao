#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* busca em v[a..b] e x é o elemento que procuramos, a funcao devolve o indice de x
se existir ou a-1 se nao encontrar e v é um vetor ordenado*/

int busca(int x, int v[], int a, int b) {
    if (a > b)                                      // quando os indices do vetor se invertem
        return (a - 1);                             // retorna a-1 porque o elemento nao foi encontrado
    if (compara(x, v[b]) > -1)                      // se x >= v [b]
        return b;                                   // devolve b
    return busca(x, v, a, b - 1);                   // chamada recursiva da funcao para v[a..b - 1]
}

/* -------------------------------------------------------------------------- */
/* recebe v[a..b], sendo v[a..b - 1] um vetor ordenado, e devolve um vetor ordenado v[a..b] */

int *insere(int v[], unsigned int a, unsigned int b) {
    int p = busca(v[b], v, a, b - 1);               // p recebe o resultado da funcao busca, um indice, para v[b] no vetor v[a..b-1]
        
    for (int i = b; i > p + 1; i--)                 // de i == b ate  i > p + 1, i eh incrementado de 1 em 1 e...     
        troca(v, i, i - 1);                         // chama a funcao troca para trocar v[i] e v[i - 1]
    return v;                                       // devolve v
}

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo método da INSERÇÃO (estava escrito "seleção", porém achamos que foi um erro) e devolve v */

int *insercao(int v[], unsigned int a, unsigned int b) {
    if (a >= b)                                     // quando os indices do vetor se invertem ou sao iguais (n == 1)  
        return v;                                   // cai na base e devolve o vetor

    insercao(v, a, b - 1);                          // chama, recursivamente, insercao (Insertion Sort) para v[a..b - 1]
    insere(v, a, b);                                // chama a funcao insere para v[a..b]
    return v;                                       // devolve v
}



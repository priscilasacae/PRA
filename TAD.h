#ifndef TAD_H_
#define TAD_H_
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*=========================================*/
/*Árvore*/
/*=========================================*/
typedef struct arvore Arvore;

struct arvore{
    Arvore *esq;
    char airline[3], airline_id[5], source[3], source_id[4], destination[3], destination_id[4], codeShare[1], stops[1], equipament[36];
    Arvore *dir;
};

Arvore *criaArv();
void salvaItem (Arvore *no, FILE *arq);
void salvaArquivo (Arvore *no);
Arvore *carregaArquivo (Arvore *no);
void busca(Arvore *no, int conta);
void imprimirIn(Arvore *no);

#endif /* TAD_H_ */

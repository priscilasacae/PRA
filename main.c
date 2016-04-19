/*
===========================================
Nome        : �rvore AVL
Autor       : Ismaily
===========================================

===============Tabela ASCII================
160-�|133-�|198-�|    |181-�|183-�|199-�|
130-�|                |144-�|
161-�|                |214-�|
162-�|147-�|          |224-�|226-�|
163-�|                |233-�|
135-�|                |128-�|
===========================================
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include "TAD.h"

/*=========================================*/
/*Programa Principal*/
/*=========================================*/

int main()
{
    Arvore *raiz = NULL;
    char nome[31];
    int op,i;
    int conta,CPF;

    for(i=0; i<256; i++) //Tabela ASCII
do{
		   printf("+--------------------------------+\n");
		   printf("|Menu Principal                  |\n");
		   printf("|--------------------------------|\n");
		   printf("|2 Buscar                        |\n");
		   printf("|4 Imprimir Em-Ordem             |\n");
		   printf("|5 Salvar no HD                  |\n");
		   printf("|6 Carregar do HD                |\n");
		   printf("|7 Sair                          |\n");
		   printf("+--------------------------------+\n");
		   printf("Entre com a op%c%co desejada: ",135,198);
		   fflush(stdin);
		   scanf("%d",&op);

switch(op){

    case 2:
            printf("Digite o n%cmero da conta para buscar: ",163);
            scanf("%d",&conta);
            busca(raiz,conta);
            system ("pause");
            system ("cls");
            break;


	case 4:
            printf("Imprimir Em-Ordem:\n\n");
            imprimirIn(raiz);
            printf("\n");
            system("pause");
            system("cls");
            break;

    case 5:
            salvaArquivo(raiz);
            printf("Os dados foram salvas com sucesso para o arquivo (arquivo.bin)\n\n");
            system ("pause");
            system("cls");
            break;

    case 6:
            carregaArquivo(raiz);
            printf("Os dados foram carregados com sucesso a partir do arquivo (arquivo.bin)\n\n");
            system ("pause");
            system ("cls");
            break;

	case 7:
            exit(0);

	default:
            printf("WRONG, BITCH!!!\n");
            system ("pause");
            system ("cls");
            break;
        }
}

    while(op!=5);
    exit(0);

 return 0;

}

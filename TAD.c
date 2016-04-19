#include "TAD.h"

/*=========================================*/
/*Criar nova árvore*/
/*=========================================*/
Arvore *criaArv(){
    return NULL;
    }

/*=========================================*/
/*Salva arquivo*/
/*=========================================*/
void salvaArquivo (Arvore *no){
    FILE *arq;
    arq=fopen("arquivo.dat","wb");
    salvaItem(no,arq);
    fclose(arq);
}

void salvaItem (Arvore *no, FILE *arq){
    fwrite(&no->conta,sizeof(int),1,arq);
    fwrite(&no->CPF,sizeof(int),1,arq);
    fwrite(&no->nome,sizeof(char),31,arq);
    if(no->esq)salvaItem(no->esq,arq);
    if(no->dir)salvaItem(no->dir,arq);
}

/*=========================================*/
/*Carrega arquivo*/
/*=========================================*/
Arvore *carregaArquivo (Arvore *no){
    FILE *arq;
    char airline[3], airline_id[5], source[3], source_id[4], destination[3], destination_id[4], codeShare[1], stops[1], equipament[36];
    arq=fopen("arquivo.dat", "rb");
    if(arq!=NULL){
        while(!feof(arq)){
            fread(&airline,sizeof(char),3,arq);
            fread(&airline_id,sizeof(char),5,arq);
            fread(&source,sizeof(char),3,arq);
            fread(&source_id,sizeof(char),4,arq);
            fread(&destination,sizeof(char),3,arq);
            fread(&destination_id,sizeof(char),4,arq);
            fread(&codeShare,sizeof(char),1,arq);
            fread(&stops,sizeof(char),1,arq);
            fread(&equipament,sizeof(char),36,arq);
        if(!feof(arq))
            inserir(no, airline, airline_id, source, source_id, destination, destination_id, codeShare, stops, equipament);

        }
    }
            return no;
}

/*=========================================*/
/*Inserir*/
/*=========================================*/
Arvore *inserir(Arvore *no, char airline[3], char airline_id[5], char source[3], char source_id[4], char destination[3], char destination_id[4], char codeShare[1], char stops[1], char equipament[36])
{
    if(no == NULL){
        no = (Arvore*)malloc(sizeof(Arvore));
        strcpy(no->airline, airline);
        strcpy(no->airline_id, airline_id);
        strcpy(no->source, source);
        strcpy(no->source_id, source_id);
        strcpy(no->destination, destination);
        strcpy(no->destination_id, destination_id);
        strcpy(no->codeShare, codeShare);
        strcpy(no->stops, stops);
        strcpy(no->equipament, equipament);
        no->esq = NULL;
        no->dir = NULL;
        printf("\nCadastrado com sucesso!\n");
    }
    else{
        if(source > no->source){
            no->dir = inserir(no, airline, airline_id, source, source_id, destination, destination_id, codeShare, stops, equipament);
        }
        if(source < no->source){
            no->esq = inserir(no, airline, airline_id, source, source_id, destination, destination_id, codeShare, stops, equipament);
        }
    }
    return no;
}

/*=========================================*/
/*Buscar*/
/*=========================================*/
void busca(Arvore *no, char source)
{
    if(no == NULL)
    {
        printf("\nN%co encontrado.\n",198);
    }
    else if(no->source == source)
    {
        //printf("\nNome:......: %s\nCPF........: %d\n\n", no->nome, no->CPF);
    }
    else
    {
        if(source > no->source)
        {
            busca(no->dir, source);
        }
        else if(conta < no->source)
        {
            busca(no->esq, source);
        }
    }
}

/*=========================================*/
/*Imprimir Em-Ordem*/
/*=========================================*/
void imprimirIn(Arvore *no){
    if(no != NULL){
        imprimirIn(no->esq);
        printf("Airline: %s Airline_id: %s Source: %s Source_id: %s Destination: %s Destination_id: %s Codeshare: %s Stops: %s Equipment: %s \n", no->airline, no->airline_id, no->source, no->source_id, no->destination, no->destination_id, no->codeShare, no->stops, no->equipament);
        imprimirIn(no->dir);
    }
}

#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int chave;
    struct no *prox;
}no;
no *cria_lista_vazia_cabeca(no *L){
        no *cabeca=(no*)calloc(1,sizeof(no));
        if(cabeca!=NULL){
            return cabeca;
        }
        else{
            printf("Erro de alocação");
            exit(1);
        }
}
no* cria_lista_vazia_sentinela(no *L){
    no *sentinela=(no*)calloc(1,sizeof(no));
    if(sentinela!=NULL){
            sentinela->prox=NULL;
            return sentinela;
        }
        else
            printf("Erro de alocação");
            exit(1);
}
no* cria_lista_vazia_cabeca_e_sentinela(no *L){
    no *sentinela=(no*)calloc(1,sizeof(no));
    no *cabeca=(no*)calloc(1,sizeof(no));
    if(sentinela!=NULL&&cabeca!=NULL){
            cabeca->prox=sentinela;
            sentinela->prox=NULL;
            return cabeca;
        }
        else
            printf("Erro de alocação");
            exit(1);
}
no *cria_no(int chave){
    no *novo=(no*)malloc(sizeof(no));
    if(novo!=NULL){
        novo->chave=chave;
        novo->prox=NULL;
    }
    else printf("Erro de alocacao");
    return novo;
}
no *insere_no_inicio_sentinela(no *L,no *novo){
    novo->prox=L;
    L=novo;
    return L;
}
no *insere_no_final_cabeca(no *L,no *novo){
    no *aux=L;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=novo;
    return L;
}
no *insere_no_cabeca_sentinela(no *L,no *novo){
    novo->prox=L->prox;
    L->prox=novo;
    return L;
}
void imprime_com_sentinela(no *L){
    no *aux=L;
    if(aux->prox==NULL)
        exit(1);
    while (aux->prox!=NULL){
            printf("%d ",aux->chave);
            aux=aux->prox;
    }
}
void imprime_com_cabeca(no *L){
    no *aux=L;
    if(aux->prox==NULL)
        exit(1);
    aux=aux->prox;
    while (aux!=NULL){
            printf("%d ",aux->chave);
            aux=aux->prox;
    }
}

void imprime_com_cabeca_e_sentinela(no *L){
    no *aux=L;
    if(aux->prox==NULL)
        exit(1);
    aux=aux->prox;
    while (aux->prox!=NULL){
            printf("%d ",aux->chave);
            aux=aux->prox;
    }
}
int main()
{
    no *L=NULL,*novo=NULL;
    L=cria_lista_vazia_cabeca_e_sentinela(L);
    novo=cria_no(5);
    L=insere_no_cabeca_sentinela(L,novo);
    novo=cria_no(4);
    L=insere_no_cabeca_sentinela(L,novo);
    novo=cria_no(3);
    L=insere_no_cabeca_sentinela(L,novo);
    novo=cria_no(2);
    L=insere_no_cabeca_sentinela(L,novo);
    novo=cria_no(1);
    L=insere_no_cabeca_sentinela(L,novo);
    imprime_com_cabeca_e_sentinela(L);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct no{
   int chave;
   struct no *ant;
   struct no *prox;
}no;
no *cria(int chave){
    no *novo=(no*)calloc(1,sizeof(no));
    if(novo!=NULL){
        novo->chave=chave;
        novo->prox=NULL;
        novo->ant=NULL;
    }
    else printf("Erro de alocacao");
    return novo;
}
no *insere_inicio(no *L,no *novo){
    if(L!=NULL){
        novo->prox=L;
        L->ant=novo;
    }
    return novo;
}
void imprime(no *L){
    no *aux=L;
    while(aux!=NULL){
        printf("%d ",aux->chave);
        aux=aux->prox;
    }
}
no *busca(no *L,int chave){
    no *aux=L;
    while(aux!=NULL&&aux->chave!=chave){
        aux=aux->prox;
    }
    return aux;
}
no *exclui_inicio(no *L){
    no *aux=L;
    if(L==NULL)
        return L;
    L=L->prox;
    if(L!=NULL)
        L->ant=NULL;
    free(aux);
    return L;
}
no *insere_final(no *L,no *novo){
    no *aux=L;
    if(L!=NULL){
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=novo;
        novo->ant=aux;
    }
    else L=novo;
    return L;
}
no *remove_final(no *L){
    no *aux=L;
    if(L==NULL)
        return L;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    if(aux->ant==NULL)
        L=NULL;
    else aux->ant->prox=NULL;
    free(aux);
    return L;

}
no *insere_ordenado(no *L,no *novo){
    no *aux=L;
    if(L==NULL)
        return novo;
    while(aux->prox!=NULL){
        if(aux->chave>novo->chave)break;
        aux=aux->prox;
    }
    if(aux->ant==NULL&&aux->chave>novo->chave){
        aux->ant=novo;
        novo->prox=aux;
        L=novo;
    }
    else if(aux->prox==NULL&&aux->chave<novo->chave){
        novo->prox=aux->prox;
        aux->prox->ant=novo;
        novo->ant=aux;
        aux->prox=novo;

    }
    else {
        novo->ant=aux->ant;
        novo->prox=aux;
        aux->ant->prox=novo;
        aux->ant=novo;
    }
    return L;
}
no *remocao_chave_dada(no *L,int chave){
    //declaracao das variaveis
    no*aux=L;
    //caso: Lista vazia
    if(L==NULL)
        return L;
    //laço de repetição para,pecorrer a lista até o final{
    while(aux!=NULL){
        //caso seja o primeiro: aux->ant==NULL;
        if(aux->ant==NULL){
            L=aux->prox;
            aux->prox->ant=NULL;
            free(aux);
        }
        //caso seja o ultimo: aux->prox==NULL;
        else if(aux->prox==NULL){
            aux->ant->prox=NULL;
            free(aux);
        }
        //caso seja no meio: defalt}
        else{
            aux->prox->ant=aux->ant;
            aux->ant->prox=aux->prox;
            free(aux);
        }
    //retornar
    }
    return L;
}




















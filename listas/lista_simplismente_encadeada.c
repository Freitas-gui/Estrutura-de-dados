#include<string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int chave;
    struct no *prox;
}no;

no *cria(int chave){
    no *novo=(no*)malloc(sizeof(no));
    if(novo!=NULL){
        novo->chave=chave;
        novo->prox=NULL;
    }
    else printf("Erro de alocacao");
    return novo;
}

no *InsereInicio(no *L,no *novo){
    novo->prox=L;
    L=novo;
    return L;
}

void imprime(no *L){
    no *aux=L;
    while (aux!=NULL){
            printf("%d ",aux->chave);
            aux=aux->prox;
    }
}
no *busca(no *L,int chave){
    no *aux=L;
    while (aux!=NULL){
        if(aux->chave==chave) break;
        aux=aux->prox;
    }
    return aux;
}
no *ExcluiPrimeiro(no *L){
    no *aux=L;
    if(aux!=NULL){
        L=aux->prox;
        free(aux);
    }
    return(L);
}
no *RemoveFinal(no *L){
    no *aux=L;
    no *ant=NULL;
    if(L!=NULL){
        while(aux->prox!=NULL){
            ant=aux;
            aux=aux->prox;
        }
        if(ant!=NULL) ant->prox=NULL;
        else L=NULL;
        free(aux);
    }
    return L;
}
no *InsereOrdenado(no *L, no *novo){
    no *aux=L,*ant=NULL;
    while(aux!=NULL&&aux->chave<novo->chave){
        ant=aux;
        aux=aux->prox;
    }
    novo->prox=aux;
    if(ant==NULL) L=novo;
    else ant->prox=novo;
    return L;
}
no *RemoveNOrdenado(no *L,int chave){
    no *aux=L,*ant=NULL;
    if (L!=NULL){
        while(aux!=NULL&&aux->chave!=chave){
            ant=aux;
            aux=aux->prox;
        }
        if(ant==NULL) L=NULL;
        else if(aux!=NULL)
            ant->prox=aux->prox;
        free(aux);
    }
    return L;
}
no *PalavraEmLista(char *palavra){
    //criar lista
    no *L=NULL,*novo=NULL;
    //percorrer td a palavra, do final para o inicil
    int tam=strlen(palavra);
    if(tam>0){
        tam--;
        while(tam>=0){
            novo=cria(palavra[tam]);
            L=InsereInicio(L,novo);
            tam--;
        }
    }
    return L;
    //insere cada caractere no inicio da lista
    //retorna a lista
}
char *ListaEmPalavra(no *L){
    no *aux=L,*novo=NULL;
    char *palavra=(char*)malloc(sizeof(char));;
    int i=0;
    while(aux!=NULL){
        i++;
        palavra=(char*)realloc(palavra,sizeof(char)*i);
        if(palavra==NULL){
            printf("Erro de alocacao");
            return NULL;
        }
        else{
            palavra[i-1]=aux->chave;
            aux=aux->prox;
        }
    }
    else{
        palavra=(char*)realloc(palavra,sizeof(char)*i);
        palavra[i]='\0';
    }
    return palavra;
}
int ComparaTamPalavra(no *L,no* L2){
    //declaraçao de variaveis para pecorrer as listas
    no *aux=L,*aux2=L2;
    int resultado=0;
    //pecorrer a palavra L
    while(aux!=NULL){
    //verificar se o caracte atual é menor ou maior
        if(aux2==NULL){
            resultado=1;
            break;
        }
        else if(aux->chave>aux2->chave){
            resultado=1;
            break;
        }
        else if(aux->chave<aux2->chave){
            resultado=-1;
            break;
        }
        else{
            aux=aux->prox;
            aux2=aux2->prox;
        }

    }
    //retorna 1,0,-1
    return resultado;
}
no *InverteOrdem(no *L){
    no *aux=L,*L2=NULL,*novo;
    while(aux!=NULL){
        novo=cria(aux->chave);
        L2=InsereInicio(L2,novo);
        aux=aux->prox;
    }
    return L2;
}

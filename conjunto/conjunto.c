#include"conjunto.h"
conjunto *cria(){
    conjunto *c;
    c=NULL;
    return c;
}
conjunto *inserir(conjunto *c,int valor){
    /*resava um espaco de memoria para o novo valor a ser inserido*/
    conjunto *novo=(conjunto*)malloc(sizeof(conjunto));
    if(novo!=NULL){
        /*o novo elemento recebe um valor e aponta para o primeiro elemento do conjunto q sera enserido,caso seja o primeiro a ser inserido, aponta para NULL */
        novo->chave=valor;
        novo->prox=c;
    }
    else
        printf("\nErro de alocacao");
    /* o novo elemento é inserido no inicio do conjunto,*/
    c=novo;
    return c;
}
conjunto *exclui(conjunto *c,int valor){
    conjunto *aux=c,*ant=NULL;
    /*esse while pecorre o conjunto, até achar o valor ou até chegar no fim do conjunto */
    while(aux!=NULL&&aux->chave!=valor){
        /*ant se posiciona um elemento antes do auxiliar q pecorre a lista*/
        ant=aux;
        aux=aux->prox;
    }
    /* condicao para o caso de n ter encontrado o valor*/
    if(aux==NULL)
        printf("\nValor nao encontrado");
    /*se encontro o valor, entao essa valor é desvinculado do conjunto */
    else{
        ant->prox=aux->prox;
        free(aux);
    }
    return c;
}
void imprime(conjunto *c){
    conjunto *aux=c;
    printf("\n");
    /* até q pecorra a lista inteira, imprime o elemento, e passa para o proximo */
    while(aux!=NULL){
        printf("%d ",aux->chave);
        aux=aux->prox;
    }
}

void verifica_vazio(conjunto *c){
    if(c==NULL)
        printf("\nconjunto vazio");
    else
        printf("\nconjunto nao vazio");
}
int cardinalidade(conjunto *c){
    conjunto *aux=c;
    int i=0;
    /* enquanto n chegar ao fim da lista, o contador soma mais 1*/
    while(aux!=NULL){
        i++;
        aux=aux->prox;
    }
    return i;
}
void pertence(conjunto *c,int valor){
    conjunto *aux=c;
    /*enquanto n chegar no fim da lista e nao encontrar o valor, o aux, caminha sobre a lista*/
    while(aux!=NULL&&aux->chave!=valor){
        aux=aux->prox;
    }
    /*caso chegue ao fim da lista se ter encontrado o valor */
    if(aux==NULL)
        printf("\nValor nao pertence ao conjunto");
    else
        printf("\nValor pertence ao conjunto");
}
void verifica_subconjunto(conjunto *a,conjunto *b){
    /* conjunto vazio é subconjunto de todos os conjuntos*/
    if(a==NULL)
        printf("\nO primeiro conjunto e subconjunto do segundo");
    else{
        conjunto *auxA=a,*auxB=b;
        /* equanto os 2 conjuntos n chegarem ao fim, o loop continua */
        while(auxB!=NULL&&auxA!=NULL){
            /*caso o valor do elemento de a for igual ao de b, o auxB volta para o inicio e o auxA adianta um elemento*/
            if (auxA->chave==auxB->chave){
                auxB=b;
                auxA=auxA->prox;
            }
            /* se nâo, auxB continua pecorrendo o conjunto, enquanto auxA permanece no msm elemento */
            else
                auxB=auxB->prox;
        }
        /* caso algum elemento de a n for igual a nenhum elemento de b*/
        if(auxB==NULL)
            printf("\nO primeiro conjunto nao e subconjunto do segundo");
        /* caso todos elemento de a forem iguais a todos elemento de b*/
        else
            printf("\nO primeiro conjunto e subconjunto do segundo");
    }
}
conjunto *diferenca(conjunto *  a,conjunto *b){
    conjunto *auxA=a,*auxB=b;
    /*caso algum conjunto for vazio, a diferenca sera o proprio a*/
    if(a==NULL||b==NULL)
        return a;
    /*conjunto q receberar (a-b)*/
    conjunto *resultado=cria();
    /*enquanto n pecorre a lista por completo*/
    while(auxA!=NULL){
        /*caso nenhum elemento de b seja igual ao elemento na posicao referida do conjunto a, o resultado recebe esse valor, auxA caminha uma unidade no conjunto e auxB volta ao inicio do conjunto b*/
        if(auxB==NULL){
            resultado=inserir(resultado,auxA->chave);
            auxA=auxA->prox;
            auxB=b;
        }
        /*caso ainda nao tenha encontrado o valor do referido elemento do conjuto a, no conjunto b, auxB avanca mais uma unidade*/
        else if(auxA->chave!=auxB->chave)
            auxB=auxB->prox;
        /*caso os elementos dos conjuntos nas referidas posicoes forem iguais, auxA avanca mais uma unidade e auxB volta pra o inicio do conjunto*/
        else{
            auxA=auxA->prox;
            auxB=b;
        }

    }
    return resultado;
}
void verifica_igual(conjunto *a,conjunto *b){
    conjunto *auxA=a,*auxB=b,/*auxiliar q ira se refirir ao elemento q deve ser trocado*/*auxBtroca=b;
    /*variavel q guarda o valor de troca*/
    int troca;
    /*enquanto n chegar ao fim dos dois conjuntos*/
    while(auxA!=NULL&&auxB!=NULL){
        /*se o elemento de a for diferente do elemento de b, auxB avanca para o proximo elemento de b*/
        if(auxA->chave!=auxB->chave)
            auxB=auxB->prox;
        /*caso contrario*/
        else{
            /*auxA avanca um elemento*/
            auxA=auxA->prox;
            /*o valor de troca e armazenado*/
            troca=auxBtroca->chave;
            /*elemento na posicao de troca recebe o valor de auxB, pois é o valor do conjunto b procurado q corresponde com o valor do conjunto a, no qual auxA se refere */
            auxBtroca->chave=auxB->chave;
            /*o elemento q n corresponde ao valor procurado, assume uma posicao mais perto do final, no conjunto*/
            auxB->chave=troca;
            /*auxB assume uma posicao a frente do auxiliar de troca*/
            auxB=auxBtroca->prox;
            /*auxiliar de troca avança uma unidade*/
            auxBtroca=auxB;
        }
    }
    /*se pecorrer as 2 listas até o final, e tds os elementos formarem pares, entao as listas sao iguais*/
    if(auxA==NULL && auxB==NULL)
        printf("\nos conjuntos sao iguais");
    else
        printf("\nos conjuntos sao diferentes");
}
conjunto *uniao(conjunto *a,conjunto *b){
    conjunto *auxB=b,*auxA=a,*resultado=cria();
    /*enquanto as 2 listas n chegarem ao fim */
    while(auxA!=NULL||auxB!=NULL){
        /*se a lista nao é vaia o resultado, recebera todos os valores de a*/
        if(auxA!=NULL){
            resultado=inserir(resultado,auxA->chave);
            auxA=auxA->prox;
        }
        /*se a lista nao é vaia o resultado, recebera todos os valores de b*/
        if(auxB!=NULL){
            resultado=inserir(resultado,auxB->chave);
            auxB=auxB->prox;
        }
    }
    return resultado;
}
conjunto *intersecao(conjunto *a,conjunto *b){
    conjunto *auxB=b,*auxA=a,*resultado=cria(),*auxR;
   /* loop que percorre o vetor x */
    while(auxA!=NULL){
        auxR=resultado;
        /* Caso chegue no último ou seja um vetor vázio */
        if(auxB==NULL){
            auxA=auxA->prox;
            auxB=b;
        }
        /* se o valor da chave n corresponde ao valor procurado, auxB, avança um elemento*/
        else if(auxA->chave!=auxB->chave)
            auxB=auxB->prox;
        else{
            /* loop para verificar se o valor encontrado, ja foi adicionado ao conjunto dos resultados*/
            while(auxR!=NULL){
                if(auxA->chave!=auxR->chave)
                    auxR=auxR->prox;
                /*caso o valor tenha sido adicionado o loop par */
                else
                    break;
            }
            /*caso o valor ainda n tenha sido inserido no conjunto resultado, ent é inserido*/
            if(auxR==NULL){
                resultado=inserir(resultado,auxA->chave);
            }
            auxA=auxA->prox;
            auxB=b;
        }
    }
    return resultado;
}

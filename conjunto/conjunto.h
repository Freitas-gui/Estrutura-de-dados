#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
//estrutura para os elementos de um conjunto
typedef struct conjunto{
    int chave;
    struct conjunto *prox;
}conjunto;
//retorna um ponteiro apontando para NULL
conjunto *cria();
//insere elementos no inico do conjunto, e retorna o conjunto atualizado
conjunto *inserir(conjunto *c,int valor);
//exclui o elemento passado por parametro, e retorna a lista atualizada
conjunto *exclui(conjunto *c,int valor);
//imprime todos os elementos do conjunto
void imprime(conjunto *c);
//verifica se é vazio e imprime uma mensagem falando se é vazio ou nao
void verifica_vazio(conjunto *c);
//conta quantos elementos possui um conjunto e retorna esse valor
int cardinalidade(conjunto *c);
//verifica se um determinado valor pertence a um determinado conjunto, e imprime se é um subconjunto ou nao
void pertence(conjunto *c,int valor);
//verifica se o primeiro conjunto é subconjunto do segundo
void verifica_subconjunto(conjunto *a,conjunto *b);
//realiza a operacao (a-b)e retorna um conjunto resultante
conjunto *diferenca(conjunto *  a,conjunto *b);
//verifica se dois conjuntos sao iguais, e imprime a informacao dizendo se sao, ou nao sao
void verifica_igual(conjunto *a,conjunto *b);
//realiza a operacao uniao (a U b)e retorna um conjunto resultante
conjunto *uniao(conjunto *a,conjunto *b);
//retorna um conjunto com a intersecao de 2 conjuntos
conjunto *intersecao(conjunto *a,conjunto *b);
#endif // CONJUNTO_H_INCLUDED

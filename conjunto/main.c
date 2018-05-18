#include "conjunto.h"
int main()
{
    conjunto *idades=cria();
    idades=inserir(idades,18);
    idades=inserir(idades,20);
    idades=inserir(idades,17);
    idades=exclui(idades,20);
    imprime(idades);
    verifica_vazio(idades);
    printf("\nCardinalidade: %d",cardinalidade(idades));
    pertence(idades,11);
    conjunto *a=cria(),*b=cria();
    a=inserir(a,1);
    a=inserir(a,3);
    a=inserir(a,9);
    b=inserir(b,1);
    b=inserir(b,2);
    b=inserir(b,3);
    b=inserir(b,5);
    verifica_subconjunto(a,b);
    imprime(diferenca(a,b));
    conjunto *a2=cria(),*b2=cria();
    a2=inserir(a2,1);
    a2=inserir(a2,4);
    a2=inserir(a2,2);
    a2=inserir(a2,3);
    b2=inserir(b2,4);
    b2=inserir(b2,1);
    b2=inserir(b2,3);
    b2=inserir(b2,2);
    verifica_igual(a2,b2);
    conjunto *a3=cria(),*b3=cria();
    a3=inserir(a3,1);
    a3=inserir(a3,3);
    a3=inserir(a3,4);
    a3=inserir(a3,3);
    b3=inserir(b3,2);
    b3=inserir(b3,3);
    b3=inserir(b3,1);
    imprime(intersecao(a3,b3));
    return 0;
}

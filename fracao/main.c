#include <stdio.h>
#include <stdlib.h>
typedef struct fracao{
    int num;
    int den;
}fracao;
fracao cria(int num,int den){
    fracao f;
    f.num=num;
    f.den=den;
    return f;
}
int acessar_num(fracao f){
    return f.num;
}
int acessar_den(fracao f){
    return f.den;
}
fracao soma(fracao f,fracao f2){
    fracao soma;
    soma.num=(f.num*f2.den)+(f2.num*f.den);
    soma.den=f.den*f2.den;
    return soma;
}
fracao multiplicar(fracao f,fracao f2){
    fracao mult;
    mult.num=f.num*f2.num;
    mult.den=f.den*f2.den;
    return mult;
}
fracao subitrair(fracao f,fracao f2){
    fracao sub;
    sub.num=(f.num*f2.den)-(f2.num*f.den);
    sub.den=f.den*f2.den;
    return sub;
}
fracao dividir(fracao f,fracao f2){
    fracao div;
    div.num=f.num*f2.den;
    div.den=f.den*f2.num;
    return div;
}
int main()
{
    fracao f=cria(2,2);
    fracao f2=cria(1,2);
    fracao s=dividir(f,f2);
    printf("%d/%d",s.num,s.den);
    return 0;
}

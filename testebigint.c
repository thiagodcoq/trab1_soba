/* Sofia Porto 2210536 3WC */
/* Thiago D'Amico 2210799 3WC */

#include <stdio.h>
#include "bigint.h"
#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

/*
Tentar atribuir um valor positivo, um negativo e o zero
*/
int atribuicao(BigInt x){
    return 0;
}

/*
Colocar um valor positivo, um negativo e o zero 
e testar os retornos 
*/
int complemento(BigInt x){
    return 0;
} 

/*
Recebe dois valores, positivo com positivo, negativo com negativo
e positivo com negativo e testa os retornos
*/
int soma(BigInt x, BigInt y){
    return 0;
}

/*
Recebe dois valores, positivo com positivo, negativo com negativo
e positivo com negativo e testa os retornos
*/
int subtracao(BigInt x, BigInt y){
    return 0;
}

/*
Recebe dois valores, positivo com positivo, negativo com negativo
e positivo com negativo e testa os retornos
*/
int multiplicacao(BigInt x, BigInt y){
    return 0;
}

int nums_iguais(BigInt x, BigInt y, int tamanho){
    //Comparar se os numeros (arrays) sao iguais
}

/*
Recebe um numero, o esperado depois do shift, faz o shift
e compara o resultado com o esperado.
Testar com numero positivo, negativo e zero.
E com o maior tamanho posivel dentro do BigInt.
*/
int shift_left(BigInt x, BigInt y){
    /*incial =0001
    esperado=0010
    shift(incial)
    compara(incial,esperado)
    */
    
    return 0;
}

/*
Recebe um numero, o esperado depois do shift, faz o shift
e compara o resultado com o esperado.
Testar com numero positivo, negativo e zero.
E com o maior tamanho posivel dentro do BigInt.
*/
int shift_right(BigInt x, BigInt y){
    /*incial =0001
    esperado=0010
    shift(incial)
    compara(incial,esperado)
    */
    
    return 0;
}

/*
Recebe um numero, o esperado depois do shift, faz o shift
e compara o resultado com o esperado.
Testar com numero positivo, negativo e zero.
E com o maior tamanho posivel dentro do BigInt.
*/
int shift_aritmetico(BigInt x, BigInt y){
    return 0;
}

int main(void){

    return 0;
}
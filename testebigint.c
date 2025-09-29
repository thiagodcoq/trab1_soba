/* Sofia Porto 2210536 3WC */
/* Thiago D'Amico 2210799 3WC */

#include <stdio.h>
#include "bigint.h"

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

void dump(BigInt x) {
    for (int i = NUM_BITS/8 - 1; i >= 0; i--) {
        printf("%02X", x[i]);
    }
    printf("\n");
}

int compara_bigInts(BigInt x, BigInt y){
    //Comparar se os numeros (arrays) sao iguais
    for (int i = 0; i < NUM_BITS/8; i++) {
        if (x[i] != y[i]) {
            return 0;
        }
    }
    return 1;
}

void cria_esperado(BigInt res, unsigned char bytes[16]) {
    for (int i = 0; i < 16; i++) {
        res[i] = bytes[i];
    }
}

/*
Tentar atribuir um valor positivo, um negativo e o zero
*/
int test_atribuicao(long val, BigInt esperado) {
    BigInt x;
    big_val(x, val);

    return compara_bigInts(x, esperado);
}

/*
Colocar um valor positivo, um negativo e o zero 
e testar os retornos 
*/
int test_complemento(long val, unsigned char esperado[16]) {
    BigInt x, res;
    big_val(x, val);          // transforma val em BigInt
    big_comp2(res, x);        // calcula complemento a 2
    return compara_bigInts(res, esperado);
}

/*
Recebe dois valores, positivo com positivo, negativo com negativo
e positivo com negativo e testa os retornos
*/
int test_soma(long a, long b, unsigned char esperado[16]) {
    BigInt x, y, res;
    big_val(x, a);
    big_val(y, b);
    big_sum(res, x, y);
    return compara_bigInts(res, esperado);
}

/*
Recebe dois valores, positivo com positivo, negativo com negativo
e positivo com negativo e testa os retornos
*/
int test_sub(long a, long b, unsigned char esperado[16]) {
    BigInt x, y, res;
    big_val(x, a);
    big_val(y, b);
    big_sub(res, x, y);
    return compara_bigInts(res, esperado);
}

/*
Recebe dois valores, positivo com positivo, negativo com negativo
e positivo com negativo e testa os retornos
*/
int test_mul(long a, long b, unsigned char esperado[16]) {
    BigInt x, y, res;
    big_val(x, a);
    big_val(y, b);
    big_mul(res, x, y);
    return compara_bigInts(res, esperado);
}

/*
Recebe um numero, o esperado depois do shift, faz o shift
e compara o resultado com o esperado.
Testar com numero positivo, negativo e zero.
E com o maior tamanho posivel dentro do BigInt.
*/
int test_shl(long a, int n, unsigned char esperado[16]) {
    BigInt x, res;
    big_val(x, a);
    big_shl(res, x, n);
    return compara_bigInts(res, esperado);
}

/*
Recebe um numero, o esperado depois do shift, faz o shift
e compara o resultado com o esperado.
Testar com numero positivo, negativo e zero.
E com o maior tamanho posivel dentro do BigInt.
*/
int test_shr(long a, int n, unsigned char esperado[16]) {
    BigInt x, res;
    big_val(x, a);
    big_shr(res, x, n);
    return compara_bigInts(res, esperado);
}

/*
Recebe um numero, o esperado depois do shift, faz o shift
e compara o resultado com o esperado.
Testar com numero positivo, negativo e zero.
E com o maior tamanho posivel dentro do BigInt.
*/
int test_sar(long a, int n, unsigned char esperado[16]) {
    BigInt x, res;
    big_val(x, a);
    big_sar(res, x, n);
    return compara_bigInts(res, esperado);
}

int main(void) {
    /* Teste atribuicao: 1 */
    unsigned char um[16] = {0x01};
    printf("Atribuicao(1): %s\n", test_atribuicao(1, um) ? "OK" : "FALHA");

    /* Teste complemento: -5 -> complemento de 5 */
    unsigned char menos5[16] = {0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    printf("Complemento(5) = -5: %s\n", test_complemento(5, menos5) ? "OK" : "FALHA");

    /* Teste soma: 2 + 3 = 5 */
    unsigned char cinco[16] = {0x05};
    printf("Soma(2,3)=5: %s\n", test_soma(2, 3, cinco) ? "OK" : "FALHA");

    /* Teste subtracao: 7 - 10 = -3 */
    unsigned char menos3[16] = {0xFD,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    printf("Sub(7,10)=-3: %s\n", test_sub(7, 10, menos3) ? "OK" : "FALHA");

    /* Teste multiplicacao: 4 * -2 = -8 */
    unsigned char menos8[16] = {0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    printf("Mul(4,-2)=-8: %s\n", test_mul(4, -2, menos8) ? "OK" : "FALHA");

    /* Teste shift left: 1 << 1 = 2 */
    unsigned char dois[16] = {0x02};
    printf("Shl(1,1)=2: %s\n", test_shl(1, 1, dois) ? "OK" : "FALHA");

    /* Teste shift right logico: 4 >> 1 = 2 */
    printf("Shr(4,1)=2: %s\n", test_shr(4, 1, dois) ? "OK" : "FALHA");

    /* Teste shift right aritmetico: -4 >> 1 = -2 */
    unsigned char menos2[16] = {0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    printf("Sar(-4,1)=-2: %s\n", test_sar(-4, 1, menos2) ? "OK" : "FALHA");

    return 0;
}

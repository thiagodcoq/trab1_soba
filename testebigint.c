/* Sofia Porto 2210536 3WC */
/* Thiago D'Amico 2210799 3WC */

#include <stdio.h>
#include "bigint.h"



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
static void dump_hex(const unsigned char *p) {
    for (int i = 15; i >= 0; i--) printf("%02X", p[i]);
}

int test_atribuicao(long val, const unsigned char esperado[16]) {
    BigInt x;
    big_val(x, val);
    //dump_hex(x);

    for (int i = 0; i < 16; i++) {
        if (x[i] != esperado[i]) {
            printf("FALHA atribuicao(val=%ld): byte[%d] esperado=%02X obtido=%02X\n",
                   val, i, esperado[i], x[i]);
            printf("  esperado: "); dump_hex(esperado); printf("\n");
            printf("  obtido  : "); dump_hex(x);        printf("\n");
            return 0;
        }
    }
    return 1;
}

/*
Colocar um valor positivo, um negativo e o zero 
e testar os retornos 
*/
int test_complemento(long val, unsigned char esperado[16]) {
    BigInt x, res;
    big_val(x, val);
    dump_hex(x);          // transforma val em BigInt
    big_comp2(res, x);
    dump_hex(res);        // calcula complemento a 2
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
    unsigned char um[16] = {0x01};                 // 1
    unsigned char zero[16] = {0x00};               // 0
    unsigned char menos2[16] = {0xFE};             // -2
    for (int i = 1; i < 16; i++) menos2[i] = 0xFF;

    printf("Atribuicao(1): %s\n",   test_atribuicao(1,   um)     ? "OK" : "FALHA");
    printf("Atribuicao(0): %s\n",   test_atribuicao(0,   zero)   ? "OK" : "FALHA");
    printf("Atribuicao(-2): %s\n",  test_atribuicao(-2,  menos2) ? "OK" : "FALHA");
    /* Teste complemento: -5 -> complemento de 5 */
    unsigned char menos5[16] = {0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    printf("Complemento(5) = -5: %s\n", test_complemento(5, menos5) ? "OK" : "FALHA");
    return 0;
}


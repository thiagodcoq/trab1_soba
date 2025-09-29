/* Sofia Porto 2210536 3WC */
/* Thiago D'Amico 2210799 3WC */

#include "bigint.h"
#include <stdio.h>
#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

void big_val(BigInt res, long val) {
    unsigned long u = (unsigned long) val;  // leitura sem sinal
    int L = (int)sizeof(long);

    // copia os bytes que cabem no long
    for (int i = 0; i < L && i < 16; i++) {
        res[i] = (unsigned char)(u & 0xFF);
        u >>= 8;
    }

    // completa os bytes restantes com extensão de sinal
    unsigned char fill = (val < 0) ? 0xFF : 0x00; // Se val for negativo, preenche com 1, se nao, preenche com 0
    for (int i = L; i < 16; i++) {
        res[i] = fill;
    }
}
void big_comp2(BigInt res, BigInt a) {
    unsigned short carry = 1; // começa com 1 (o +1 do complemento de dois)

    printf("== DEBUG big_comp2 ==\n");

    for (int i = 0; i < 16; i++) {
        unsigned int temp = (unsigned short)(~a[i]) + carry;
        res[i] = (unsigned char)(temp & 0xFF);
        carry = (temp >> 8) & 1;

        printf("Byte[%2d]: a=%02X ~a=%02X temp=%03X res=%02X carry=%d\n",
               i, a[i], (unsigned char)~a[i], temp, res[i], carry);
    }

    printf("Resultado final: ");
    for (int i = 15; i >= 0; i--) {
        printf("%02X", res[i]);
    }
    printf("\n\n");
}
void big_sum(BigInt res, BigInt a, BigInt b) { return; }
void big_sub(BigInt res, BigInt a, BigInt b) { return; }
void big_mul(BigInt res, BigInt a, BigInt b) { return; }
void big_shl(BigInt res, BigInt a, int n) { return; }
void big_shr(BigInt res, BigInt a, int n) { return; }
void big_sar(BigInt res, BigInt a, int n) { return; }

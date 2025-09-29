// testebigint.c
#include <stdio.h>
#include "bigint.h"

static void dump_hex(const unsigned char *p) {
    for (int i = 15; i >= 0; i--) printf("%02X", p[i]);
}

int test_atribuicao(long val, const unsigned char esperado[16]) {
    BigInt x;
    big_val(x, val);

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

int main(void) {
    unsigned char um[16] = {0x01};                 // 1
    unsigned char zero[16] = {0x00};               // 0
    unsigned char menos2[16] = {0xFE};             // -2
    for (int i = 1; i < 16; i++) menos2[i] = 0xFF;

    printf("Atribuicao(1): %s\n",   test_atribuicao(1,   um)     ? "OK" : "FALHA");
    printf("Atribuicao(0): %s\n",   test_atribuicao(0,   zero)   ? "OK" : "FALHA");
    printf("Atribuicao(-2): %s\n",  test_atribuicao(-2,  menos2) ? "OK" : "FALHA");
    return 0;
}

void big_val(BigInt res, long val) {
    unsigned long u = (unsigned long) val;  // leitura sem sinal
    int L = (int)sizeof(long);

    // copia os bytes que cabem no long
    for (int i = 0; i < L && i < 16; i++) {
        res[i] = (unsigned char)(u & 0xFF);
        u >>= 8;
    }

    // completa os bytes restantes com extensão de sinal
    unsigned char fill = (val < 0) ? 0xFF : 0x00;
    for (int i = L; i < 16; i++) {
        res[i] = fill;
    }
}

void big_comp2(BigInt res, BigInt a) {
    unsigned short carry = 1; // começa com 1 (o +1 do complemento de dois)

    printf("== DEBUG big_comp2 ==\n");

    for (int i = 0; i < 16; i++) {
        unsigned short temp = (unsigned short)(~a[i]) + carry;
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

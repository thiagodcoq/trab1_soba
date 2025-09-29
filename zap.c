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
    unsigned long u = (unsigned long) val;  // para extrair bytes sem sinal
    int L = (int)sizeof(long);
    if (L > 16) L = 16; // por segurança, embora não deva acontecer

    // bytes menos significativos (little-endian)
    for (int i = 0; i < L; i++) {
        res[i] = (unsigned char)(u & 0xFFu);
        u >>= 8;
    }

    // extensão de sinal manual para completar 128 bits
    unsigned char fill = (val < 0) ? 0xFF : 0x00;
    for (int i = L; i < 16; i++) {
        res[i] = fill;
    }
}

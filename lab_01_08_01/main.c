#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1

unsigned int pack(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
    unsigned int u = b1;
    u <<= 8;
    u |= b2;
    u <<= 8;
    u |= b3;
    u <<= 8;
    u |= b4;
    return u;
}

int main(void)
{
    unsigned char byte1, byte2, byte3, byte4;

    printf("Введите значения 4х байт (в 10-ой):\n");
    if (scanf("%hhu%hhu%hhu%hhu", &byte1, &byte2, &byte3, &byte4) != 4)
    {
        return ERR_IO;
    }

    printf("%u\n", pack(byte1, byte2, byte3, byte4));

    return OK;
}
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

void bin_print(uint32_t u)
{
	size_t nbits = sizeof(u) * CHAR_BIT;
	uint32_t mask = 1 << (nbits - 1);
	
	for (size_t i = 0; i < nbits; i++)
	{
		if (u & mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
	}
	printf("\n");
}

uint32_t pack(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4)
{
	uint32_t u = b1;
	u <<= 8;
	u |= b2;
	u <<= 8;
	u |= b3;
	u <<= 8;
	u |= b4;
	return u;
}

void unpack_print(uint32_t u)
{
	int bytes = 4;
	for (int i = 0; i < bytes; i++)
	{
		uint32_t tmp = u;
		tmp <<= i * 8;
		tmp >>= 24;
		printf("%" PRIu8 " ", tmp);
	}
	printf("\n");
}

int main(void)
{
	uint8_t byte1, byte2, byte3, byte4;

	printf("Введите значения четырех байт (в 10-ой):\n");
	if (scanf("%u%u%u%u", &byte1, &byte2, &byte3, &byte4) != 4)
	{
		printf("IO error!");
		return ERR_IO;
	}

	uint32_t packed_int = pack(byte1, byte2, byte3, byte4);
	bin_print(packed_int);
	unpack_print(packed_int);

	return OK;
}

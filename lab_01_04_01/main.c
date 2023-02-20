#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_ZERO 2

int main(void)
{
    int flat_num;
    
    printf("Введите номер квартиры:\n");
    if (scanf("%d", &flat_num) != 1)
    {
        printf("IO error!");
        return ERR_IO;
    }
    else if (flat_num <= 0)
    {
        printf("Нумерация квартиры начинается с 1!\n");
        return ERR_ZERO;
    }

    int entrance = ((flat_num - 1) / (9 * 4)) + 1;
    int floor = ((flat_num - (entrance - 1) * 36 - 1) / 4) + 1;

    printf("Номер подъезда = %d\nЭтаж = %d\n", entrance, floor);

    return OK;
}
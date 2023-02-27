#include <stdio.h>
#include <math.h>

#define OK 0
#define floors 9
#define flats_per_floor 4

int main(void)
{
    int flat_num;
    
    printf("Введите номер квартиры:\n");
    scanf("%d", &flat_num);

    int entrance = ((flat_num - 1) / (floors * flats_per_floor)) + 1;
    int floor = ((flat_num - (entrance - 1) * (floors * flats_per_floor) - 1) / flats_per_floor) + 1;

    printf("Номер подъезда = %d \nЭтаж = %d \n", entrance, floor);

    return OK;
}
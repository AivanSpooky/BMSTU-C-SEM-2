#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_NEG 2

int main(void)
{
    int n;
    
    printf("Введите натуральное число n:\n");
    if (scanf("%d", &n) != 1)
    {
        printf("IO error!");
        return ERR_IO;
    }
    else if (n <= 0)
    {
        printf("Число N должно быть натуральным!\n");
        return ERR_NEG;
    }

    printf("Число N: ");
    int power_of_ten = 1;
    while (n / power_of_ten != 0)
    {
        power_of_ten *= 10;
    }

    while (power_of_ten != 1)
    {
        power_of_ten /= 10;
        printf("%d ", (n / power_of_ten) % power_of_ten);
    }
    printf("\n");

    return OK;
}

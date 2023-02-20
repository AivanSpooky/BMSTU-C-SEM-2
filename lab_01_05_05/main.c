#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_NEG 2

int degree_of_10(int degree)
{
    int result = 1;
    for (int i=0; i<degree; i++)
    {
        result *= 10;
    }
    return result;
}

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
    int i = 0;
    int power_of_ten = 1;
    while (n / power_of_ten != 0)
    {
        i++;
        power_of_ten = degree_of_10(i);
    }

    while (power_of_ten != 1)
    {
        i--;
        power_of_ten = degree_of_10(i);
        printf("%d", (n/power_of_ten)%10);
    }
    printf("\n");

    return OK;
}
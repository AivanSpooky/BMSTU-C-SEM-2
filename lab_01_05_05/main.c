#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_NEG 2

void print_number(int n)
{
    printf("Число N: ");
    int power_of_ten = 1;
    while (n / power_of_ten != 0)
    {
        power_of_ten *= 10;
	}
	
    while (power_of_ten != 1)
    {
        power_of_ten /= 10;
        //printf("|%d %d|\n", n, power_of_ten);
        printf("%d ", (n / power_of_ten) % 10);
        
    }
    printf("\n");
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

    print_number(n);

    return OK;
}
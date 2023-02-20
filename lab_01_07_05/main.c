#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_WRONG_INPUT 2

int func_f(int x)
{
    return 1/(sqrt(1-(x*x)));
}

int main(void)
{
    double x, eps;
    
    printf("Введите x и eps:\n");
    if (scanf("%lf%lf", &x, &eps) != 2)
    {
        printf("Неверный ввод!");
        return ERR_IO;
    }
    else if (eps <= 0 || eps >= 1 || x >= 1 || x <= -1)
    {
        printf("Ввод неверный!");
        return ERR_WRONG_INPUT;
    }

    

}
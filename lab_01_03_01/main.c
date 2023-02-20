#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_NEG 2

int main(void)
{
    double v1, t1;
    double v2, t2;
    
    printf("Введите V1, T1, V2, T2:\n");

    if (scanf("%lf%lf%lf%lf", &v1, &t1, &v2, &t2) != 4)
    {
        printf("IO error!");
        return ERR_IO;
    }
    else if (v1 < 0 || v2 < 0)
    {
        printf("Объем не может быть отрицательным!\n");
        return ERR_NEG;
    }

    double v = v1 + v2;
    double t = (v1 * t1 + v2 * t2) / (v1 + v2);

    printf("Общий объем V = %f\nТемпература T = %f\n", v, t);

    return OK;
}
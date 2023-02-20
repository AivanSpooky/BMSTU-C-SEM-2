#include <stdio.h>
#include <math.h>

#define M_PI   3.14159265358979323846264338327950288
#define OK 0
#define ERR_IO 1
#define ERR_NEG 2
#define ERR_BASE 2
#define ERR_ANGLE 3

int main(void)
{
    double a, b;
    double phi;
    
    printf("Введите основания равн/бедр. трапеции и угол (в градусах) при большем из них (a, b, phi):\n");

    if (scanf("%lf%lf%lf", &a, &b, &phi) != 3)
    {
        printf("IO error!");
        return ERR_IO;
    }
    else if (a <= 0 || b <= 0)
    {
        printf("Основание трапеции не может быть нулевым или отрицательным!\n");
        return ERR_NEG;
    }
    else if (a == b)
    {
        printf("Основания трапеции не могут быть одинаковыми!\n");
        return ERR_BASE;
    }
    else if (phi <= 0 || phi >= 90)
    {
        printf("Угол должен быть острым!\n");
        return ERR_ANGLE;
    }

    double s = fabs(a * a - b * b) / 2 * tanf((phi * M_PI / 180));

    printf("S = %f\n", s);

    return OK;
}
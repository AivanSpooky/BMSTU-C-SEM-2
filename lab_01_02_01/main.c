#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    double m_pi = 3.141592;
    double a, b;
    double phi;
    
    printf("Введите основания равн/бедр. трапеции и угол (в градусах) при большем из них (a, b, phi):\n");

    scanf("%lf%lf%lf", &a, &b, &phi);

    double s = fabs(a * a - b * b) / 2 * tan((phi * m_pi / 180));

    printf("S = %.6f\n", s);

    return OK;
}

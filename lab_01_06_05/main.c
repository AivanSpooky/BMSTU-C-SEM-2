#include <stdio.h>
#include <math.h>

#define EPS 0.0000000000000000001
#define OK 0
#define ERR_INCORRECT_INPUT 1
#define ERR_SAME_DOTS 2

int intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double ABx, ABy, ACx, ACy, ADx, ADy;
    double CAx, CAy, CBx, CBy, CDx, CDy;
    double ACxAB, ADxAB, CAxCD, CBxCD;
    ACx = x3 - x1;
    ACy = y3 - y1;
    ABx = x2 - x1;
    ABy = y2 - y1;
    ADx = x4 - x1;
    ADy = y4 - y1;
    CAx = x1 - x3;
    CAy = y1 - y3;
    CBx = x2 - x3;
    CBy = y2 - y3;
    CDx = x4 - x3;
    CDy = y4 - y3;
    ACxAB = ACx * ABy - ACy * ABx;
    ADxAB = ADx * ABy - ADy * ABx;
    CAxCD = CAx * CDy - CAy * CDx;
    CBxCD = CBx * CDy - CBy * CDx;
    if ((ACxAB * ADxAB < 0) && (CAxCD * CBxCD < 0))
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    double x_p, y_p;
    double x_q, y_q;
    double x_r, y_r;
    double x_s, y_s;
    if (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x_p, &y_p, &x_q, &y_q, &x_r, &y_r, &x_s, &y_s) != 8)
    {
        printf("Неверный ввод!");
        return ERR_INCORRECT_INPUT;
    }
    else if (((fabs(x_p - x_q) < EPS) && (fabs(y_p - y_q) < EPS)) || ((fabs(x_r - x_s) < EPS) && (fabs(y_r - y_s) < EPS)))
    {
        printf("У одного из отрезков концы имеют одинаковые координаты!\n");
        return ERR_SAME_DOTS;
    }

    printf("%d", intersect(x_p, y_p, x_q, y_q, x_r, y_r, x_s, y_s));
    return OK;
}
#include <stdio.h>
#include <math.h>

#define EPS 0.0000000000000000001
#define OK 0
#define ERR_INCORRECT_INPUT 1
#define ERR_SAME_DOTS 2

double find_line_coefficients_k(double x1, double y1, double x2, double y2)
{
    return (y2 - y1) / (x2 - x1);
}

double find_line_coefficients_b(double x1, double y1, double x2, double y2)
{
    return y1 - (y2 - y1) / (x2 - x1) * x1;
}

// Функция возвращает знак
double sg(double n)
{
    return (n > 0) - (n < 0);
}

int RectIntersects(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    if ((sg(x3 - x2) * sg(x4 - x1) < 0) || (sg(y3 - y2) * sg(y4 - y1) < 0))
    {
        return 0;
    }
    return 1;
}

int intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double ABx, ABy, ACx, ACy, ADx, ADy;
    double CAx, CAy, CBx, CBy, CDx, CDy;
    double ACxAB, ADxAB, CAxCD, CBxCD;
    if (!RectIntersects(fmin(x1, x2), fmin(y1, y2), fmax(x1, x2), fmax(y1, y2), fmin(x3, x4), fmin(y3, y4), fmax(x3, x4), fmax(y3, y4)))
    {
        return 0;
    }
    ACx = x3 - x1; ACy = y3 - y1;
    ABx = x2 - x1; ABy = y2 - y1;
    ADx = x4 - x1; ADy = y4 - y1;
    CAx = x1 - x3; CAy = y1 - y3;
    CBx = x2 - x3; CBy = y2 - y3;
    CDx = x4 - x3; CDy = y4 - y3;
    ACxAB = ACx * ABy - ACy * ABx;
    ADxAB = ADx * ABy - ADy * ABx;
    CAxCD = CAx * CDy - CAy * CDx;
    CBxCD = CBx * CDy - CBy * CDx;
    if ((sg(ACxAB) * sg(ADxAB) > 0) || (sg(CAxCD) * sg(CBxCD) > 0))
    {
        return 0;
    }
    return 1;
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

    double tmp;

    if (x_p > x_q)
    {
        tmp = x_q;
        x_q = x_p;
        x_p = tmp;

        tmp = y_q;
        y_q = y_p;
        y_p = tmp;
    }
    if (x_r > x_s)
    {
        tmp = x_s;
        x_s = x_r;
        x_r = tmp;

        tmp = y_s;
        y_s = y_r;
        y_r = tmp;
    }
    if ((fabs(x_p - x_q) < EPS) && (fabs(x_r - x_s) < EPS))
    {
        if ((fabs(x_p - x_r) < EPS) && ((y_p <= y_s && y_p >= y_r) || (y_q <= y_s && y_q >= y_r) || (y_r <= y_q && y_r >= y_p) || (y_s <= y_q && y_s >= y_p)))
        {
            printf("1\n");
            return OK;
        }
        else
        {
            printf("0\n");
            return OK;
        }
    }
    double k1 = find_line_coefficients_k(x_p, y_p, x_q, y_q);
    double b1 = find_line_coefficients_b(x_p, y_p, x_q, y_q);
    double k2 = find_line_coefficients_k(x_r, y_r, x_s, y_s);
    double b2 = find_line_coefficients_b(x_r, y_r, x_s, y_s);
    if (fabs(k1 - k2) < EPS)
    {
        if ((fabs(b1 - b2) < EPS) && ((x_p <= x_r && x_p <= x_s && x_q >= x_r && x_q >= x_s) || ((x_p <= x_s && x_p >= x_r) || (x_q >= x_r && x_q <= x_s))))
        {
            printf("1\n");
            return OK;
        }
        else
        {
            printf("0\n");
            return OK;
        }
    }

    if (intersect(x_p, y_p, x_q, y_q, x_r, y_r, x_s, y_s))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return OK;
}
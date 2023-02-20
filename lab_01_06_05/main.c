#include <stdio.h>
#include <math.h>

#define EPS 1e-3
#define OK 0
#define ERR_INCORRECT_INPUT 1
#define ERR_SAME_DOTS 2

double find_line_coefficients(double x1, double y1, double x2, double y2)
{
    return (y2 - y1) / (x2 - x1), y1 - (y2 - y1) / (x2 - x1) * x1;
}

int main(void)
{
    double x_p, y_p;
    double x_q, y_q;
    double x_r, y_r;
    double x_s, y_s;
    
    printf("Введите x_p, y_p, x_q, y_q, x_r, y_r, x_s, y_s:\n");
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

    if (x_p > x_q)
    {
        x_p, x_q = x_q, x_p;
        y_p, y_q = y_q, y_p;
        printf("%f  %f", x_p, x_q);
    }
    if (x_r > x_s)
    {
        x_r, x_s = x_s, x_r;
        y_r, y_s = y_s, y_r;
    }
    if ((fabs(x_p - x_q) < EPS) && (fabs(x_r - x_s) < EPS))
    {
        if (fabs(x_p - x_r) < EPS)
        {
            printf("0\n");
            return OK;
        }
        else
        {
            printf("1\n");
            return OK;
        }
    }
    else if (fabs(x_p - x_q) < EPS)
    {
        if (x_p >= x_r && x_p <= x_s)
        {
            printf("0\n");
            return OK;
        }
        else
        {
            printf("1\n");
            return OK;
        }
    }
    else if (fabs(x_r - x_s) < EPS)
    {
        if (x_r >= x_p && x_r <= x_q)
        {
            printf("0\n");
            return OK;
        }
        else
        {
            printf("1\n");
            return OK;
        }
    }
    double k1, b1 = find_line_coefficients(x_p, y_p, x_q, y_q);
    double k2, b2 = find_line_coefficients(x_r, y_r, x_s, y_s);
    if (fabs(k1 - k2) < EPS)
    {
        if (fabs(b1 - b2) < EPS)
        {
            printf("0\n");
            return OK;
        }
        else
        {
            printf("1\n");
            return OK;
        }
    }
    double x_cross = (b2 - b1) / (k1 - k2);
    if ((x_cross < x_p && x_cross < x_r) || (x_cross > x_q && x_cross > x_s))
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
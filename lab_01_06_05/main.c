#include <stdio.h>
#include <math.h>

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


int main(void)
{
    double eps = 0.0000001;
    double x_p, y_p;
    double x_q, y_q;
    double x_r, y_r;
    double x_s, y_s;
    
    if (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x_p, &y_p, &x_q, &y_q, &x_r, &y_r, &x_s, &y_s) != 8)
    {
        printf("Неверный ввод!");
        return ERR_INCORRECT_INPUT;
    }
    else if (((fabs(x_p - x_q) < eps) && (fabs(y_p - y_q) < eps)) || ((fabs(x_r - x_s) < eps) && (fabs(y_r - y_s) < eps)))
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
        printf("%f  %f", x_p, x_q);
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
    if ((fabs(x_p - x_q) < eps) && (fabs(x_r - x_s) < eps))
    {
        if (fabs(x_p - x_r) < eps)
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
    else if (fabs(x_p - x_q) < eps)
    {
        x_q += eps;
    }
    else if (fabs(x_r - x_s) < eps)
    {
        x_s += eps;
    }
    double k1 = find_line_coefficients_k(x_p, y_p, x_q, y_q);
    double b1 = find_line_coefficients_b(x_p, y_p, x_q, y_q);
    double k2 = find_line_coefficients_k(x_r, y_r, x_s, y_s);
    double b2 = find_line_coefficients_b(x_r, y_r, x_s, y_s);
    if (fabs(k1 - k2) < eps)
    {
        if (fabs(b1 - b2) < eps)
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
    if ((x_cross <= x_q && x_cross >= x_p) && (x_cross <= x_s && x_cross >= x_r))
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
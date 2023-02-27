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

int intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double ab_x, ab_y, ac_x, ac_y, ad_x, ad_y;
    double ca_x, ca_y, cb_x, cb_y, cd_x, cd_y;
    double ac_x_ab, ad_x_ab, ca_x_cd, cb_x_cd;
    ac_x = x3 - x1;
    ac_y = y3 - y1;
    ab_x = x2 - x1;
    ab_y = y2 - y1;
    ad_x = x4 - x1;
    ad_y = y4 - y1;
    ca_x = x1 - x3;
    ca_y = y1 - y3;
    cb_x = x2 - x3;
    cb_y = y2 - y3;
    cd_x = x4 - x3;
    cd_y = y4 - y3;
    ac_x_ab = ac_x * ab_y - ac_y * ab_x;
    ad_x_ab = ad_x * ab_y - ad_y * ab_x;
    ca_x_cd = ca_x * cd_y - ca_y * cd_x;
    cb_x_cd = cb_x * cd_y - cb_y * cd_x;
    if ((ac_x_ab * ad_x_ab < 0) && (ca_x_cd * cb_x_cd < 0))
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

    printf("%d", intersect(x_p, y_p, x_q, y_q, x_r, y_r, x_s, y_s));
    return OK;
}
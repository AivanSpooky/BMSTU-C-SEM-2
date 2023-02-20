#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1

int main(void)
{
    double cur_x = 0;
    int n = 1;
    double sum = 0;
    
    while (1 == 1)
    {
        if (scanf("%lf", &cur_x) != 1)
        {
            return ERR_IO;
        }
        else if (cur_x < 0)
        {
            break;
        }
        else
        {
            sum += sqrtf(cur_x / n);
            n++;
        }
    }

    printf("%f", sinf(sum));

    return OK;

}
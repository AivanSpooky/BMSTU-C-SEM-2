#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_WRONG_INPUT 2

int main(void)
{
    double cur_x = 0;
    int n = 1;
    double sum = 0;
    int elem_count = 0;
    
    while (n > 0)
    {
        if (scanf("%lf", &cur_x) != 1)
        {
            return ERR_IO;
        }
        else if (cur_x < 0)
        {
            if (n == 1)
            {
                return ERR_WRONG_INPUT;
            }
            break;
        }
        else
        {
            sum += sqrtf(cur_x / n);
            n++;
        }
    }

    printf("%f\n", sinf(sum));

    return OK;
}
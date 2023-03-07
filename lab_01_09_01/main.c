#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_WRONG_INPUT 2

int function(double *sum)
{
	double cur_x = 0;
	int n = 1;
	printf("Введите положительный икс (отрицательный - конец ввода): \n");
	if (scanf("%lf", &cur_x) != 1)
	{
		printf("IO error! \n");
		return ERR_IO;
	}
	if (cur_x < 0)
	{
		printf("Wrong input error! \n");
		return ERR_WRONG_INPUT;
	}
	else
	{
		*sum += sqrt(cur_x / n);
		n++;
	}
	printf("Введите положительный икс (отрицательный - конец ввода): \n");
	while (scanf("%lf", &cur_x))
	{
		printf("Введите положительный икс (отрицательный - конец ввода): \n");
		if (cur_x < 0)
		{
			break;
		}
		else
		{
			*sum += sqrt(cur_x / n);
			n++;
		}
	}
	*sum = sin(*sum);
	return OK;
}

int main(void)
{
	double sum = 0;

	int err_code = function(&sum);
	if (err_code == 0)
	{
		printf("%f\n", sum);
	}

	return err_code;
}

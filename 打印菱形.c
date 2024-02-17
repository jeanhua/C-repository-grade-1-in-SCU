#include<stdio.h>
int main()
{
	double a,b;
	scanf_s("%lf", &b);
	a = (b + 1) / 2;
	if (a>(int)a)
	{
		printf("error");
		return 0;
	}
	else
	{
		printf("print\n");
	}
	for (int i = 1; i <= a; i++)
	{
		for (int kongge = 0; kongge < a - i; kongge++)
		{
			printf(" ");
		}
		for (int o = 1; o <= 2*i-1; o++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = a-1; i >0; i--)
	{
		for (int kongge = a - i; kongge >0; kongge--)
		{
			printf(" ");
		}
		for (int o = 1; o <= 2*i-1; o++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
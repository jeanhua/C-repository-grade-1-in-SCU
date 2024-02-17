#include<stdio.h>
#include<math.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a=0, b=1;
	int ina, inb,error=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d/%d", &ina, &inb);
		if (inb == 0)
		{
			error = 1;
		}
		a = a * inb + b * ina;
		b = b * inb;
		for (int j = 2; j <= (a > b ? a : b); j++)
		{
			if (a % j == 0 && b % j == 0)
			{
				a /= j; b /= j;
				j = 1;
			}
		}
	}
	if (error==1)
	{
		printf("error\n");
		return 0;
	}
	if (a!=0)
	{
		if (b != 1)
		{
			if (a >= b && a % b == 0)
			{
				printf("%d", a / b);
			}
			else
			printf("%d/%d", a, b);
		}
		else
		{
			printf("%d", a);
		}
	}
	else
	{
		printf("0\n");
	}
}
#include<stdio.h>
int main()
{
	double ice_eat, stick_left, n;
	scanf_s("%lf", &n);
	for (int i = (int)n / 2; i <= 100000000; i++)
	{
		if (n / 3 <= 1)
		{
			printf("%d",(int)n);
			return 0;
		}
		ice_eat = i;
		stick_left = i;
		while (stick_left / 3 >= 1)
		{
			ice_eat += (int)(stick_left / 3);
			stick_left = (int)(stick_left / 3) + (int)stick_left % 3;
			if (ice_eat == n)
			{
				printf("%d\n", i);
				return 0;
			}
		}
	}
	return 0;
}
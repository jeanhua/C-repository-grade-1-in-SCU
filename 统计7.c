#include<stdio.h>
int main()
{
	int min, max,n=0,tem;
	scanf_s("%d%d", &min, &max);
	for (int i = min; i <= max; i++)
	{
		tem = i;
		while (tem != 0)
		{
			if (tem % 10 == 7)
			{
				n++;
			}
			tem /= 10;
		}
	}
	printf("%d\n", n);
	return 0;
}
#include<stdio.h>
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int q = 1; q <= i; q++)
		{
			printf("%d*%d=%d ", i, q, i * q);
		}
		printf("\n");
	}
	return 0;
}
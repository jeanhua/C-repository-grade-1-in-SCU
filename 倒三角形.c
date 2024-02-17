#include<stdio.h>
int main()
{
	int n1 = 0;
	scanf("%d", &n1);
	for (int m = 1; m <= n1; m++)
	{
		int n = 0;
		scanf("%d", &n);
		for (int j = n; j >= 1; j--)
		{
			int q = n - j;
			while (q > 0)
			{
				printf(" ");
				q--;
			}
			for (int i = 1; i <= 2 * j - 1; i++)
			{
				printf("*");
			}
			q = n - j;
			while (q > 0)
			{
				printf(" ");
				q--;
			}
			printf("\n");
		}
	}
}
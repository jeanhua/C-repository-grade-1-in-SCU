#include<stdio.h>
int main()
{
	int n,sum=0;
	int out = 1;
	int line = 0;
	scanf_s("%d", &n);
	while (sum < n * n)
	{
		int num;
		scanf_s("%d", &num);
		out = out == 0 ? 1 : 0;
		if (num != 0)
		{
			for (int s = 1; s <= num; s++)
			{
				printf("%d", out);
				if ((sum + s) % n == 0 && line != n - 1)
				{
					printf("\n");
					line++;
				}
			}
			sum += num;
		}
	}
	return 0;
}
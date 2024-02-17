#include<stdio.h>
int main()
{
	int out[20][20] = { 0 };
	int n;
	scanf("%d", &n);
	int hang = 1, lie = 1, num = 1;
	for (int circle = 0; circle <= n / 2; circle++)
	{
		for (int i = 1+circle; i <= n-circle; i++)
		{
			out[1+circle][i] = num;
			num++;
		}
		for (int i = 2+circle; i <= n-circle; i++)
		{
			out[i][n-circle] = num;
			num++;
		}
		for (int i = n - 1-circle; i >= 1+circle; i--)
		{
			out[n-circle][i] = num;
			num++;
		}
		for (int i = n - 1-circle; i > 1+circle; i--)
		{
			out[i][1+circle] = num;
			num++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%-5.d", out[i][j]);
		}
		printf("\n");
	}
}
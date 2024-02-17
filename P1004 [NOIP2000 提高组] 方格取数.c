#include<stdio.h>
int max(int a, int b, int c, int d)
{
	int x = a > b ? a : b;
	int y = c > d ? c : d;
	return x > y ? x : y;
}
int main()
{
	int a[12][12]={{0}}, f[12][12][12][12]={{{{0}}}}, x=1, y=1, num=1,n;
	scanf("%d", &n);
	while (x != 0 || y != 0 || num != 0)
	{
		scanf("%d%d%d", &x, &y, &num);
		a[x][y] = num;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				for (int l = 1; l <= n; l++)
				{
					f[i][j][k][l] = max(f[i - 1][j][k-1][l], f[i-1][j][k][l-1], f[i][j-1][k - 1][l], f[i][j-1][k][l - 1]) + a[i][j] + a[k][l];
					if (i == k && j == l)
					{
						f[i][j][k][l] -= a[i][j];
					}
				}
			}
		}
	}
	printf("%d", f[n][n][n][n]);
}
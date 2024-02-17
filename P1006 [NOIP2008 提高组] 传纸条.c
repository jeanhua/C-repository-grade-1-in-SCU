#include<stdio.h>
int max(int a, int b, int c, int d)
{
	return (a > b ? a : b) > (c > d ? c : d) ? (a > b ? a : b) : (c > d ? c : d);
}
int map[60][60], m, n;
int dp[60][60][60][60];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int heart;
			scanf("%d", &heart);
			map[i][j] = heart;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				for (int l = 1; l <= n; l++)
				{
					dp[i][j][k][l] = max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1], dp[i][j - 1][k][l - 1])+map[i][j]+map[k][l];
					if (i == k && j == l)
					{
						dp[i][j][k][l] -= map[i][j];
					}
				}
			}
		}
	}
	printf("%d", dp[m][n][m][n]);
}
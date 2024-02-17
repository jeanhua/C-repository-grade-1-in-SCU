#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n;
	while (scanf("%d%d", &n, &m)==2)
	{
		//创建二维指针
		int** dp = (int*)malloc(sizeof(int*) * 600);
		for (int i = 0; i < 600; i++)dp[i] = (int*)malloc(sizeof(int*) * 600);
		for (int i = 0; i < 600; i++)
		{
			for (int j = 0; j < 600; j++)
			{
				dp[i][j] = (int)malloc(sizeof(int));
			}
		}
		//初始化二维指针
		for (int i = 0; i < 600; i++)
		{//行
			for (int j = 0; j < 600; j++)
			{//列
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++)
		{//行
			for (int j = 1; j <= m; j++)
			{//列
				scanf("%d", &dp[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] += dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}

		//释放内存
		for (int i = 0; i < 600; i++)free(dp[i]);
		free(dp);
	}
}
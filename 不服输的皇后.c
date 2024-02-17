#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int cheer[15][15] = { 0 };
	for (int i = 1; i <= 10; i++)
	{
		cheer[i][1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0)
		{
			for (int j = 1; j <= n; j++)
			{
				cheer[i][j] = 1;
			}
		}
	}
}
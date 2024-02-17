#include<stdio.h>
int main()
{
	int zuobiao[101][101];
	for (int i = 0; i <= 100; i++)
	{
		for (int i2 = 0; i2 <= 100; i2++)
		{
			zuobiao[i][i2] = -1;
		}
	}
	int n,a,b,g,k;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d%d%d%d", &a, &b, &g, &k);
		for (int longx = 1; longx <= g; longx++)
		{
			for (int longy = 1; longy <= k; longy++)
			{
				zuobiao[a + longx - 1][b + longy - 1] = i;
			}
		}
	}
	int x, y;
	scanf_s("%d%d", &x, &y);
	printf("%d", zuobiao[x][y]);
	return 0;
}
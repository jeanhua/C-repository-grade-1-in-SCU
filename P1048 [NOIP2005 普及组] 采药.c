#include<stdio.h>
int main()
{
	int t, m;
	scanf("%d%d", &t, &m);
	int dp[10000] = {0};
	int time[150], price[150];
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &time[i], &price[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = t; j >= time[i]; j--)
		{
			if (dp[j - time[i]] + price[i] > dp[j])
			{
				dp[j] = dp[j - time[i]] + price[i];
			}
		}
	}
	printf("%d", dp[t]);
}
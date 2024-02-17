#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	long long n, m,sum=0;
	scanf("%lld%lld", &n, &m);
	long long* hight = (long long*)malloc(sizeof(long long) * n);
	memset(hight, 0, sizeof(long long) * n);
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &hight[i]);
	}
	for (long long i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%lld%lld", &a, &b);
		if (a < b)
		{
			for (long long j = a; j < b; j++)
			{
				sum += hight[j] > hight[j + 1] ? hight[j] - hight[j + 1] : 0;
			}
		}
		else
		{
			for (long long j = a; j > b; j--)
			{
				sum += hight[j] > hight[j - 1] ? hight[j] - hight[j - 1] : 0;
			}
		}
		printf("%lld\n", sum);
		sum = 0;
	}
}
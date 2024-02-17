#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int n,in[110],sum=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &in[i]);
	}
	qsort(in, n, sizeof(int), cmp);
	for (int now = 2; now < n; now++)
	{
		int let = 1;
		for (int i = 0; i < n-1; i++)
		{
			if (i > now - 2)
			{
				break;
			}
			for (int i2 = i+1; i2 < n; i2++)
			{
				if (in[i] + in[i2] > in[now])
				{
					break;
				}
				if (in[i] + in[i2] == in[now])
				{
					if (let == 1)
					{
						sum++;
						let = 0;
					}
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
#include<stdio.h>
int f[20011];
int w[41];
int main()
{
	int n = 0, v = 0,j=0;
	scanf_s("%d%d", &v, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (j = v; j >= w[i]; j--)
		{
			if (f[j] < f[j - w[i]] + w[i])
			{
				f[j] = f[j - w[i]] + w[i];
			}
		}
	}
	printf("%d", v - f[v]);
	return 0;
}
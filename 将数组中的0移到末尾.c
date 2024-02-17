#include<stdio.h>
int main()
{
	int n, sum,in[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int sum0 = 0,qtmp;
		scanf("%d", &sum);
		for (int q = 0; q < sum; q++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (tmp != 0)
			{
				in[q] = tmp;
			}
			else
			{
				in[q] = -1024;
				sum0++;
			}
			qtmp = q+1;
		}
		for (int i2 = qtmp; i2 <= qtmp + sum0; i2++)
		{
			in[i2] = 0;
		}
		for (int re = 0; re < qtmp + sum0; re++)
		{
			if (in[re] != -1024)
			{
				printf("%d ", in[re]);
			}
		}
		printf("\n");

	}
}
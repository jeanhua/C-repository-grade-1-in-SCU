#include<stdio.h>
int a, n, m, x, sum[30], in[30], out[30];
int main()
{
	scanf_s("%d%d%d%d", &a, &n, &m, &x);
	sum[1] = sum[2] = a;
	in[1] = a;
	out[1] = 0;
	for (int p = 0; sum[n - 1] != m; p++)
	{
		in[2] = out[2] = p;
		for (int i = 2; i < n - 1; i++)
		{
			in[i + 1] = in[i] + in[i - 1];
			out[i + 1] = in[i];
			sum[i + 1] = sum[i] + in[i + 1] - out[i + 1];
		}
	}
	printf("%d\n", sum[x]);
	return 0;
}
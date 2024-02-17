#include<stdio.h>
int main()
{
	int n, in[200],sum=0,xp=0,step=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
		sum += in[i];
	}
	xp = sum / n;
	for (int i = 0; i < n; i++)
	{
		in[i] -= xp;
	}
	for (int i = 0; i < n; i++)
	{
		if (in[i] != 0)
		{
			if (in[i] > 0)
			{
				in[i + 1] += in[i];
				in[i] = 0;
				step++;
			}
			if (in[i] < 0)
			{
				in[i + 1] += in[i];
				in[i] = 0;
				step++;
			}
		}
	}
	printf("%d", step);
}
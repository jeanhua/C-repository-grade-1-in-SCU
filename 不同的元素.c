#include<stdio.h>
int main()
{
	int sum=0, in[35],n;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &in[i]);
		}
		int tmp;
		for (int i = 0; i < n; i++)
		{
			if (in[i] != NULL)
			{
				for (int i2 = i + 1; i2 < n; i2++)
				{
					if (in[i] == in[i2])
					{
						in[i2] = NULL;
					}
				}
				sum++;
			}
		}
		printf("%d\n", sum);
	}
}
#include<stdio.h>
int e[1010];
int main()
{
	int s,n,max=0,result[1000];
	scanf_s("%d", &n);
	int abc = 0;
	for (abc = 0; abc< n; abc++)
	{
		for (int i = 0; i < 1010; i++)
		{
			e[i] = 0;
		}
		max = 0;
		do {
			scanf_s("%d", &s);
			max++;
			e[s] = 1;
		} while (s != 0);
		for (int q = 0; q <= max; q++)
		{
			if (e[q] != 1)
			{
				result[abc] = q;
			}
		}
	}
	for (int i = 0; i < abc; i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}
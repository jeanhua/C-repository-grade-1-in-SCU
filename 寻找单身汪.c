#include<stdio.h>
int main()
{
	int x,n[100];
	scanf_s("%d", &x);
	for (int i = 0; i < x; i++)
	{
		scanf_s("%d", &n[i]);
	}
	for (int q = 0; q < x; q++)
	{
		for (int e = 0; e < q; e++)
		{
			if (n[e] == n[q])
			{
				n[e] = n[q] = 0;
			}
		}
	}
	for (int i = 0; i < x; i++)
	{
		if (n[i] != 0)
		{
			printf("%d", n[i]);
		}
	}
}
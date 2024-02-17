#include<stdio.h>
int main()
{
	int n, x[100];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (((0 == x[i] % 4 && x[i] % 100 != 0) || (0 == x[i] % 400)) && x[i] > 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
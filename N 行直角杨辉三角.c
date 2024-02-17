#include<stdio.h>
int jiecheng(int a)
{
	if (a == 0)
	{
		return 1;
	}
	int in = a;
	for (int i = 1; i < a; i++)
	{
		in *= i;
	}
	return in;
}
int calgorithm(int a, int b)
{
	if (b == 0 || a==0)
	{
		return 1;
	}
	int re = jiecheng(a) / (jiecheng(b) * jiecheng(a - b));
	return re;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n > 20||n<1)
	{
		printf("Input Error\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int i2 = 0; i2 <= i; i2++)
		{
			printf("%d,", calgorithm(i, i2));
		}
		printf("\n");
	}
}
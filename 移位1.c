#include<stdio.h>
void zuoyi(int* a)
{
	int tmp;
	tmp = a[1];
	for (int i = 1; i <= 9; i++)
	{
		a[i] = a[i + 1];
	}
	a[10] = tmp;
}
int main()
{
	int n, in[15];
	scanf("%d", &n);
	for (int i = 1; i <= 10; i++)
	{
		scanf("%d", &in[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		zuoyi(in);
	}
	for (int i = 1; i <= 10; i++)
	{
		printf("%d ", in[i]);
	}
}
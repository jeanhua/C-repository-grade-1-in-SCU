#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int a, b, sum[300];
	scanf("%d%d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &sum[i]);
	}
	for (int i = a; i < a + b; i++)
	{
		scanf("%d", &sum[i]);
	}
	qsort(sum, a + b, sizeof(int), cmp);
	for (int i = 0; i < a + b; i++)
	{
		printf("%d ", sum[i]);
	}
}
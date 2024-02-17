#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int n;
	scanf_s("%d", &n);
	int in[100];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &in[i]);
	}
	qsort(in, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", in[i]);
	}
	return 0;
}
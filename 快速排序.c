#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int i;
	int inp[100];
	for (i = 0; i < 100; i++)
	{
		scanf_s("%d", &inp[i]);
		if (inp[i] == 0)
		{
			break;
		}
	}
	qsort(inp, i, sizeof(int), compare);
	for (int q = 0; q < i; q++)
	{
		printf("%d ", inp[q]);
	}
	return 0;
}
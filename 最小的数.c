#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int in[60],n=0,now=0;
	for (int num = 0; num <= 9; num++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			in[now] = num;
			now++;
		}
	}
	qsort(in, now, sizeof(int), cmp);
	for (int i = 0; i < now; i++)
	{
		if (in[0] == 0 && in[i] != 0)
		{
			in[0] = in[i];
			in[i] = 0;
			break;
		}
	}
	for (int i = 0; i < now; i++)
	{
		printf("%d", in[i]);
	}
}
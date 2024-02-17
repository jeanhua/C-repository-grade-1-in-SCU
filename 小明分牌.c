#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int input[1000];
	int n,sum=0;
	scanf_s("%d", &n);
	int min;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &input[i]);
	}
	int k = 0,report;
	for (int i = 0; i < n; i++)
	{
		if (input[i] != -1)
		{
			if (k == 0)
			{
				min = input[i];
				k = 1;
			}
			if(min>input)
			min = input[i];
			report = i;
			break;
		}
		if (i == -1)
		{
			//½áÊø
		}
	}
	
	sum += min;
	printf("%d", sum);
}
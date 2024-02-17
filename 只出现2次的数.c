#include<stdio.h>
int main()
{
	int n,in[1000],result[1000];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d",&in[i]);
	}
	int yes = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0,tmp=i[in];
		for (int q = i; q < n; q++)
		{
			if (tmp == in[q])
			{
				sum++;
				in[q] = -1;
			}
		}
		if (sum == 2 && tmp != -1)
		{
			printf("%d ", tmp);
			yes = 1;
		}
	}
	if (yes == 0)
	{
		printf("none");
	}
	return 0;
}
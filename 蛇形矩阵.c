#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int beginx = 1, beginy = 1;
	for (int i = 1; i <= n; i++)//行数
	{
		for (int j = i; j <= n; j++)//列数
		{
			printf("%d ", beginx);
			beginx += j + 1;
		}
		beginy += i;
		beginx = beginy;
		printf("\n");
	}
}
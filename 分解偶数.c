#include<stdio.h>
int isTheNum(int n)
{
	if (n < 2)return -1; else if (n == 2)return 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)return -1;
	}
	return 1;
}
int main()
{
	int n;
	int record[100] = {0};
	scanf("%d", &n);
	if (n % 2 != 0||n<6)
	{
		printf("ERROR\n");
		return 0;
	}
	for (int i = 2; i <n; i++)
	{
		if (isTheNum(i) == 1 && isTheNum(n - i) == 1)
		{
			int is = 1;
			for (int j = 2; j <= i; j++)if (n - i == record[j])is=0;
			if (is == 1) {
				printf("%d %d\n", i, n - i);
				record[i] =i;
			}
		}
	}
}
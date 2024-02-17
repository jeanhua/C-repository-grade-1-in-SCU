#include<stdio.h>
int main()
{
	int n,input,sum=0,sum1=0,q=0,result[100];
	scanf_s("%d", &n);
	for (int w = 0; w < n; w++)
	{
		do {
			scanf_s("%d", &input);
			sum1 += input;
			q++;
		} while (input != 0);
		for (int i = 0; i <= q; i++)
		{
			sum += i;
		}
		result[w] = sum - sum1;
		sum1 = sum = q = 0;
	}
	for (int w = 0; w < n; w++)
	{
		printf("%d\n", result[w]);
	}
	return 0;
}
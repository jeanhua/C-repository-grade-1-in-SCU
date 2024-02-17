#include<stdio.h>
#include<math.h>
int main()
{
	int m = 0, n = 0,num_sum=0,daoxu=0;
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &n);
		for (int q = n; q >= n; q++)
		{
			int temp = q;
			int num[10];
			daoxu = 0;
			for (num_sum = 0; num_sum < 10; num_sum++)
			{
				num[num_sum] = temp % 10;
				temp /= 10;
				if (temp == 0)
				{
					break;
				}
			}
			for (int x = 0; x <= num_sum; x++)
			{
				daoxu += num[x] * pow(10, num_sum - x);
			}
			if (daoxu == q)
			{
				printf("%d\n", q);
				break;
			}
		}
	}
	return 0;
}
#include<stdio.h>
int main()
{
	int n,input;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &input);
		for (int q = 2; q <= input; q++)
		{
			int x;
			for (x = 2; x <= input; x++)
			{
				if (q % x == 0)
				{
					break;
				}
			}
			if (x == q)
			{
				printf("%d ", q);
			}
		}
		printf("\n");
	}
	return 0;
}
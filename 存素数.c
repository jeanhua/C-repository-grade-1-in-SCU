#include<stdio.h>
int main()
{
	int n,in,result=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		result = 0;
		scanf_s("%d",&in);
		if (in <= 1)
		{
			printf("Input Error\n");
		}
		else
		{
			for (int a = 2; a <= in; a++)
			{
				int b;
				for (b = 2; b <= in; b++)
				{
					if (a % b == 0)
					{
						break;
					}
				}
				if (b == a)
				{
					result++;
				}
			}
			if (result > 100)
			{
				printf("Overflow\n");
			}
			else
			{
				for (int a = 2; a <= in; a++)
				{
					int b;
					for (b = 2; b <= in; b++)
					{
						if (a % b == 0)
						{
							break;
						}
					}
					if (b == a)
					{
						printf("%d,", a);
					}
				}
				printf("\n");
			}
		}
	}
	
}
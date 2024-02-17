#include<stdio.h>
int main()
{
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		int in, result = -1;
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &in);
			if (in % 3 == 0)
			{
				if ((in < result && result != -1) || result == -1)
				{
					result = in;
				}
			}
		}
		if (result == -1)
		{
			printf("Null\n");
		}
		else
		{
			printf("%d\n", result);
		}
	}
	return 0;
}
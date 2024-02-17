#include <stdio.h>
#include <math.h>
int main()
{
	int s[100], m[100], n=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d%d", &s[i], &m[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int yes = 0;
		for (int a = s[i]; a <= m[i]; a++)
		{
			double x = a - a % 100; x /= 100;
			double y = a % 100 - a % 100 % 10; y /= 10;
			double z = a % 100 % 10;
			if ((x * x * x + y * y * y + z * z * z) == (x * 100 + y * 10 + z))
			{
				printf("%.0lf ", x * 100 + y * 10 + z);
				yes = 1;
			}
		}
		if (yes == 0)
		{
			printf("%d", -1);
		}
		printf("\n");
	}
	return 0;
}
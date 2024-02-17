#include<stdio.h>
#include<math.h>
int  main()
{
	int n;
	scanf_s("%d", &n);
	double x[100], y[100], sum[100],result=0,s=0;
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%lf%lf%lf", &x[i-1], &y[i-1], &sum[i-1]);
		s=sqrt(x[i-1]*x[i-1]+y[i-1]*y[i-1]);
		result += 2 * (s / 50) + sum[i-1] * 1.5;
	}
	if ((int)result < result)
	{
		printf("%d\n", (int)result+1);
	}
	else
	{
		printf("%.0lf\n", result);
	}
	return 0;
}

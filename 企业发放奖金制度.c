#include<stdio.h>
int main()
{
	double i, x;
	scanf_s("%lf", &i);
	switch ((int)((i-1)/100000))
	{
	case 0:
		x = 0.1 * i;
		break;
	case 1:
		x = 10000 + (i - 100000) * 0.075;
		break;
	case 2:
	case 3:
		x = 10000 + 100000 * 0.075 + (i - 200000) * 0.05;
		break;
	case 4:
	case 5:
		x = 10000 + 100000 * 0.075 + 200000 * 0.05 + (i - 400000) * 0.03;
		break;
	case 6:
	case 7:
	case 8:
	case 9:
		x = 10000 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (i - 600000) * 0.015;
		break;
	default:
		x = 10000 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + (i - 1000000) * 0.01;
		break;
	}
	printf("%.2lf", x);
}
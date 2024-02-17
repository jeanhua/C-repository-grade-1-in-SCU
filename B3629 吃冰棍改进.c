#include<stdio.h> 
int main()
{
	long long n, x;
	scanf_s("%lld", &n);
	x = n;
	if (n % 3 == 0)
	{
		n++;
	}
	x = n - n / 3;
	printf("%lld\n", x);
	return 0;
}
#include<stdio.h>
#include<math.h>
long long count(long long a)
{
	return log10l(a) + 1.0;
}
int main()
{
	long long a, b, x;
	scanf("%lld%lld%lld", &a, &b, &x);
	long long n = x / 2;
	while (a * n + b * (log10l(n) + 1) > x)
	{
		n /= 2;
	}
	long long resu = 0;
	for (long long i = n; i <= 2 * n; i += (2 * n - n) / 2 == 0 ? 1 : (2 * n - n) / 2)
	{
		if (a * (i)+b * (log10l(i) + 1) <= x)
		{
			resu = i;
		}
	}
	long long resu1 = resu;
	long long tmp=0;
	long long i1 = resu1;
	ada:
	if (a * i1 + b * count(i1) <= x)
	{
		resu = i1;
		i1++;
		goto ada;
	}
	printf("%lld", resu);
}
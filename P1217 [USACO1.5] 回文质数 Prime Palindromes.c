#include<stdio.h>
#include<math.h>
int shifouzhishu(long long n)
{
	for (int i = 3; i * i <= n; i += 2)if (n % i == 0)return 0;
	return 1;
}
int shifouhuiwenhsu(long long n)
{
	long long num = n;
	long long tmp = 0;
	for (int i = log(num) / log(10); i >= 0; i--)
	{
		tmp += num % 10 * pow(10, i);
		num /= 10;
	}
	if (n == tmp)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ws(int k)  //Î»Êý
{
	if (k >= 10 && k < 100 && k != 11 || k >= 1000 && k < 10000)return 0;
	if (k >= 100000 && k < 1000000 || k >= 10000000 && k < 100000000)return 0;
	return 1;
}
int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	for (long long i = a % 2 == 0 ? a + 1 : a; i <= b; i += 2)
	{
		if (ws(i) != 0) {
			if (shifouzhishu(i) == 1 && shifouhuiwenhsu(i) == 1)
			{
				printf("%lld\n", i);
			}
		}
	}
}
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
bool cop(int &a, int &b)
{
	return a < b;
}
int main()
{
	int n, inp[110],sum=0,result=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &inp[i]);
		sum += inp[i];
	}
	int p = sum / n;
	sort(inp, inp + n, cop);
	while (inp[0] != inp[n - 1])
	{
		result++;
		int more = inp[n - 1] - p;
		int less = p - inp[0];
		if (more >= less)
		{
			inp[n - 1] -= less;
			inp[0] += less;
		}
		else if (more < less)
		{
			inp[n - 1] -= more;
			inp[0] += more;
		}
		sort(inp, inp + n, cop);
	}
	printf("%d", result);
	return 0;
}
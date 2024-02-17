#include<stdio.h>
#include<math.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int n,a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		int maxnum = max(max(a, b), c);
		int minnum = min(min(a, b), c);
		int middle = a + b + c - maxnum - minnum;
		double sinx = (double)minnum / (double)maxnum;
		double siny = (double)middle / (double)maxnum;
		if (sinx * sinx + siny * siny - 1==0&&(sinx!=0&&siny!=0))printf("Yes\n");else printf("No\n");
	}
	return 0;
}
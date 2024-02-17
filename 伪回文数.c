#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int tmp,wei[15];
		scanf("%d", &tmp);
		int len = 0;//len=Î»Êý
		for (len = 0; tmp != 0; len++)
		{
			wei[len] = tmp % 10;
			tmp /= 10;
		}
		int res = 0;
		for (int m = 0; m <= len / 2; m++)
		{
			if (wei[m] != wei[len - m-1])
			{
				res += 1;
			}
		}
		if (res != 1||len==1)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}

}
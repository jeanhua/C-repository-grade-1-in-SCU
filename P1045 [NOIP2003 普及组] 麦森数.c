#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int wei[600];
	for (int i = 1; i <= 500; i++)wei[i] = 0; wei[1] = 1;
	int p;
	scanf("%d", &p);
	int weishu= p *log10(2) + 1;
	printf("%d\n", weishu);
	int more=0;
	for (int i = p; i >= 20; i -= 20)
	{
		for (int j = 1; j <= 500; j++)
		{
			wei[j] = wei[j] * pow(2, 20) + more;
			more = wei[j] - (wei[j] % 10);
			more /= 10;
			wei[j] %= 10;
		}
		more = 0;
		p -= 20;
	}
	if (p > 0)
	{
		for (int j = 1; j <= 500; j++)
		{
			wei[j] = wei[j] * pow(2, p) + more;
			more = wei[j] - (wei[j] % 10);
			more /= 10;
			wei[j] %= 10;
		}
		more = 0;
	}
	if (weishu < 500)
	{
		for (int i = 500; i > weishu; i--)
		{
			wei[i] = 0;
		}
	}
	wei[1] -= 1;
	int shuchu = 500;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 50; j++)
		{
			printf("%d", wei[shuchu--]);
		}
		printf("\n");
	}
}
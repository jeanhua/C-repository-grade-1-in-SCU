#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	getchar();
	int sum = 0, num = 0;
	char in[500];
	fgets(in, 450, stdin);
	int len = strlen(in);
	int fuhao = 0;//0Õý1¸º
	for (int i = 0; i < len; i++)
	{
		fuhao = 0;
		if ((in[i] >= '0' && in[i] <= '9')||in[i]=='-')
		{
			if (in[i] == '-')
			{
				fuhao = 1;
				i++;
			}
			int wei = i;
			for (int j = i + 1; j < len; j++)
			{
				if (in[j] == ' ' || in[j] == 'n' || in[j] == '\n')
				{
					num++;
					break;
				}
				else
				{
					wei++;
				}
			}
			int qwq = 0;
			for (int q = wei; q >= i; q--)
			{
				sum += (in[i + qwq] - 48) * pow(10, q - i)*(fuhao==0?1:-1);
				qwq++;
			}
			i = wei;
		}
	}
	double s = sum, m = num;
	if (num == 0)
	{
		printf("n/a\n");
		return 0;
	}
	printf("%.2f\n", s / m);
}
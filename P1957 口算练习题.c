#include<stdio.h>
#include<string.h>
#include<math.h>
int cout(int a)
{
	if (a ==0)
	{
		return 1;
	}
	if (a >0)
	{
		if (a == 1000)
		{
			return 4;
		}
		return (log(a) / log(10) + 1);
	}
	if (a < 0)
	{
		return (log(-a) / log(10) + 1 + 1);
	}

}
int main()
{
	int n = 0;
	scanf("%d", &n);
	char in[20],tmp;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d", in,&a);
		if (in[0] != 'a' && in[0] != 'b' && in[0] != 'c')
		{
			b = 0;
			for (int i = 0; i < strlen(in); i++)
			{
				b += ((int)in[i] - 48) * pow(10, strlen(in) - i - 1);
			}
			switch (tmp)
			{
			case '+':
				printf("%d+%d=%d\n", b, a, b + a);
				printf("%d\n", cout(b) + cout(a) + cout(a + b) + 2);
				break;
			case '-':
				printf("%d-%d=%d\n", b, a, b - a);
				printf("%d\n", cout(b) + cout(a) + cout(b-a) + 2);
				break;
			case 'x':
				printf("%d*%d=%d\n", b, a, b * a);
				printf("%d\n", cout(b) + cout(a) + cout(b * a) + 2);
				break;
			}
		}
		else
		{
			tmp = in[0];
			switch (tmp)
			{
			case 'a':
				tmp = '+';
				break;
			case 'b':
				tmp = '-';
				break;
			case 'c':
				tmp = 'x';
				break;
			}
			scanf("%d", &b);
			switch (in[0])
			{
			case 'a':
				printf("%d+%d=%d\n", a, b, b + a);
				int test = cout(b);
				printf("%d\n", cout(b) + cout(a) + cout(b + a) + 2);
				break;
			case 'b':
				printf("%d-%d=%d\n", a, b, a - b);
				printf("%d\n", cout(b) + cout(a) + cout(a-b) + 2);
				break;
			case 'c':
				printf("%d*%d=%d\n", a, b, b * a);
				printf("%d\n", cout(b) + cout(a) + cout(b * a) + 2);
				break;
			}
		}
		
	}
}
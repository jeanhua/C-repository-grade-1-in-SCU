#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char in[120]; 
	int len = 0, i2 = 0,tmp, ascii[1000],cont;
	fgets(in, 100, stdin);
	len = strlen(in)-1;
	for (int i = 0; i < len; i++)
	{
		tmp = (int)in[i];
		for (int i2 = 0; i2 < 8; i2++)
		{
			ascii[8 * (i + 1) - 1 - i2] = tmp % 2;
			tmp /= 2;
		}
	}
	for (int less = 8*len;less<(len*8/6+1)*6;less++)
	{
		ascii[less] = 0;
	}
	int panduan = len * 8 % 6 == 0 ? len * 8 / 6 : len * 8 / 6 + 1;
	for (int x = 0; x < panduan; x++)
	{
		tmp = 0;
		for (int q = 0; q < 6; q++)
		{
			tmp += ascii[q + x * 6] * pow(2, 5 - q);
		}
		if (tmp<26)
		{
			printf("%c", tmp + 65);
		}
		if (tmp > 25 && tmp < 52)
		{
			printf("%c", tmp + 71);
		}
		if (tmp > 51 && tmp < 62)
		{
			printf("%c", tmp - 4);
		}
		if (tmp == 62)
		{
			printf("+");
		}
		if (tmp == 63)
		{
			printf("/");
		}
	}
	int sum = len * 8 / 6 + 1;
	sum = sum / 4 + 1;
	sum *= 4;
	if ((len * 8 / 6) % 4 != 0)
	{
		
		for (int i = 0; i < sum - (len * 8 / 6 + 1); i++)
		{
			printf("=");
		}
	}
	printf("\n");
	return 0;
}
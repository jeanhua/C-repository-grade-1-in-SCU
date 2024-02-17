#include<stdio.h>
#include<string.h>
void start(char* a,int sum)
{
	int begin = 0, end = 0;
sta:

	for (int i = begin; i <= sum; i++)//寻找结束位置
	{
		if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')))
		{
			end = i;
			break;
		}
	}
	for (int i = end - 1; i >= begin; i--)//输出
	{
		putchar(a[i]);
	}
	for (int i = end; i <= sum; i++)//寻找开始位置
	{
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
		{
			begin = i;
			break;
		}
		if (i == sum)
		{
			return;
		}
	}
	for (int i = end; i < begin; i++)
	{
		putchar(a[i]);
	}
	goto sta;
}
int main()
{
	char in[1500] = { '\0' };
	for (int i = 0; i < 1000; i++)
	{
		in[i] = getchar();
		if (in[i] == '\n')
		{
			in[i] = '\0';
			break;
		}
	}
	int last = strlen(in),biaodian;
	start(in, last);
	for (int i = last - 1; i >= 0; i--)
	{
		if ((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z'))
		{
			biaodian = i;
			break;
		}
	}
	printf("%s", &in[biaodian + 1]);
}
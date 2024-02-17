#include<stdio.h>
#include<string.h>
void xiaoxie(const char* a, char* b)
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			b[i] = a[i] + 'a' - 'A';
		}
		else
		{
			b[i] = a[i];
		}
	}
	b[strlen(a)] = '\0';
}
int finds(const char* a, const char* b, int beginfind)//a是被找的字符串，b是要找的字符串
{
	for (int i = beginfind; i < strlen(a); i++)
	{
		if (a[i] == b[0])
		{
			for (int q = 0; q < strlen(b); q++)
			{
				if (a[i + q] != b[q])
				{
					break;
				}
				else if (q == strlen(b) - 1)
				{
					return i;
				}
			}
		}
		if (i == strlen(a) - 1)
		{
			return -1;
		}
	}
}
int main()
{
	char in[110],in_low[110], find[110],find_low[110];
	gets(in);
	gets(find);
	xiaoxie(&in, &in_low);
	xiaoxie(&find, &find_low);
	int from = 0,out_num=0;
	int da = 0;
	while (out_num < strlen(in))
	{
		from = finds(&in_low, &find_low, from+1);
		if (from == -1)
		{
			for (; out_num < strlen(in); out_num++)
			{
				printf("%c", in[out_num]);
			}
			return 0;
		}
		for (; out_num < from; out_num++)
		{
			printf("%c", in[out_num]);
		}
		if (from < strlen(in))
		{
			printf("/*");
			da = 1;

		}
		for (int i = from; i < from + strlen(find); i++)
		{
			printf("%c", in[i]);
			out_num++;
		}
		if (da == 1)
		{
			printf("*/");
			da = 0;
		}
	}
	
	
}
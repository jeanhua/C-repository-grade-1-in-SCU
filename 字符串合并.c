#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}
int main()
{
	char in[200],tmp='0', i = 0;
	while (tmp != ' ')
	{
		scanf("%c", &tmp);
		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9'))
		{
			in[i] = tmp;
			i++;
		}
	}
	while (tmp != '\n')
	{
		scanf("%c", &tmp);
		if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9'))
		{
			in[i] = tmp;
			i++;
		}
	}
	in[i] = '\0';
	qsort(in, i, sizeof(char), cmp);
	printf("%s",in);
}
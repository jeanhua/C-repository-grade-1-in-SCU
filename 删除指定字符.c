#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}
int main()
{
	char in[200] = { 0 }, str[200] = { 0 };
	fgets(in, 190, stdin);
	fgets(str, 190, stdin);
	int len_in = strlen(in);
	int len_str = strlen(str);
	for (int i = 0; i < len_str; i++)
	{
		for (int j = 0; j < len_in; j++)
		{
			if (in[j] == str[i])
			{
				in[j] = '\0';
			}
		}
	}
	char result[200] = {0};
	int a=0;
	for (int i = 0; i < 200; i++)
	{
		if (in[i] != '\0')
		{
			result[a++] = in[i];
		}
	}
	result[a] = '\0';
	if (strlen(result) == 0)
	{
		printf("null\n");
		return 0;
	}
	qsort(result, a, sizeof(result[0]), cmp);
	printf("%s\n", result);
}
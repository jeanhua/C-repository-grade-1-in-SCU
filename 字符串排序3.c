#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strchange(char* a,char *b)
{
	char tmp[150];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}
int main()
{
	int n = 0;
	char in[50][150];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		fgets(in[i], 100, stdin);
	}
	for (int q = 0; q < n * (n - 1) / 2; q++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (strcmp(in[i], in[i + 1]) > 0)
			{
				strchange(in[i], in[i + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s", in[i]);
	}
}
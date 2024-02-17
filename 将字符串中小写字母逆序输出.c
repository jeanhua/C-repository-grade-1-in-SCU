#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char in[150];
	for (int i = 0; i < n; i++)
	{
		fgets(in, 100, stdin);
		char lowstr[150];
		int a = 0;
		int len_in = strlen(in);
		for (int j = 0; j < len_in; j++)
		{
			if (in[j] >= 'a' && in[j] <= 'z')
			{
				lowstr[a++] = in[j];
			}
		}
		lowstr[a] = '\0';
		for (int q = a - 1; q >= 0; q--)
		{
			putchar(lowstr[q]);
		}
		putchar('\n');
		
	}
}
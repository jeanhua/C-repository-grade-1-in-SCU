#include<stdio.h>
#include<string.h>
int main()
{
	char in[100];
	fgets(in, 90, stdin);
	int len = strlen(in)-1;
	for (int i = 0; in[i] != '\0'; i++)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			in[i] = in[i] + 'a' - 'A';
		}
		else if(in[i] >= 'a' && in[i] <= 'z')
		{
			in[i] = in[i] - 'a' + 'A';
		}
		else
		{
			in[i] = '#';
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (in[i] != '#')
		{
			printf("%c", in[i]);
		}
		else
		{
			printf("^_^");
		}
	}
}
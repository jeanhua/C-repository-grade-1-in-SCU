#include<stdio.h>
#include<string.h>
int main()
{
	char in[150];
	fgets(in, 100, stdin);
	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			if (in[i] >= 'W')
			{
				in[i] = 3 - ('Z' - in[i]) + 'A';
			}
			else
			{
				in[i] += 4;
			}
		}
		if (in[i] >= 'a' && in[i] <= 'z')
		{
			if (in[i] >= 'w')
			{
				in[i] = 3-('z' - in[i]) + 'a';
			}
			else
			{
				in[i] += 4;
			}
		}
	}
	printf("%s", in);
}
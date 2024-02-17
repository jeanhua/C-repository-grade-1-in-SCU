#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] != '*')
		{
			for (int i2 = i + 1; i2 < len; i2++)
			{
				if (str[i] == str[i2])
				{
					str[i2] = '*';
				}
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (str[i] != '*')
		{
			printf("%c", str[i]);
		}
	}
}
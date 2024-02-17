#include<stdio.h>
#include<string.h>
int main()
{
	int max=0;
	char a[300];
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < len; i++)
	{
		putchar(a[i]);
		if (a[i] == max)
		{
			printf("(SCU)");
		}
	}
}
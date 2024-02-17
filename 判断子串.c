#include<stdio.h>
#include<string.h>
int main()
{
	char a[300];
	char b[300];
	scanf("%s", a);
	scanf("%s", b);
	if (strstr(a, b) != NULL)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
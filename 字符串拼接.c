#include<stdio.h>
int main()
{
	char a[10], b[10], c[20];
	scanf_s("%s", a,10);
	scanf_s("%s", b,10);
	int i = 0;
	for (i = 0; a[i] != '\0'; i++)
	{
		c[i] = a[i];
	}
	for (int x = 0; b[x] != '\0'; x++)
	{
		c[i] = b[x];
		i++;
	}
	i[c] = '\0';
	printf("%s", c);
	return 0;
}
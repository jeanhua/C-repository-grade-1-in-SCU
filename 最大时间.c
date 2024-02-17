#include<stdio.h>
int main()
{
	char a, b, c, d;
	scanf_s("%c", &a);
	scanf_s("%c", &b);
	getchar();
	scanf_s("%c", &c);
	scanf_s("%c", &d);
	if (a == '?')
	{
		a = '2';
	}
	if (a == '2' &&b == '?')
	{
		b = '3';
	}
	else if (b == '?')
	{
		b = '9';
	}
	if (c == '?')
	{
		c = '5';
	}
	if (d == '?')
	{
		d = '9';
	}
	printf("%c%c:%c%c", a, b, c, d);
}
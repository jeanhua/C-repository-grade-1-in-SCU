#include<stdio.h>
int main()
{
	int b[3],tmp;
	scanf("%d", &tmp);
	b[0] = tmp / 100;
	b[1] = (tmp%100)/10;
	b[2] = tmp % 100 % 10;
	printf("%d", b[0]+b[1]+b[2]);
}
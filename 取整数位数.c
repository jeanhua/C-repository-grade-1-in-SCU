#include<stdio.h>
int main()
{
	int a;
	printf("程序将截取第3位到第6位\n");
	scanf_s("%*2d%3d", &a);
	printf("%d", a);
	return 0;
}
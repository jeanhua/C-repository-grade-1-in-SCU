#include<stdio.h>
int main()
{
	float a[100];
	int i = 0;
	scanf_s("%f", &a[i++]);
	while (getchar()!='\n')
	{
		scanf_s("%f", &a[i++]);
	}
	int q = 0;
	while (q<i)
	{
		printf("%.3f %d\n", a[q], (int)a[q]);
		q++;
	}
	
}
#include<stdio.h>
int main(void)
{
	printf("���������λ��������ִ���㷨��������3����Ϊ2+22+222\n");
	int n = 1;
	int result = 0;
	scanf("%d",&n);
	if(n==0)
	{
		printf("error input!\n");
		return 0;
	}
	int num[n];
	num[0]=2;
	int x;
	for(x=0;x<n-1;x++)
	{
		num[x+1]=num[x]*10+2;
	}
	x=0;
	while(x<n)
	{
		result=result+num[x];
		x++; 
	}
	printf("%d\n",result);
	return 0;
}

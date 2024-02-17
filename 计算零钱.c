#include<stdio.h>
int main()
{
	int sum,tw,te,fi,on = 0;
	printf("«Î ‰»Î«Æ ˝£°\n");
	scanf("%d",&sum);
	tw = sum/20;
	if(tw!=0)
	{
		sum=sum-(20*tw);
	}
	te=sum/10;
	if(te!=0)
	{
		sum=sum-(10*te);
	}
	fi=sum/5;
	if(fi!=0)
	{
		sum=sum-(5*fi);
	}
	on=sum;
	printf("20 dollars need: %d\n10 dollars need: %d\n5 dollars need: %d\n1 dollar need: %d\n",tw,te,fi,on);
	system("pause");
	return 0;
}

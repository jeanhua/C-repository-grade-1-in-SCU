#include<stdio.h>
int main(void)
{
	printf("how many numbers ?\n");
	int num = 0;
	scanf("%d",&num);
	if(num<2)
	{
		printf("you need more than 2 numbers!\n");
		main();
	}
	int input[num];
	int result[num];
	printf("list numbers !\n");
	int n = 0;
	while(1)
	{
		scanf("%d",&input[n]);
		n++;
		if(n==num)
		{
			break;
		}
	}
//ÅÅĞò×ó±ß
	int a;
	int comlish_num = 0;
	int cont = 1;
	int num1 = num / 2;
	while(cont){
	for(a=0;a<=num1-1-comlish_num;a++)
	{
		if(input[a]>input[a+1])
		{
			int temp = 0;
			temp = input[a];
			input[a]=input[a+1];
			input[a+1]=temp;
		}	
    } 
    for(a=0;input[a]<=input[a+1];a++)
    {
    	if(a>=num1-1-comlish_num)
    	{
    		cont = 0;
		}
	}
	comlish_num++;
}
//ÅÅĞòÓÒ±ß 
cont = 1;
comlish_num = 0;
    while(cont){
	for(a=num1;a <= num-2-comlish_num;a++)
	{
		if(input[a]>input[a+1])
		{
			int temp = 0;
			temp = input[a];
			input[a]=input[a+1];
			input[a+1]=temp;
		}	
    } 
    for(a=num1;input[a]<=input[a+1];a++)
    {
    	if(a>=num-2-comlish_num)
    	{
    		cont = 0;
		}
	}
}
//Á½×éÅÅĞò
int b = num1;
int x = 0;
a=0;
cont = 1;
while(cont)
{
	if(input[a]<=input[b])
	{
		result[x]=input[a];
		x++;
		a++;
	}
	else{
		result[x]=input[b];
		x++;
		b++;
	}
	if(x==num)
	{
		cont = 0;
		break;
	}
	if(a==num1)
	{
		for(;x<=num;x++,b++)
		{
			result[x]=input[b];
		}
		break;
	}
	if(b==num)
	{
		for(;x<=num;x++,a++)
		{
			result[x]=input[a];
		}
		break;
	}
	
}
printf("result:\n");
for(x=0;x<=num-1;x++)
{
printf("%d ",result[x]);
}
	return 0;
}

#include <stdio.h>
int main() 
{
	printf("�������֣���-1���������10000��\n");
	int input[10001];
	int num_sum,temp = 0;
	while(1)
	{
		scanf("%d",&input[num_sum]);
		if(input[num_sum]== -1 )
		{
			break;
		} 
		num_sum++;
	}
	if(num_sum<2)
	{
		printf("������Ŀ���٣�\n");
		return 0;
	}
	if(num_sum>10000)
	{
		printf("������Ŀ���࣡\n");
		return 0;
	}
	int a=0;
	int start = 1;
	int x=0;
	while(start)
	{
		for(a=0;a<num_sum-1-x;a++)
	    {
	    	
	        if(input[a]>input[a+1])
	       {	    
		     temp=input[a];
		     input[a]=input[a+1];
		     input[a+1]=temp;
	       }
		}
		for(a=0;input[a]<=input[a+1];a++)
		{
			if(a>=num_sum-2-x)
			{
				start = 0;
				break;
			}
		}
		x++;
    }
	printf("�������£�\n");
	for(a=0;a<num_sum;a++)
	{
		printf("%d ",input[a]);
	}
	printf("\n"); 
	system("pause");
	return 0;
}


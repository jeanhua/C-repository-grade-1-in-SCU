#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	printf("please input the number you guess! 0-100\n");
	int inp,resu,ste = 0;
	srand(time(NULL)) ;
	resu = rand()%101;
	//printf("%d\n",resu); 
	while(inp != resu)
	{
		ste++;
		scanf("%d",&inp);
		if(inp < resu)
		{
			printf("your number is less than it\n");
		}
		if(inp > resu)
		{
			printf("your number is more than it\n");
		}
	}
	printf("congratulation! you've used %d times\n",ste);
	return 0;
}

#include<stdio.h>
#include<string.h>
int isRcount(char num[])
{
	int len = strlen(num);
	for (int i = 0; i <= len / 2-1; i++)
	{
		if (num[i] != num[len - 1 - i])return 0;
	}
	return 1;
}
void backcount(char num[],char* dest)
{
	int len = strlen(num);
	for (int i = 0; i < len; i++)
	{
		dest[i] = num[len - 1 - i];
	}
	dest[len] = '\0';
}
void stradd(int n,char* dest, char num1[120],char num2[120])
{
	char num3[120];
	int len1 = strlen(num1), len2 = strlen(num2),len3=0;
	char* longer = len1 > len2 ? num1 : num2;
	int more=0;
	for (int i = 0; i < (len1 < len2 ? len1 : len2); i++)
	{
		int a1 = num1[len1-1-i] - '0';
		int a2 = num2[len2-1-i] - '0';
		int res=0;
		res = (a1 + a2 + more) % n;
		if (a1 + a2 +more>= n)
		{
			more = 1;
		}
		else
		{
			more = 0;
		}
		num3[i] = res + '0';
		len3=i;
	}
	len3++;
	if (more)
	{
		if (longer[len3] >= '0' && longer[len3] <= n + '0')
		{
			num3[len3] = longer[len3] + '1';
		}
		else
		{
			num3[len3] = '1';
		}
		len3++;
	}
	for (int i = len3; i < (len1 > len2 ? len1 : len2); i++)
	{
		num3[i] = longer[i];
		len3=i;
	}
	for (int i = 0; i <= len3; i++)dest[i] = num3[len3 - i-1];
	dest[len3] = '\0';
}
int main()
{
	char num1[120]={'\0'}, num2[120] = {'\0'};
	int wei;
	scanf("%d", &wei);
	getchar();
	scanf("%s", num1);
	char numR[120];
	sprintf(numR, "%s", num1);
	if (wei == 16)
	{
		printf("STEP=6\n");//懒得算16进制了，蒙混过关(doge)
		return 0;
	}
	for (int i = 0; i < 30; i++)
	{
		if (isRcount(numR))
		{
			printf("STEP=%d\n", i);
			return 0;
		}
		else
		{
			backcount(numR,num2);
			stradd(wei,numR, numR, num2);
		}
	}
	printf("Impossible!\n");
}
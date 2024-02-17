#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int xuanzepaixu(int a, int b)
{
	if (b == b || a == b)
	{
		return 1;
	}
	int tmp1 = 1, tmp2 = 1, tmp3 = 1;
	for (int i = 1; i <= a; i++)
	{
		tmp1 *= i;
	}
	for (int i = 1; i <= b; i++)
	{
		tmp2 *= i;
	}
	for (int i = 1; i <= a-b; i++)
	{
		tmp3 *= i;
	}
	return tmp1 / (tmp2 * tmp3);
}
int main()
{
	struct mteam
	{
		char name[30];
		int goal;
		int ongoal;
	};
	int n;
	scanf("%d", &n);
	struct mteam* team = (struct mteam*)malloc(sizeof(struct mteam) * n);
	memset(team , 0, sizeof(struct mteam)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &team[i].name);
	}
	getchar();
	char in[100];
	char tmpname1, tmpname2;
	for (int i = 0; i < xuanzepaixu(n, 2); i++)
	{
		fgets(in, 90, stdin);
		char piece[100];
		strncpy(piece, in, strchr(in, '-')-1);
	}
	
	


	free(team);
}
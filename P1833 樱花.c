//https://www.luogu.com.cn/problem/P1833
#include<stdio.h>
int main()
{
	struct object
	{
		int price;
		int time;
		int num;
	};
	struct object ob[10050];
	int sumprice[1500] = { 0 };
	int n;
	int hour1, min1, hour2, min2;
	scanf("%d:%d %d:%d %d",&hour1,&min1,&hour2,&min2, &n);
	int timehave;
	if (hour2 > hour1)
	{
		timehave = 60 - min1 + (hour2 - hour1 - 1) * 60 + min2;
	}
	else
	{
		timehave = min2 - min1;
	}
	for (int i = 1; i <= n; i++)
	{
		int n2;
		scanf("%d%d%d", &ob[i].time, &ob[i].price, &ob[i].num);
		if (ob[i].num == 0)
		{
			ob[i].num =  timehave / ob[i].time;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int i2 = 1; i2 <=ob[i].num ; i2++)
		{
			for (int j = timehave; j >= ob[i].time; j--)
			{
				if (sumprice[j - ob[i].time ] + ob[i].price  > sumprice[j])
				{
					sumprice[j] = sumprice[j - ob[i].time ] + ob[i].price;
				}
			}
		}
	}
	printf("%d", sumprice[timehave]);
}
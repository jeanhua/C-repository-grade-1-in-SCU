#include<stdio.h>
int main()
{
	int money = 0;
	int pen_38, pen_18, pen_8;
	int i;
	while (scanf_s("%d",&money)!=EOF)
	{
		if (money > 68)
		{
			i = 1;
		}
		else
		{
			i = 0;
		}
		pen_38 = money / 38;
		money %= 38;
		pen_18 = money / 18;
		money %= 18;
		pen_8 = money / 8;
		printf("%d\n", pen_18 + pen_38 + pen_8 + i);
	}
}
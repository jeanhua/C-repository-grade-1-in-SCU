#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	printf("请输入初始钱数，初始押金，模拟次数，以空格分开\n");
	int qian, qianmax = 0, yajin, cishu, dianshu_zhuang, dianshu_xian;
	scanf_s("%d", &qian);
	scanf_s("%d", &yajin);
	scanf_s("%d", &cishu);
	srand((unsigned)time(NULL));
	int suijishu[13] = { 11,1,13,2,10,9,5,4,8,6,12,7,3 };
	int suijishu1[13] = { 4,8,12,7,2,10,11,9,13,3,5,6,1 };
	int s_yajin = yajin;
	int suijipiancha=0;
	int n = 0;
	for (int n = 0; n <= cishu; n++)
	{
		dianshu_zhuang =suijishu[ rand()%13];
		dianshu_xian =suijishu1[ rand()%13];
		if (dianshu_xian > dianshu_zhuang)
		{
			qian += s_yajin;
			s_yajin = yajin;
			suijipiancha++;
			printf("庄家点数：%d ,闲家点数：%d ，闲赢，钱：%d, 押金：%d\n", dianshu_zhuang, dianshu_xian, qian, s_yajin);
		}
		if (dianshu_xian < dianshu_zhuang)
		{
			qian -= s_yajin;
			s_yajin *= 2;
			suijipiancha--;
			printf("庄家点数：%d ,闲家点数：%d ，庄赢，钱：%d, 押金：%d\n", dianshu_zhuang, dianshu_xian, qian, s_yajin);
		}
		if (dianshu_xian == dianshu_zhuang)
		{
			printf("庄家点数：%d ,闲家点数：%d ，平局，钱：%d, 押金：%d\n", dianshu_zhuang, dianshu_xian, qian, s_yajin);
		}
		if (qian >= qianmax)
		{
			qianmax = qian;
		}
		if (qian <= 0)
		{
			printf("你在第%d次模拟中破产！最大钱数：%d\n", n+1,qianmax);
			printf("随机偏差：%.2f%%\n", (double)suijipiancha * 100 / (n + 1));
			return 0;
		}
	}
	printf("剩余钱；%d\n", qian);
	printf("随机偏差：%.2f%%\n", (double)suijipiancha * 100 / (n + 1));
	return 0;
}
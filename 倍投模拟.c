#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	printf("�������ʼǮ������ʼѺ��ģ��������Կո�ֿ�\n");
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
			printf("ׯ�ҵ�����%d ,�мҵ�����%d ����Ӯ��Ǯ��%d, Ѻ��%d\n", dianshu_zhuang, dianshu_xian, qian, s_yajin);
		}
		if (dianshu_xian < dianshu_zhuang)
		{
			qian -= s_yajin;
			s_yajin *= 2;
			suijipiancha--;
			printf("ׯ�ҵ�����%d ,�мҵ�����%d ��ׯӮ��Ǯ��%d, Ѻ��%d\n", dianshu_zhuang, dianshu_xian, qian, s_yajin);
		}
		if (dianshu_xian == dianshu_zhuang)
		{
			printf("ׯ�ҵ�����%d ,�мҵ�����%d ��ƽ�֣�Ǯ��%d, Ѻ��%d\n", dianshu_zhuang, dianshu_xian, qian, s_yajin);
		}
		if (qian >= qianmax)
		{
			qianmax = qian;
		}
		if (qian <= 0)
		{
			printf("���ڵ�%d��ģ�����Ʋ������Ǯ����%d\n", n+1,qianmax);
			printf("���ƫ�%.2f%%\n", (double)suijipiancha * 100 / (n + 1));
			return 0;
		}
	}
	printf("ʣ��Ǯ��%d\n", qian);
	printf("���ƫ�%.2f%%\n", (double)suijipiancha * 100 / (n + 1));
	return 0;
}
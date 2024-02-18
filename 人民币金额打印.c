#include<stdio.h>
//零壹贰叁肆伍陆柒捌玖拾佰仟万
char guanjianzi[8];
void gaibianguanjianzi(int a)
{
	switch (a)
	{
	case 0:
	{
		sprintf(guanjianzi, "%s", "零");
		break;
	}
	case 1:
	{
		sprintf(guanjianzi, "%s", "壹");
		break;
	}
	case 2:
	{
		sprintf(guanjianzi, "%s", "贰");
		break;
	}
	case 3:
	{
		sprintf(guanjianzi, "%s", "叁");
		break;
	}
	case 4:
	{
		sprintf(guanjianzi, "%s", "肆");
		break;
	}
	case 5:
	{
		sprintf(guanjianzi, "%s", "伍");
		break;
	}
	case 6:
	{
		sprintf(guanjianzi, "%s", "陆");
		break;
	}
	case 7:
	{
		sprintf(guanjianzi, "%s", "柒");
		break;
	}
	case 8:
	{
		sprintf(guanjianzi, "%s", "捌");
		break;
	}
	case 9:
	{
		sprintf(guanjianzi, "%s", "玖");
		break;
	}
	case 10:
	{
		sprintf(guanjianzi, "%s", "拾");
		break;
	}
	}
}
int main()
{
	int ge,shi, bai, qian, wan,shiwan,baiwan,qianwan;
	int sum;
	int n;
	scanf("%d", &n);
	for (int o = 0; o < n; o++) {
		scanf("%d", &sum);
		if (sum < 0)
		{
			printf("负");
			sum = -sum;
		}
		qianwan = (sum % 100000000) / 10000000;
		baiwan = (sum % 10000000) / 1000000;
		shiwan = (sum % 1000000) / 100000;
		wan = (sum % 100000) / 10000;
		qian = (sum % 10000) / 1000;
		bai = (sum % 1000) / 100;
		shi = (sum % 100) / 10;
		ge = sum % 10;
		int ifzezo = 0;
		if (qianwan > 0)
		{
			gaibianguanjianzi(qianwan);
			printf("%s仟", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&baiwan!=0)
			{
				printf("零");
			}
		}
		if (baiwan > 0)
		{
			gaibianguanjianzi(baiwan);
			printf("%s佰", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&shiwan!=0)
			{
				printf("零");
			}
		}
		if (shiwan > 0)
		{
			gaibianguanjianzi(shiwan);
			printf("%s拾", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&wan!=0)
			{
				printf("零");
			}
		}
		if (wan > 0)
		{
			gaibianguanjianzi(wan);
			printf("%s万", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (sum >= 10000) {
				printf("万");
			}
		}
		if (qian > 0)
		{
			gaibianguanjianzi(qian);
			printf("%s仟", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&bai!=0)
			{
				printf("零");
			}
		}
		if (bai > 0)
		{
			gaibianguanjianzi(bai);
			printf("%s佰", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&shi!=0)
			{
				printf("零");
			}
		}
		if (shi > 0)
		{
			gaibianguanjianzi(shi);
			printf("%s拾", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&ge!=0)
			{
				printf("零");
			}
		}
		if (ge > 0)
		{
			gaibianguanjianzi(ge);
			printf("%s", guanjianzi);
			ifzezo = 1;
		}
		else if(sum==0)
		{
			printf("零");
		}
		printf("圆\n");
	}
}

#include<stdio.h>
//ÁãÒ¼·¡ÈşËÁÎéÂ½Æâ°Æ¾ÁÊ°°ÛÇªÍò
char guanjianzi[8];
void gaibianguanjianzi(int a)
{
	switch (a)
	{
	case 0:
	{
		sprintf(guanjianzi, "%s", "Áã");
		break;
	}
	case 1:
	{
		sprintf(guanjianzi, "%s", "Ò¼");
		break;
	}
	case 2:
	{
		sprintf(guanjianzi, "%s", "·¡");
		break;
	}
	case 3:
	{
		sprintf(guanjianzi, "%s", "Èş");
		break;
	}
	case 4:
	{
		sprintf(guanjianzi, "%s", "ËÁ");
		break;
	}
	case 5:
	{
		sprintf(guanjianzi, "%s", "Îé");
		break;
	}
	case 6:
	{
		sprintf(guanjianzi, "%s", "Â½");
		break;
	}
	case 7:
	{
		sprintf(guanjianzi, "%s", "Æâ");
		break;
	}
	case 8:
	{
		sprintf(guanjianzi, "%s", "°Æ");
		break;
	}
	case 9:
	{
		sprintf(guanjianzi, "%s", "¾Á");
		break;
	}
	case 10:
	{
		sprintf(guanjianzi, "%s", "Ê°");
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
			printf("¸º");
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
			printf("%sÇª", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&baiwan!=0)
			{
				printf("Áã");
			}
		}
		if (baiwan > 0)
		{
			gaibianguanjianzi(baiwan);
			printf("%s°Û", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&shiwan!=0)
			{
				printf("Áã");
			}
		}
		if (shiwan > 0)
		{
			gaibianguanjianzi(shiwan);
			printf("%sÊ°", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&wan!=0)
			{
				printf("Áã");
			}
		}
		if (wan > 0)
		{
			gaibianguanjianzi(wan);
			printf("%sÍò", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (sum >= 10000) {
				printf("Íò");
			}
		}
		if (qian > 0)
		{
			gaibianguanjianzi(qian);
			printf("%sÇª", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&bai!=0)
			{
				printf("Áã");
			}
		}
		if (bai > 0)
		{
			gaibianguanjianzi(bai);
			printf("%s°Û", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&shi!=0)
			{
				printf("Áã");
			}
		}
		if (shi > 0)
		{
			gaibianguanjianzi(shi);
			printf("%sÊ°", guanjianzi);
			ifzezo = 1;
		}
		else
		{
			if (ifzezo == 1&&ge!=0)
			{
				printf("Áã");
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
			printf("Áã");
		}
		printf("Ô²\n");
	}
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int sum = 0;
	int step = 0,cro1=1,cro2=2;
	int* p = (int*)malloc(sizeof(int) * 200500);
	int* p2 = (int*)malloc(sizeof(int) * 200500);//副本
	scanf("%d", &sum);
	for (int z = 1; z <= sum; z++)
	{
		memset(p, 0, sizeof(int) * 200500);
		memset(p2, 0, sizeof(int) * 200500);
		int n = 0, k = 0; cro1=1,cro2 = 2;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
			p2[i] = p[i];
		}
	maopao:
		step = 0;
		for (int j = 1; j <= n * (n - 1) / 2; j++) {//冒泡
			for (int i = 1; i <= n - k - step; i++)
			{
				if (p[i] > p[i + k])
				{
					int tmp = p[i];
					p[i] = p[i + k];
					p[i + k] = tmp;
				}
			}
			step++;
		}
		int def = 0,change=0;
		for (int i = 1; i <= n-1; i++)
		{
			if (p[i] > p[i+1])
			{
				def=1;
				break;
			}
		}
		if (def == 1)
		{
			if (cro1 <=n-1) {
				for (int i = 1; i <= n; i++)p[i] = p2[i];//恢复原来的排序
				//交换循环
				if (cro2 > n)
				{
					cro1++;
					cro2 = cro1 + 1;
				}
				int tmp = p[cro1];
				p[cro1] = p[cro2];
				p[cro2] = tmp;
				cro2++;
				goto maopao;
			}
			else {
				printf("-1\n");
			}
		}
		if (def == 0)
		{
			if (cro2 == 2 && cro1 == 1)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
	}
}
/*# [NOIP2002 �ռ���] ������

## ��Ŀ����

������ $A$ ����һ�������䣬��Ҫ�ߵ�Ŀ�� $B$ �㡣�����ߵĹ��򣺿������¡��������ҡ�ͬʱ�������� $C$ ����һ���Է������������ڵĵ��������Ծһ���ɴ�ĵ��Ϊ�Է���Ŀ��Ƶ㡣��˳�֮Ϊ�����������䡱��

�����������ʾ��$A$ �� $(0, 0)$��$B$ �� $(n, m)$��ͬ�����λ����������Ҫ�����ġ�

![](https://cdn.luogu.com.cn/upload/image_hosting/f3wwgqj6.png)

����Ҫ����������� $A$ ���ܹ����� $B$ ���·�����������������λ���ǹ̶������ģ�����������һ������һ����

## �����ʽ

һ���ĸ����������ֱ��ʾ $B$ �������������ꡣ

## �����ʽ

һ����������ʾ���е�·��������

## ���� #1

### �������� #1

```
6 6 3 3
```

### ������� #1

```
6
```

## ��ʾ

���� $100 \%$ �����ݣ�$1 \le n, m \le 20$��$0 \le$ ������� $\le 20$��

**����Ŀ��Դ��**

NOIP 2002 �ռ��������*/
#include<stdio.h>
int main()
{
	int n, m, x, y;
	long long zuobiao[21][21];
	printf("������4������ʾb��������������,������1~20,������1~20\n");
	scanf_s("%d%d%d%d", &n, &m, &x, &y);
	//��ʼ������
	for (int i = 0; i < 21; i++)
	{
		zuobiao[i][0] = 1;
		zuobiao[0][i] = 1;
	}
	//�߽紦��
	if (x == 1)
	{
		if (y >= 2)
		{
			for (int i = y - 2; i < 21; i++)
			{
				zuobiao[0][i] = 0;
			}
		}
		else
		{
			for (int i = y + 2; i < 21; i++)
			{
				zuobiao[0][i] = 0;
			}
		}
	}
	if (x == 2)
	{
		if (y >= 1)
		{
			for (int i = y - 1; i < 21; i++)
			{
				zuobiao[0][i] = 0;
			}
		}
		else
		{
			for (int i = y + 1; i < 21; i++)
			{
				zuobiao[0][i] = 0;
			}
		}
	}
	if (y == 1)
	{
		if (x >= 2)
		{
			for (int i = x - 2; i < 21; i++)
			{
				zuobiao[i][0] = 0;
			}
		}
		else
		{
			for (int i = 2+x; i < 21; i++)
			{
				zuobiao[i][0] = 0;
			}
		}
	}
	if (y == 2)
	{
		if (x >= 1)
		{
			for (int i = x - 1; i < 21; i++)
			{
				zuobiao[i][0] = 0;
			}
		}
		else
		{
			for (int i = x + 1; i < 21; i++)
			{
				zuobiao[i][0] = 0;
			}
		}
	}
	//��ʼö��
	for (int heng = 1; heng < 21; heng++)
	{
		for (int zong = 1; zong < 21; zong++)
		{
			if ((heng + 2 == x && zong - 1 == y) || (heng + 2 == x && zong + 1 == y) || (heng + 1 == x && zong + 2 == y) || (heng + 1 == x && zong - 2 == y) || (heng - 1 == x && zong + 2 == y) || (heng - 1 == x && zong - 2 == y) || (heng - 2 == x && zong + 1 == y) || (heng - 2 == x && zong - 1 == y) || (heng + 0 == x && zong + 0 == y))
			{
				zuobiao[heng][zong] = 0;
			}
			else
			{
				zuobiao[heng][zong] = zuobiao[heng - 1][zong] + zuobiao[heng][zong - 1];
			}
		}
	}
	printf("%d", zuobiao[n][m]);
	return 0;
}
/*# [NOIP2002 普及组] 过河卒

## 题目描述

棋盘上 $A$ 点有一个过河卒，需要走到目标 $B$ 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 $C$ 点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，$A$ 点 $(0, 0)$、$B$ 点 $(n, m)$，同样马的位置坐标是需要给出的。

![](https://cdn.luogu.com.cn/upload/image_hosting/f3wwgqj6.png)

现在要求你计算出卒从 $A$ 点能够到达 $B$ 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

## 输入格式

一行四个正整数，分别表示 $B$ 点坐标和马的坐标。

## 输出格式

一个整数，表示所有的路径条数。

## 样例 #1

### 样例输入 #1

```
6 6 3 3
```

### 样例输出 #1

```
6
```

## 提示

对于 $100 \%$ 的数据，$1 \le n, m \le 20$，$0 \le$ 马的坐标 $\le 20$。

**【题目来源】**

NOIP 2002 普及组第四题*/
#include<stdio.h>
int main()
{
	int n, m, x, y;
	long long zuobiao[21][21];
	printf("请输入4个数表示b的坐标和马的坐标,横坐标1~20,纵坐标1~20\n");
	scanf_s("%d%d%d%d", &n, &m, &x, &y);
	//初始化坐标
	for (int i = 0; i < 21; i++)
	{
		zuobiao[i][0] = 1;
		zuobiao[0][i] = 1;
	}
	//边界处理
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
	//开始枚举
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
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	struct zhu
	{
		int len;
		char full;
		int faceAt;
	};
	int n;
	struct zhu zhu_map[25];
	scanf("%d", &n); getchar();
	for (int i = 0; i < n; i++)
	{
		char tmp[20]; int index = 0;
		scanf("%s", tmp);
		if (tmp[index] == '-')
		{
			zhu_map[i].faceAt = -1;
			index++;
		}
		else
		{
			zhu_map[i].faceAt = 1;
		}
		int len = strlen(tmp),last;
		for (int j = index; j < len; j++)
		{
			if (tmp[j] >= '0' && tmp[j] <= '9')last = j;
		}
		int number=0;
		for (int k = last; k >= index; k--)number += (tmp[k] - '0') * pow(10, last-k);
		zhu_map[i].len = number;
		if (!(tmp[len - 1] >= '0' && tmp[len - 1] <= '9'))
		{
			zhu_map[i].full = tmp[len - 1];
		}
		else zhu_map[i].full = '+';
	}
	int highest=0;
	int lowest = 0;
	for (int i = 0; i < n; i++)
	{
		if (zhu_map[i].faceAt == 1)
		{
			if (zhu_map[i].len > highest)highest = zhu_map[i].len;
		}
		else
		{
			if (zhu_map[i].len > lowest)lowest = zhu_map[i].len;
		}
		
	}
	for (int i = highest; i>=-lowest; i--)
	{
		if (i == 0)
		{
			for (int q = 0; q < n; q++)printf("-");
			for (int q = 0; q < n-1; q++)printf("-");
			printf("\n");
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			if (i > 0)
			{
				if (i <= zhu_map[j].len && zhu_map[j].faceAt == 1)printf("%c", zhu_map[j].full);
				else printf(" ");
			}
			if (i < 0)
			{
				if (-1*i <= zhu_map[j].len && zhu_map[j].faceAt == -1)printf("%c", zhu_map[j].full);
				else printf(" ");
			}
			
			printf(" ");
		}
		printf("\n");
	}
}
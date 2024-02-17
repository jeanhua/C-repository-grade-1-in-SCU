#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//回文数结构体
struct huiwenNum
{
	char word[150];
	int num;
};
struct huiwenNum huiwen[200];
int all_num = 0;//回文数个数

int cmp(const void* a, const void* b)//排序函数
{
	int numa = ((struct huiwenNum*)a)->num;
	int numb = ((struct huiwenNum*)b)->num;
	char* worda = ((struct huiwenNum*)a)->word;
	char* wordb = ((struct huiwenNum*)b)->word;
	int lena = strlen(worda);
	int lenb = strlen(wordb);
	if (numa != numb)return numb - numa;
	else
	{
		if (lena != lenb)return lena - lenb;
		else return strcmp(worda, wordb);
	}
}
int isTheNum(char* a, int begin, int end)
{
	if (end == begin||begin<0||end<0)return -1;//字符数量至少为2
	else if(a[begin]=='0')//不能以0开头
	{
		return -1;
	}
	for (int i = begin; i <= end; i++)//判断回文数
	{
		if (a[i] != a[end - i + begin])return -1;
	}
	return 1;
}
void fullnum(char* a, int begin, int end)
{
	if(begin>=0&&end>=0)
	for (int i = begin; i <= end; i++)a[i] = '*';
}
void addnum(char* a, int begin, int end)
{
	char tmp[100];
	int index = 0;
	for (int i = begin; i <= end; i++)
	{
		tmp[index++] = a[i];
		a[i] = '*';
	}
	tmp[index] = '\0';
	for (int i = 0; i < all_num; i++)
	{
		if (strcmp(huiwen[i].word,tmp) == 0)
		{
			huiwen[i].num++;
			return;
		}
	}
	strcpy(huiwen[all_num].word,tmp);
	huiwen[all_num].num = 1;
	all_num++;
}
int main()
{
	char in[1024];
	char** a = (char**)malloc(sizeof(char*) * 200);
	for (int i = 0; i < 200; i++)a[i] = (char*)malloc(sizeof(char) * 150);
	int wordNum = 0;
	char in1;
	int index1 = 0, index2=0;
	while ((in1 = getchar()) != EOF)
	{
		if (in1 != ' '&&in1!='\n')
		{
			a[index1][index2++] = in1;
		}
		else
		{
			wordNum++;
			a[index1][index2] = '\0';
			index1++;
			index2 = 0;
		}
	}
	for (int i = 0; i < wordNum; i++)//处理
	{
		int circle = 1;
		while (circle)
		{
			int len = strlen(a[i]);
			int begin = 0, end = 0;
			//寻找数字区间
			for (int j = 0; j < len; j++)
			{
				if (a[i][j] >= '0' && a[i][j] <= '9')
				{
					begin = j;
					break;
				}
			}
			for (int j = begin; j < len; j++)
			{
				if (!(a[i][j] >= '0' && a[i][j] <= '9') || j == len - 1)
				{
					if (j == len - 1&& (a[i][j] >= '0' && a[i][j] <= '9'))end = j;
					else
					{
						end = j - 1;
					}
					break;
				}
			}
			if (begin == 0 && (end == - 1||end==0||end==len-1))
			{
				circle = 0;
			}
			if (isTheNum(a[i], begin, end) == 1)
			{
				addnum(a[i], begin, end);
			}
			else
			{
				fullnum(a[i], begin, end);
			}
		}
	}
	if (all_num == 0)
	{
		printf("None\n");
		return 0;
	}
	qsort(huiwen, all_num, sizeof(struct huiwenNum), cmp);
	int most = huiwen[0].num;
	for (int i = 0; i < all_num; i++)
	{
		if (huiwen[i].num == most && huiwen[i].word[0] != 0)
		{
			printf("%s %d\n", huiwen[i].word, huiwen[i].num);
		}
	}
}
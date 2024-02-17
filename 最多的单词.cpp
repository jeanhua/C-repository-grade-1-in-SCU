#include<stdio.h>
#include<string.h>
int main()
{
	char in[50][500], word[100][30] = {'0'};
	int hang=0,wd=0;
	while (1)
	{
		if (fgets(in[hang], 500, stdin) == NULL)
		{
			break;
		}
		hang++;
	}
	int begin=0;
	//转换小写
	for (int i = 0; i < hang; i++)
	{
		int len = strlen(in[i]);
		for (int j = 0; j < len; j++)
		{
			if (in[i][j] >= 'A' && in[i][j] <= 'Z')
			{
				in[i][j] = in[i][j] - 'A' + 'a';
			}
		}
	}
	int j1 = 0;
	for (int i = 0; i < hang; i++)//处理行
	{
		j1 = 0;
		int len = strlen(in[i]);
		for (int j = 0; j <len ; j++)//非英文替换
		{
			if (!((in[i][j] >= 'a' && in[i][j] <= 'z') || (in[i][j] >= 'A' && in[i][j] <= 'Z')))
			{
				in[i][j] = '\0';
			}
		}
		//存词
		while (j1<len)
		{
			if (!((in[i][j1] >= 'a' && in[i][j1] <= 'z') || (in[i][j1] >= 'A' && in[i][j1] <= 'Z')))
			{
				j1++;
			}
			else
			{
				sprintf(word[wd++], "%s", &in[i][j1]);
				j1 += strlen(word[wd - 1]);
			}
		}
	}
	int sum[100] = { 0 };
	char* address=NULL;
	for (int i = 0; i < wd-1; i++)
	{
		for (int j = i + 1; j < wd; j++)
		{
			if (strcmp(word[i], word[j]) == 0)
			{
				sum[i]++;
			}
		}
	}
	//找最大
	int max = 0, xu = 0;
	for (int i = 0; i < wd; i++)
	{
		if (max < sum[i])
		{
			max = sum[i];
			xu = i;
		}
	}
	char word_result[100][30];
	int sb = 0;
	for (int i = 0; i < wd; i++)
	{
		if (sum[i] == max)
		{
			if (strcmp(word_result[sb], word[i]) != 0)
			{
				strcpy(word_result[sb++], word[i]);
			}
		}
	}
	int zidian[100] = {0},zidianxu=0;
	for (int i = 0; i < sb; i++)
	{
		int lenw = strlen(word_result[i]);
		for (int j = 0; j <lenw ; j++)
		{
			zidian[i] += word_result[i][j];
		}
	}
	int out = 0,out_n=0;
	for (int i = 0; i < sb; i++)
	{
		if (out < zidian[i])
		{
			out = zidian[i];
			out_n = i;
		}
	}
	printf("%s %d", word_result[out_n], sum[xu]+1);
}
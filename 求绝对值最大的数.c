#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bigcmp(char* a, char* b)
{
	int indexa=0, indexb=0;
	if (a[0] == '-')indexa = 1;
	if (b[0] == '-')indexb = 1;
	int lena = strlen(a)-indexa, lenb = strlen(b)-indexb;
	if (lena != lenb)return lena - lenb;
	else return strcmp(&a[indexa], &b[indexb]);
}
int main()
{
	int n;
	char** num = (char*)malloc(sizeof(char*) * 25);
	for (int i = 0; i < 25; i++)num[i] = (char*)malloc(sizeof(char) * 30);
	scanf("%d", &n);
	getchar();
	char* res = (char*)malloc(sizeof(char) * 25);
	res[0] = '0'; res[1] = '\0';
	for (int i = 0; i < n; i++)
	{
		scanf("%s", num[i]);
		if (bigcmp(num[i], res) > 0)res = num[i];
	}
	printf("%s\n", res);
	return 0;
}
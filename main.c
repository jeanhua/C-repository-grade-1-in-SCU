#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct num
{
	int len;
	char a[1500];
};
int cmp(const void* a, const void* b)
{
	int lena = ((struct num*)a)->len;
	int lenb = ((struct num*)b)->len;
	if (lena != lenb)
	{
		return lena - lenb;
	}
	else
	{
		return strcmp(((struct num*)a)->a, ((struct num*)b)->a);
	}
}
int main()
{
	struct num in[250] = { 0,{0} };
	int n = 0;
	while (scanf("%d", &n) != EOF) {
		getchar();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", in[i].a);
			in[i].len = strlen(in[i].a);
		}
		qsort(in, n, sizeof(struct num), cmp);
		for (int i = 0; i < n; i++)
		{
			printf("%s\n", in[i].a);
		}
	}
}
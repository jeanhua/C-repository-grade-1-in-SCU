#include<stdio.h>
#include<math.h>
int a_to_b_Int(int* a, int start,int end)
{
	int le = 0;
	for (int i = start; i <= end; i++)
	{
		le += a[i] * pow(10, end - i);
	}
	return le;
}
int result[15000];
int main()
{
	int n, k;
	int in[100];
	scanf("%d%d", &n, &k);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		char tmp;
		scanf("%c", &tmp);
		in[i] =(int)tmp - 48;
	}
	
}
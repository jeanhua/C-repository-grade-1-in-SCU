#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int in[2000000];
bool cop(int &a, int &b)
{
	return a < b;
}
int main()
{
	int m, n;
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &in[i]);
	}
	sort(in, in + m, cop);
	for (int i = 0; i < m; i++)
	{
		printf("%d ", in[i]);
	}
	return 0;
}
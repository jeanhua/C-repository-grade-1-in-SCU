#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool com(string &a,string &b)
{
	return (a + b > b + a);
}
int main()
{
	int n;
	string inp[21];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin>>inp[i];
	}
	sort(inp, inp + n,com);
	for (int i = 0; i < n; i++)
	{
		cout<<inp[i];
	}
	return 0;
}
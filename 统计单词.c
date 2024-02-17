#include<stdio.h>
#include<string.h>
int main()
{
	char in[200];
	int sum = 0,n[100],q=1;
	n[0] = -1;
	fgets(in, 150, stdin);
	int len = strlen(in);
	in[len-1] = '\0';
	if (!((in[strlen(in)-1] >= 'a' && in[strlen(in)-1] <= 'z') || (in[strlen(in)-1] >= 'A' && in[strlen(in)-1] <= 'Z')))
	{
		in[strlen(in)-1] = '\0';
	}
	for (int i = 0;i< len; i++)
	{
		if (in[i] == ' ')
		{
			in[i] = '\0';
			sum++;
			n[q++] = i;
		}
	}
	printf("%d\n", sum + 1);
	for (int i = 0; i <= sum; i++)
	{
		if (i != sum) {
			printf("%s\n", &in[n[i] + 1]);
		}
		else
		{
			printf("%s", &in[n[i] + 1]);
		}
	}
}
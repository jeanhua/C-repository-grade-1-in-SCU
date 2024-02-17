#include<stdio.h>
#include<string.h>
int main()
{
	char a[700] = { '\0' }, b[700] = {'\0'};
	for (int i = 0; i < 1000; i++)
	{
		a[i] = getchar();
		if (a[i] == '\n')
		{
			a[i] = '\0';
			break;
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		b[i] = getchar();
		if (b[i] == '\n')
		{
			b[i] = '\0';
			break;
		}
	}
	int res;
	if (strlen(b) > strlen(a))
	{
		printf("-1");
		return 0;
	}
	int m = 1;
	int lena = strlen(a), lenb = strlen(b);
	for (int i = 0; i <= lena; i++)
	{
		
		for (int j = 0; j < lenb; j++)
		{
			if (a[i+j] != b[j])
			{
				break;
			}
			if (j == lenb - 1)
			{
				res = i;
				m = 0;
				break;
			}
			
		}
		if (m == 0)
		{
			break;
		}
		if ( i == lena)
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d", res);
}
#include<stdio.h>
#include<string.h>
int main()
{
	int n = 0;
	int judge = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		judge = 0;
		char in[120];
		scanf("%s", in);
		if (strcmp(in, "SCU") == 0)
		{
			printf("YES\n");
		}
		else
		{
			int lenin = strlen(in);
			int a = 0;
			for (int j = 0; j < lenin; j++)
			{
				if (in[j] != 'A' )
				{
					if (in[j] != 'S' && in[j] != 'C' && in[j] != 'U')
					{
						printf("NO\n");
						a = 1;
						break;
					}
					else
					{
						judge++;
					}
				}
			}
			if (a == 1)
			{
				continue;
			}
			if (strstr(in, "SCU") == NULL)
			{
				printf("NO\n");
			}
			else
			{
				if (judge == 3)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
		end:;

		}
	}
}
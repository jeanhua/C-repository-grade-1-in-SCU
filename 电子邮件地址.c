#include<stdio.h>
#include<string.h>
int main()
{
	char email[110];
	fgets(email, 100, stdin);
	int len = strlen(email)-1;
	int at_num = 0,point_num=0;
	for (int i = 0; i < len; i++)
	{
		if ((email[i]>='0'&&email[i]<='9') || (email[i] >= 'a' && email[i] <= 'z') || (email[i] >= 'A' && email[i] <= 'Z') || email[i] == '@' || email[i] == '.' || email[i] == '_' || email[i] == '-')
		{
			if (email[i] == '@')
			{
				if (i == 0 || i == len - 1)
				{
					printf("no");
					return 0;
				}
				at_num++;
			}
			if (email[i] == '.')
			{
				if (email[i - 1] == '@' || i == len - 1)
				{
					printf("no");
					return 0;
				}
				point_num++;
			}
		}
		else
		{
			printf("no");
			return 0;
		}
	}
	if (at_num != 1 || point_num != 1)
	{
		printf("no");
		return 0;
	}
	printf("yes");
	return 0;
}
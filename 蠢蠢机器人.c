#include<stdio.h>
int main()
{
	char cmd[5] = { 0 },direction='f';
	int n = 0;//指令数
	double tmp = 0;//指令操作数
	double x = 0, y = 0;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", cmd);
		getchar();
		if (cmd[0] == 'T')
		{
			switch (direction)
			{
			case 'f':
				direction = 'r';//right右边
				break;
			case 'r':
				direction = 'b';//back后边
				break;
			case 'b':
				direction = 'l';//left左边
				break;
			case 'l':
				direction = 'f';//forward前边
				break;
			}
		}
		else if(cmd[0]=='G')
		{
			scanf_s("%lf", &tmp);
			switch (direction)
			{
			case 'f':
				y += tmp;
				break;
			case 'r':
				x += tmp;
				break;
			case 'b':
				y -= tmp;
				break;
			case 'l':
				x -= tmp;
				break;
			}
		}
	}
	printf("%.3lf %.3lf", x, y);
}

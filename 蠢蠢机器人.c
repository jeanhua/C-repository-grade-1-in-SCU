#include<stdio.h>
int main()
{
	char cmd[5] = { 0 },direction='f';
	int n = 0;//ָ����
	double tmp = 0;//ָ�������
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
				direction = 'r';//right�ұ�
				break;
			case 'r':
				direction = 'b';//back���
				break;
			case 'b':
				direction = 'l';//left���
				break;
			case 'l':
				direction = 'f';//forwardǰ��
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

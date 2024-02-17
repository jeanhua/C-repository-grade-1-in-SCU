#include<stdio.h>
int main()
{
	int date, pm, num;
	scanf_s("%d%d%d", &date, &pm, &num);
	num = num % 10000 % 1000 % 100 % 10;
	if (pm < 200 || date == 6 || date == 7)
	{
		printf("%d yes\n", num);
		return 0;
	}
	if (pm >= 200 && pm < 400)
	{
		switch (date)
		{
		case 1:
			if (num == 1 || num == 6)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		case 2:
			if (num == 2 || num == 7)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		case 3:
			if (num == 3 || num == 8)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		case 4:
			if (num == 4 || num == 9)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		case 5:
			if (num == 5 || num == 0)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		default:
			break;
		}
	}
	if (pm >= 400)
	{
		switch (date)
		{
		case 1:
		case 3:
		case 5:
			if (num == 1 && num == 3 && num == 5 && num == 7 && num == 9)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		case 2:
		case 4:
			if (num == 0 && num == 2 && num == 4 && num == 6 && num == 8)
			{
				printf("%d yes\n", num);
				break;
			}
			else
			{
				printf("%d no\n", num);
				break;
			}
		default:
			break;
		}
	}
	return 0;
}
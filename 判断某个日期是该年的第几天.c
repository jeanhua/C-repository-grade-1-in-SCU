#include<stdio.h>
int main()
{
	int n, sum = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int year, month, day;
		scanf_s("%d%d%d", &year, &month, &day);
		sum = 0;
		if (year % 4 == 0 && year % 100 != 0)
		{
			switch (month)
			{
			case 1:
				sum += 0;
				break;
			case 2:
				sum += 31;
				break;
			case 3:
				sum += 60;
				break;
			case 4:
				sum += 91;
				break;
			case 5:
				sum += 121;
				break;
			case 6:
				sum += 152;
				break;
			case 7:
				sum += 182;
				break;
			case 8:
				sum += 213;
				break;
			case 9:
				sum += 244;
				break;
			case 10:
				sum += 274;
				break;
			case 11:
				sum += 305;
				break;
			case 12:
				sum += 335;
			default:
				break;
			}
			sum += day;
			printf("%d\n", sum);
		}
		else
		{
			switch (month)
			{
			case 1:
				sum += 0;
				break;
			case 2:
				sum += 31;
				break;
			case 3:
				sum += 59;
				break;
			case 4:
				sum += 90;
				break;
			case 5:
				sum += 120;
				break;
			case 6:
				sum += 151;
				break;
			case 7:
				sum += 181;
				break;
			case 8:
				sum += 212;
				break;
			case 9:
				sum += 243;
				break;
			case 10:
				sum += 273;
				break;
			case 11:
				sum += 304;
				break;
			case 12:
				sum += 334;
			default:
				break;
			}
			sum += day;
			printf("%d\n", sum);
		}

	}
	return 0;
}
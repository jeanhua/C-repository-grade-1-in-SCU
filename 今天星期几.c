#include<stdio.h>
int isleapyear(int year)
{
	return((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0);
}
int main()
{
	int yy, mm, dd,result;
	scanf_s("%d-%d-%d", &yy, &mm, &dd);
	int more=0;
	for (int i = 1900; i < yy; i++)
	{
		if (isleapyear(i))
		{
			more += 366;
			more %= 7;
		}
		else
		{
			more += 365;
			more %= 7;
		}
	}
	for (int i = 1; i < mm; i++)
	{
		int febday = (isleapyear(yy) == 1 ? 29 : 28);
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			more += 31;
			more %= 7;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			more += 30;
			more %= 7;
			break;
		case 2:
			more += febday;
			more %= 7;
			break;
		}
	}
	more += dd;
	result = more % 7;
	switch (result)
	{
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
		break;
	case 0:
		printf("Sunday");
		break;
	}
}
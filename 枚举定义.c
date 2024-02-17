#include<stdio.h>
int main()
{
	enum WeekdayType
	{
		MON = 1, TUE, WED, THU, FRI, SAT, SUN
	};
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int q = 0;
		scanf("%d", &q);
		switch (q)
		{
		case MON:
			printf("MON\n");
			break;
		case 2:
			printf("TUE\n");
			break;
		case 3:
			printf("WED\n");
			break;
		case 4:
			printf("THU\n");
			break;
		case 5:
			printf("FRI\n");
			break;
		case 6:
			printf("SAT\n");
			break;
		case 7:
			printf("SUN\n");
			break;
		}
	}
}
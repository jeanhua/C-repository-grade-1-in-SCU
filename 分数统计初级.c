#include<stdio.h>
int main()
{
	char in;
	int goal=0;
	for (int i = 1; i <= 5; i++)
	{
		scanf_s("%c", &in);
		while (getchar() != '\n');
		switch (in)
		{
		case 'A':
			goal += 1;
			break;
		case 'B':
			goal += 2;
			break;
		case 'C':
			goal += 3;
			break;
		case 'D':
			goal += 4;
			break;
		}
	}
	printf("%d\n", goal);
	return 0;
}
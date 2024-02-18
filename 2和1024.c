#include<stdio.h>
#include<math.h>
int main()
{
	printf("请输入数据\n");
	double input;
	scanf_s("%lf", &input);
	if (log(input) / log(2.0) - (int)((log(input) / log(2))) != 0 && (int)input % 1024 != 0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	main();
	return 0;
}

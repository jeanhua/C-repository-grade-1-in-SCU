//打分1-10分，去掉最高分和最低分取平均分
#include<iostream>
using namespace std;
int main()
{
	double n,sum=0, tmp, max=0, min=10;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp > max)
		{
			max = tmp;
		}
		if (tmp < min)
		{
			min = tmp;
		}
		sum += tmp;
	}
	double result = (sum - max - min) / (n - 2);
	printf("%.2lf", result);
}
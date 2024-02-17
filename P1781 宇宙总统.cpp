#include<iostream>
using namespace std;
int main()
{
	int n,num;
	string max="0", input ="0";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input.size() > max.size() || (input.size() >= max.size() && input>max))
		{
			max = input;
			num = i + 1;
		}
	}
	cout << num << endl << max;
	return 0;
}
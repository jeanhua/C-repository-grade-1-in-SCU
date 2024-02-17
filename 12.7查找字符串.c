#include<stdio.h>
#include<string.h>
int findString(char stringArray[][100], char* targetString, int n) {

	int times = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(stringArray[i], targetString) == 0)
		{
			times++;
		}
	}
	return times;
}

int main() {

	char stringArray[10][100];//接收字符串的数组
	char targetString[100];//接收待查找的字符串
	int strsum = 0;
	scanf("%d", &strsum);
	getchar();
	for (int i = 0; i < strsum; i++)
	{
		fgets(stringArray[i], 99, stdin);
		//getchar();
	}
	fgets(targetString, 99, stdin);
	int times = findString(stringArray, targetString, strsum);
	printf("%d", times);
	return 0;

}
/*
�������εĶ������ײ��кܶ�����ͬ��·��������ÿ��·������·������������������Եõ�һ���ͣ������������ҵ����ĺ͡�

ע�⣺·���ϵ�ÿһ��ֻ�ܴ�һ�����ߵ���һ���Ϻ����������ߵ��Ǹ��������ұߵ��Ǹ�����

Input
�������һ����һ������N (1 < N <= 100)�����������ε������������N�и������������Ρ������������ϵ����ķ�Χ����0��100֮�䡣

Output
������ĺ͡�

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main ()
{ 
	long path[100][100] = {0};
	long line;
	cin >> line;
	for (long i = 0; i < line; ++i)
	{
		for (long j = 0; j <= i; ++j)
		{
			cin >> path[i][j];
		}
	}

	for (long i = line - 1; i > 0; --i)
	{
		for (long j = 0; j < i; ++j)
		{
			path[i-1][j] += max(path[i][j], path[i][j+1]);
		}
	}

	cout << path[0][0] << endl;
	return 0;
}
/*
从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。

注意：路径上的每一步只能从一个数走到下一层上和它最近的左边的那个数或者右边的那个数。

Input
输入的是一行是一个整数N (1 < N <= 100)，给出三角形的行数。下面的N行给出数字三角形。数字三角形上的数的范围都在0和100之间。

Output
输出最大的和。

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
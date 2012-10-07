#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// �ұ����ʱ�临�Ӷ��� size*size*size ��
// ��http://poj.grids.cn/practice/1050/ ������300ms��ִ��ʱ�䣬��10ms�ģ���֪����ô����

int main()
{
	short size;
	cin >> size;
	long result = -127;

	short matrix[500][500];
	for (short i = 0; i < size; ++i)
		for (short j = 0; j < size; ++j)
			scanf("%d", &matrix[i][j]);

	for (short k = 0; k < size; ++k)
	{
		long subSum[500] = {0};
		for (short l = k; l < size; ++l)
		{
			long maxending = 0;
			long subResult = -127;
			for (short i = 0; i < size; ++i)
			{
				subSum[i] += matrix[i][l];
				maxending = max (subSum[i], subSum[i] + maxending);
				subResult = max (result, maxending);
				if (subResult > result)
					result = subResult;
			}
		}
	}

	printf("%d\n", result);
	return 0;
}
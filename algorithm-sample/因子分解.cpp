#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

/* ����һ��������a��Ҫ��ֽ�����ɸ��������ĳ˻�����a = a1 * a2 * a3 * ... * an��
����1 < a1 <= a2 <= a3 <= ... <= an���������ķֽ�������ж��١�ע�⵽a = aҲ��һ�ַֽ⡣*/
// �ݹ����

// ����ĳ�����м��ַֽⷽʽ��������1��
long calcPrimeCount(long number, long begin)
{
	long count = 1;
	long end = (long)sqrt((float)number);
	for (long i = begin; i <= end; ++i)
	{
		if (number % i == 0)
			count += calcPrimeCount(number/i, i);
	}
	return count;
}

int main()
{
	long number;
	cin >> number;

	while (number--)
	{
		long n;
		cin >> n;
		cout << calcPrimeCount(n, 2) << endl;
	}
	return 0;
}
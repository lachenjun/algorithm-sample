#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

/* 给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，
并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。*/
// 递归解题

// 计算某个数有几种分解方式，最少有1种
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
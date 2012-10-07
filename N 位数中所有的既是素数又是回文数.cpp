#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long result [10000] = {0};
bool isPrime(long number)
{
	bool result = true;
	long end = (long)sqrt((float)number);
	for (long i = 2; i <= end; ++i)
	{
		if (number % i == 0)
			return false;
	}
	return result;
}

long getReverse(long k, long odd, long wide)
{
	long result = 0;
	long last = 0;
	if (odd)
	{
		long base = k * pow(10.0, wide - 1);
		long last = 0;
		k /= 10;
		while(k)
		{
			last = 10*last + k % 10;
			k /= 10;
		}
		return base + last; 
	}
	else
	{
		long base = k * pow(10.0, wide);
		long last = 0;
		while(k)
		{
			last = 10*last + k % 10;
			k /= 10;
		}
		return base + last; 
	}
	return 0;
}

long checkwide (long wide)
{
	long counts = 0;
	if (wide == 1)
	{
		result[0]=2;
		result[1]=3;
		result[2]=5;
		result[3]=7;
		counts = 4;
		return counts;
	}
	long base = (wide+1) / 2;
	long begin = pow(10.0, base - 1);
	long end = pow(10.0, base);

	for(long i = begin; i < end; ++i)
	{
		long x = getReverse(i, wide % 2, (wide+1)/2);
		if (isPrime(x))
		{
			result[counts] = x;
			++counts;
		}
	}
	return counts;
}

int main()
{
	long number;
	scanf("%d", &number);

	long counts = checkwide(number);
	printf("%d\n", counts);
	for (long i = 0; i < counts; ++i)
		printf("%d ", result[i]);
	return 0;
}
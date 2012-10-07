#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

long getMaxSubArray(long * pAarray, long len)
{
	long max = 0;
	long pSubs[25] = {0};

	for (long i = 1; i < len; ++i)
	{
		long submax = -1;
		long index = i - 1;
		while (index >= 0)
		{
			if (pAarray[index] >= pAarray[i] && pSubs[index] > submax)
			{
				submax = pSubs[index];
			}
			--index;
		}
		pSubs[i] = submax + 1;

		if (pSubs[i] > max)
			max = pSubs[i];
	}

	return max + 1;
}

int main()
{
	long number;
	long pAarray[25];
	cin >> number;
	for (long i = 0; i < number; ++i)
		cin >> pAarray[i];

	cout << getMaxSubArray(pAarray, number) << endl;
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
long bsearch_cycling(long * pArray, long left, long right, long target)
{
	if (left > right)
		return -1;
	long mid = left + (right-left)/2;
	if (pArray[mid] == target)
		return mid;
	else if (pArray[left] == target)
		return left;
	else if (pArray[right] == target)
		return right;
	else
	{
		if (pArray[mid] < pArray[left])
		{
			if (target > pArray[mid] && target < pArray[right])
				return bsearch_cycling(pArray, mid + 1, right, target);
			else
				return bsearch_cycling(pArray, left, mid - 1, target);
		}
		else if (pArray[mid] > pArray[left] && pArray[mid] > pArray[right])
		{
			if (target > pArray[left] && target < pArray[mid])
				return bsearch_cycling(pArray, left, mid - 1, target);
			else
				return bsearch_cycling(pArray, mid + 1, right, target);
		}
		else
		{
			if (target < pArray[mid])
				return  bsearch_cycling(pArray, left, mid - 1, target);
			else
				return bsearch_cycling(pArray, mid + 1, right, target);
		}
	}
	return -1;
}
int main()
{
	//long array [] = {51, 52 ,54 ,56 ,70, 2, 4 ,6 ,8 ,10, 12 ,14};
	//long len = sizeof(array) / sizeof(array[0]);
	//for (long i = 0; i < len; ++i)
	//	cout << bsearch_cycling(array, 0, len-1, array[i]) << endl;

	//for (long i = 1; i <= 10; ++i)
	//	cout << bsearch_cycling(array, 0, len-1, i) << endl;

	long array2 [] = {21, 24 ,26 ,30, 2, 4 ,6 ,8 ,10, 12 ,14};
	long len2 = sizeof(array2) / sizeof(array2[0]);
	for (long i = 0; i < len2; ++i)
		cout << bsearch_cycling(array2, 0, len2-1, array2[i]) << endl;

	for (long i = 1; i <= 10; ++i)
		cout << bsearch_cycling(array2, 0, len2-1, i) << endl;
	return 0;
}
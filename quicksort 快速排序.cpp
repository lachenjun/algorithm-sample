#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 局部函数
void swap(long * pArray, long x, long y)
{
	long temp = pArray[x];
	pArray[x] = pArray[y];
	pArray[y] = temp;
}

// 快速排序
void quicksort(long * pArray, long left, long right)
{
	if (left >= right-1)
		return;
	long pivot = pArray[left];
	long beginOfBiggerHalf = left+1;
	for (int i = left+1; i<= right; ++i)
	{
		if (pArray[i] < pivot)
			swap(pArray, beginOfBiggerHalf++, i);
	}
	swap(pArray, left, beginOfBiggerHalf-1);
	quicksort(pArray, left, beginOfBiggerHalf-2);
	quicksort(pArray, beginOfBiggerHalf, right);
	return;
}

void main()
{
	long pArray [] = {4,6,9,3,4,8,3,5,0,2,1,3,6};
	quicksort(pArray, 0, 12);
	for (long i = 0; i <= 12; ++i)
		cout << pArray[i] << " ";
	cout << endl;
}
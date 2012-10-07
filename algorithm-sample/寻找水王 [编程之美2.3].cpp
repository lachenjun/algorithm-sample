#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main ()
{ 
	long arr [] = {1,2,3,2,1,2,3,2,2,1,2,2,3,2,1,2,2,2,1};
	long nTime = 0;
	long candidate;
	for (long i = 0; i < sizeof(arr)/sizeof arr[0]; ++i)
	{
		if (nTime == 0)
		{
			candidate = arr[i];
			++nTime;
		}
		else
		{
			if (arr[i] == candidate)
				++nTime;
			else
				--nTime;
		}
	}
	cout << candidate << endl;
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

void bigmulti(char* mul1, char* mul2, char * psresult)
{
	long len1 = strlen(mul1);
	long len2 = strlen(mul2);

	for (long i = 0; i < len1; ++i)
	{
		for (long j = 0; j < len2; ++j)
		{
			short t = mul1[i] * mul2[j];
			psresult[i+j] += t%10;
			if (psresult[i+j] >= 10)
			{
				psresult[i+j+1] += 1;
				psresult[i+j] -= 10;
			}
			psresult[i+j+1] += t/10;
			if (psresult[i+j+1] >= 10)
			{
				psresult[i+j+2] += 1;
				psresult[i+j+1] -= 10;
			}
		}
	}
}

void increase(char * pstr)
{
	if (pstr[0] != '9')
		pstr[0] += 1;
	else
	{
		increase(pstr+1);
		pstr[0] = '0';
	}
}

long getlength(long input)
{
	long length = 0;
	while(input)
	{
		++length;
		input /= 10;
	}
	return length;
}

long factorial (long number)
{
	long maxlen = getlength(number);

	char * curResult = new char [2];
	curResult[0] = '1';

	char * lastNumber  = new char [maxlen];
	memset (lastNumber , 0, maxlen);
	lastNumber[0] = '1';

	for (long i = 1; i <= number; ++i)
	{	
		char * curNumber = new char [strlen(lastNumber)+1];
		strcpy(curNumber, lastNumber);
		increase(curNumber);

		strcpy(curResult, lastNumber);

		char * curResult = new char [strlen(curResult) + strlen(curNumber) + 1];
		memset(curResult, 0, strlen(curResult) + strlen(curNumber) + 1);
		bigmulti(lastResult, curNumber, curResult);

		strcpy(lastNumber, curNumber);
		strcpy(lastResult, curResult);
		delete [] curNumber;
		delete [] lastResult;
	}
	return 0;
}

int main()
{
	long number;
	cin >> number;
	factorial(number);
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

void bigadd(const char * number1, const char * number2)
{
	long len1 = strlen(number1);
	long len2 = strlen(number2);
	long newlength = len1 > len2 ? len1 : len2;
	char * pResult = new char [newlength + 1];
	memset(pResult, 0, (newlength + 1)*sizeof(char));

	long prenumber = 0;
	long i = len1;
	long j = len2;
	while (i && j)
	{
		short t = prenumber + number1[i-1] + number2[j-1] - '0' - '0';
		prenumber = t >= 10 ? 1 : 0;
		pResult[newlength-1] = t%10 + '0';
		--i;--j;--newlength;
	}

	if (i == 0 && j != 0)
	{
		while (j)
		{
			short t = prenumber + number2[j-1] - '0';
			prenumber = t >= 10 ? 1 : 0;
			pResult[newlength-1] = t%10 + '0';
			--j;--newlength;
		}
	}
	else if (i != 0 && j == 0)
	{
		while (i)
		{
			short t = prenumber + number1[i-1]- '0';
			prenumber = t >= 10 ? 1 : 0;
			pResult[newlength-1] = t%10 + '0';
			--i;--newlength;
		}
	}

	if (prenumber)
		cout << prenumber;
	cout << pResult;
	delete [] pResult;
}

int main()
{
	char number1 [200];
	cin >> number1;
	char number2 [200];
	cin >> number2;

	bigadd(number1, number2);
}
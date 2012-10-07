// testcpu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <set>
#include <string>
using namespace std;

void str2bignumber(const char* input, short * output)
{
	long length = strlen(input);
	for (long i = 0; i< length; ++i)
	{
		output[i] =input[length-i-1] - 48;
	}
}

char * bigmulti(short* mul1, long len1, short* mul2, long len2)
{
	short * psresult = new short [len1+len2];
	memset(psresult, 0, (len2+len1)*sizeof(short));

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

	char * pcresult = new char [len1+ len2 + 1];
	memset(pcresult, ' ' , (len1+ len2)*sizeof(char));

	// truncate useless 0 in front
	long actuallen = len1+len2-1;
	while (psresult[actuallen]==0 && actuallen >=0)
		actuallen--;

	// tranfer short * to char *
	long indexOfChar = 0;
	while(actuallen>=0)
		pcresult[indexOfChar++] = psresult[actuallen--] + 48; 
	pcresult[indexOfChar] = 0;

	delete [] psresult;
	return pcresult;
}

void mycase(const char * number1, const char * number2)
{
	long length1 = strlen(number1);
	short * output1 = new short [length1];
	str2bignumber(number1, output1);

	long length2 = strlen(number2);
	short * output2 = new short [length2];
	str2bignumber(number2, output2);

	char * result = bigmulti(output1, length1, output2, length2);
	cout << result << endl;

	delete [] output1;
	delete [] output2;
	delete [] result;
}
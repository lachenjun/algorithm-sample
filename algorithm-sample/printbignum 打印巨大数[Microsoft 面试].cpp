#include <iostream>
using namespace std;


/*
	printnum(long n)

	n = 1: 0,1,2,3,4,5,6,7,8,9
	n = 2: 0,1,2,3,4,5,6,7,8,9……,98,99
	n = 3: 0,1,2,3,4,5,6,7,8,9……,998,999*/

void add(char * pstr, long len)
{
	if (pstr[len - 1] != 9)
		pstr[len - 1] += 1;
	else
	{
		add(pstr, len - 1);
		pstr[len - 1] = 0;
	}
}

void printchar(char * pstr, long len)
{
	bool begin = false;
	for (long i = 0; i < len; ++i)
	{
		if (begin || pstr[i] != 0)
		{
			begin = true;
			cout << char(pstr[i] + '0');
		}
	}
}

void printnum(long n)
{
	// 初始化为0
	char * pstr = new char [n];
	memset(pstr, 0, n);

	// 目标值是999....
	char * presult = new char [n];
	memset(presult, 9, n);

	long curlen = 0;
	while(memcmp(pstr, presult, n))
	{
		add(pstr, n);
		printchar(pstr, n);
		cout << ",";
	}

	delete [] pstr;
	delete [] presult;
}

void main()
{
	printnum(4);
}
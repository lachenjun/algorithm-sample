#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <memory.h>
using namespace std;

void dec2binary(char * input, char * output)
{
	long len = strlen(input);
	char * head = new char [len + 1];
	char * end = new char [len + 1];
	strcpy(head, input);
	memset(end, '0', len);
	end[len] = 0;

	long index = 0;
	long left = 0;
	while (strcmp(input, end))
	{
		while (index < len)
		{
			input[index] = (left*10 + head[index] - '0') / 2 + '0';
			left = (head[index] - '0') % 2 ? 1 : 0;
			++index;
		}
		*(output++)  = left + '0';
		index = left = 0;
		strcpy(head, input);
	}
	delete [] head;
	delete [] end;
}

void printStr(char * output)
{
	long len = strlen(output);
	while (--len >= 0)
		cout << output[len];
	cout << endl;
}

int main()
{
	char input [31] = {0};
	char result [100] = {'0'}; // 处理0为被除数

	while (cin >> input)
	{
		dec2binary(input, result);
		printStr(result);

		memset(result, 0, 100);
		result[0] = '0'; // 处理0为被除数
	}
	return 0;
}

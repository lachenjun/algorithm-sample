/*
Description
The Recaman's sequence is defined by a0 = 0 ; for m > 0, am = am−1 − m if the resulting am is positive and not already in the sequence, otherwise am = am−1 + m.
The first few numbers in the Recaman's Sequence is 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9 ...
Given k, your task is to calculate ak.

Input
The input consists of several test cases. Each line of the input contains an integer k where 0 <= k <= 500000.
The last line contains an integer −1, which should not be processed.

Output
For each k given in the input, print one line containing ak to the output.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define MAX_LENGTH 600000

class Used
{
public:
	Used()
	{		
		for (int i = 0; i < 8; ++i)
			m_offset[i] = 1<<i;

		reset();
	}

	bool get(int i)
	{
		return ((m_data[i/8] & m_offset[i%8]) != 0);
	}

	void set(int i)
	{
		m_data[i/8] |= m_offset[i%8];
	}

	void reset()
	{
		memset(m_data, 0, MAX_LENGTH); 
	}

private:
	char m_data[MAX_LENGTH];
	char m_offset[8];
};

int main()
{
	Used obj;
	while (true)
	{
		long k;
		cin >> k;
		
		if (k == -1)
			return 0;

		obj.reset();
		long result = 0;
		for (long i = 0; i <= k; ++i)
		{
			if (result > i && !obj.get(result - i))
				result -= i;
			else
				result += i;
			obj.set(result);
		}
		cout << result << endl;
	}
	return 0;
}
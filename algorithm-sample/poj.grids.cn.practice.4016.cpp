#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

class student
{
public:
	student(){_times = 1;}
	student(long index, long score):_index(index), _scores(score)
	{
		_times = 1;
	}

	double _scores;
	long _index;
	long _times;
};

int main()
{
	long number;
	cin >> number;
	map <long, student> mStudent;
	long i = 0;
	while (i < number)
	{
		long score;
		long studentID;
		cin >> studentID >> score;
		if (mStudent.find(studentID) == mStudent.end())
			mStudent[studentID] = student(i, score);
		else
		{
			student & s = mStudent[studentID];
			s._scores = (s._scores*s._times+score)/(s._times+1.0);
			s._times++;
		}
		++i;
	}
}
// testcpu.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <complex>

using namespace std;

// �Լ�дһ��ģ��vector ��

class myPoint
{
public:
	myPoint(double xx, double yy):x(xx), y(yy){}
	friend double Distance (myPoint & p1, myPoint &p2);
private:
	double x;
	double y;
};

double Distance(myPoint & p1, myPoint &p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
};

void main()
{
	myPoint p1(1,2);
	myPoint p2(4,6);

	cout << Distance(p1, p2) << endl;
}
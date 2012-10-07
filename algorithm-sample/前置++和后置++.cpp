#include <iostream>
#include <windows.h>
using namespace std;


class A
{
private:
	long data;
public:
	A()
	{
		data = 0;
	}
	long operator++() // ǰ��++��һԪ������
	{
		data += 1;
		return data;
	}

	long operator++(int i) // ����++, ��Ԫ������
	{
		long temp = data;
		++*this;
		return temp;
	}

	friend void print (const A & a);
};

void print(const A & a)
{
	cout << a.data << endl;
}
void main()
{
	A a;
	print(a);

	cout << ++a << endl;
	print(a);

	cout << a++ << endl;
	print(a);
}
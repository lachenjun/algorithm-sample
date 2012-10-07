#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int input = 0;
	while(cin>>input)
	{
		bool minus = false;
		int result = 0;
		if (input < 0)
		{
			minus = true;
			input = -input;
		}
		while (input)
		{
			result = result* 10 + input % 10;
			input = input / 10;
		}

		if (minus == true)
			cout << -result << endl;
		else
			cout << result << endl;
	}
	return 0;
}
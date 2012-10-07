void swap (char * str, long spacelength, long index)
{
	char temp = str[index];
	str[index] = ' ';
	str[index - spacelength] = temp;
}

void fun(char * str)
{
	long length = strlen(str);
	long spacelength = 0;
	for (long i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
			++spacelength;

		if (spacelength && str[i] != ' ')
		{
			swap(str, spacelength, i);
		}
	}
}

void main()
{
	char str [] = " my name is liheng ";
	fun(str);
	cout << str << "|" << endl;
}
long  larray [] = {1,6,6,6,6,8,15,15,15,17};

// 直接返回查找到的位置
long Binarysearch(long * larray, long start, long end, long value)
{
	if (start<0 || start> end)
		return -1;
	long mid = (start+end)/2;
	if (larray[mid] == value)
		return mid;
	else if (larray[mid] < value)
		return Binarysearch(larray, mid+1, end, value);
	else
		return Binarysearch(larray, start, mid-1, value);
}

long searchbegin(long* larray, long index, long value)
{
	long result = index;
	while(result > 0 && larray[result - 1] == value)
		result--;
	return result;
}

// 返回查找到的第一个元素的位置
long Binarysearchfirst(long * larray, long start, long end, long value)
{
	if (start<0 || start> end) 
		return -1;
	long mid = (start+end)/2;

	if (mid == 0)
		return larray[mid] == value? 0:-1;
	else if (larray[mid] == value && larray[mid-1] < value)
		return mid;
	else if (larray[mid] > value || (larray[mid] == value && larray[mid-1] == value))
		return Binarysearchfirst(larray, start, mid-1, value);
	else
		return Binarysearchfirst(larray, mid+1, end, value);
}

void main()
{
	long result = -2;
	result= Binarysearchfirst(larray, 0 , 9, 1);
	cout << result << endl;
	result = Binarysearchfirst(larray, 0 , 9, 2);

	cout << result << endl;
	result = Binarysearchfirst(larray, 0 , 9, 6);

	cout << result << endl;
	result = Binarysearchfirst(larray, 0 , 9, 8);

	cout << result << endl;
	result = Binarysearchfirst(larray, 0 , 9, 15);

	cout << result << endl;
	result = Binarysearchfirst(larray, 0 , 9, 17);

	cout << result << endl;
	result = Binarysearchfirst(larray, 0 , 9, 19);

	cout << result << endl;
}
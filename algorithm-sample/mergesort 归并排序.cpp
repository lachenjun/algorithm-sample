using namespace std;
long array [] = {9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1};
long length = 18;

void mergesortimplement( long begin1, long len1, long begin2, long len2)
{
	if (begin1 == begin2 || len2 <= 0)
		return;
	long * temp  = new long[len1 + len2];
	memset(temp, 0, (len1 + len2)*sizeof(long));
	long *tem = temp;

	long times1 = 0;
	long times2 = 0;
	while(times1 < len1 && times2 < len2)
	{
		if (array[begin1+times1] < array[begin2+times2])
		{
			*(temp++) = array[begin1+times1];
			++times1;
		}
		else
		{
			*(temp++) = array[begin2+times2];
			++times2;
		}
	}

	memcpy(temp, array+begin1+times1, (len1 - times1)*sizeof(long));
	memcpy(temp, array+begin2+times2, (len2 - times2)*sizeof(long));
	memcpy(array + begin1, tem, (len1 + len2)*sizeof(long));
	delete [] tem;
}

void mergesort(long low, long high)
{
	// 非递归
	/*for (long len = 1; len < length; len = 2*len) // 被merge的数组的长度，最短1，最长length-1
	{
		for (long begin = low; begin <= length-1; begin += 2*len)	// begin表示merge开始的地方
		{
			if (begin+2*len > length)
				mergesortimplement(begin, len, begin+len, length-begin-len);
			else	
				mergesortimplement(begin, len, begin+len, len);
		}
	}*/

	// 递归
	if (low < high)
	{
		long mid = (low + high)/2;
		mergesort(low, mid);
		mergesort(mid+1, high);
		mergesortimplement(low, mid-low+1,mid+1,high-mid);
	}
}

void main()
{
	mergesort(0, 17);
	for (long i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

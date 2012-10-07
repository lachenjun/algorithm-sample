long array[21]={0,20,13,8,17,11,12,9,19,14,16,5,4,10,15,18,7,6,3,2,1};
void swap (long * p1, long *p2)
{
	long temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void heapinsert(long * array , long index)
{
	while(index	!= 1) 
	{
		if (array[index] < array[index/2])
			swap(&array[index], &array[index/2]);
		index /= 2;
	}
}

void initheap(long * array )
{
	for (long i = 2; i <= 20; ++i)
	{
		heapinsert(array,i);
	}
}

long getheap(long * array ,long length)
{
	long ret = array[1];
	long i = 1;

	array[1] = -1;
	if (2*i <= length)
	{
		while(i < length)
		{
			if ((2*i+1 <= length && array[2*i] < array[2*i + 1]) || 2*i == length)
			{
				swap(&array[2*i], &array[i]);
				i = 2*i;
			}
			else if ((2*i+1 <= length && array[2*i] >= array[2*i + 1]))
			{
				swap(&array[2*i+1], &array[i]);
				i = 2*i + 1;
			}
			else
				break;
		}
		if (i != length)
			swap(&array[length], &array[i]);
	}
	return ret;
}

void heapsort(long *array)
{
	initheap(array);
	for (long i = 20; i != 0; --i)
	{
		cout << getheap(array, i) << " ";
	}
}

void main()
{
	heapsort(array);	
}

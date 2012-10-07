void Insertsort(int *a , long length)
{
	for (long i = 1; i < length; ++i)
	{
		long cur = a[i];
		long len = i;
		while (len && cur < a[len - 1])
		{
			a[len] = a[len - 1];
			--len;
		}
		a[len] = cur;
	}
}



void main()
{
	int a[10]={10,8,19,7,6,5,14,3,2,1};
	Insertsort(a,10);
	//	ShellSort(11);
	for(long i=0;i<10;i++)
	{
		printf("%-3d",a[i]);
	}
}
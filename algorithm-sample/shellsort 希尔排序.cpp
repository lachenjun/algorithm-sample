#include<stdio.h>

int a[10]={10,9,8,7,6,5,4,3,2,1};
void Shell(int length,int offset)
{
	for(long i = offset;  i < length; ++i)
	{
		long cur = a[i];
		long k = i - offset;
		while(k >= 0 && cur < a[k])
		{
			a[k + offset] = a[k];
			k -= offset; 
		}
		a[k + offset] = cur;

	}
}

void main()
{
	//	Insertsort(a,10);
	for(long offset=10/2; offset>0; offset = offset/2)//注意最后一趟增量必须为 1
	{
		Shell(10,offset);
	}

	for(long i=0;i<10;i++)
	{
		printf("%-3d",a[i]);
	}
}
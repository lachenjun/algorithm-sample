long stack2 [] = {31,-41,59,26,-53,58,97,-95,-23,84};
// Ѱ���������еĺ����������飬������Ծ
void getmaxsub()
{
	long maxsofar = 0;
	long maxending = 0;
	for (long i = 0; i < 10; i++)
	{
		maxending = max(maxending+stack2[i], 0);
		maxsofar = max(maxsofar, maxending);
	}
}

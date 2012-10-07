// zigzag ‰≥ˆŒ Ã‚
/* 
	0,  1,  5,  6, 14, 15, 27, 28,
	2,  4,  7, 13, 16, 26, 29, 42,
	3,  8, 12, 17, 25, 30, 41, 43,
	9, 11, 18, 24, 31, 40, 44, 53,
	10,19, 23, 32, 39, 45, 52, 54,
	20,22, 33, 38, 46, 51, 55, 60,
	21,34, 37, 47, 50, 56, 59, 61,
	35,36, 48, 49, 57, 58, 62, 63,
*/

void zigzag(long * p, long len)
{
	for (long i = 0; i < len; ++i)
	{
		for (long j = 0; j < len; ++j)
		{
			long linenum = i + j;
			long begin = (linenum + 1)*linenum/2;
			long _i = len - i - 1;
			long _j = len - j - 1;
			long _linenum = _i + _j;
			long _begin = (_linenum + 1)*_linenum/2 + 1;

			if (linenum < len && linenum % 2 == 1)
				p[i*len+j] = begin + i;
			else if (linenum < len && linenum % 2 == 0)
				p[i*len+j] = begin + j;
			else if (linenum >= len && linenum % 2 == 1)
				p[i*len+j] = len*len - (_begin + _i);
			else if (linenum >= len && linenum % 2 == 0)
				p[i*len+j] = len*len - (_begin + _j);
		}
	}
}

void main()
{
	long len = 8;
	long * p = new long[len*len];
	zigzag(p, len);
	for (long i = 0; i < len; ++i)
	{
		for (long j = 0; j < len; ++j)
		{
			printf("%03d, ", p[len*i+j]);
		}
		cout << endl;
	}
}
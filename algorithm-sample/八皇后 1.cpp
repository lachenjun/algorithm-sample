//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//const long len = 8;
//long a[len];
//
//int main()
//{
//	long cur = 0;
//	long count = 0;
//	bool not_finished = true;
//	a[0] = 1;
//	while(not_finished)
//	{
//		while(not_finished && cur < len)
//		{
//			bool valid = true;
//			// ͬ�м��
//			for (long i = 0; valid && i < cur; ++i)
//				if (a[i] == a[cur])
//					valid = false;
//
//			// �Խ��߼��
//			for (long i = 0; valid && i < cur; ++i)
//				if ((a[i] - i == a[cur] - cur) || i + a[i] == cur + a[cur])
//					valid = false;
//
//			if(!valid)
//			{
//				if(a[cur] == a[cur-1])
//				{
//					--cur;
//					if (cur > 0 && a[cur] == len)
//						a[cur] = 1;
//					else if (cur == 0 && a[cur] == len)
//						not_finished = false; // ��ʱ����
//					else
//						++a[cur];
//				}
//				else if (a[cur] == len)
//					a[cur] = 1;
//				else
//					++a[cur];
//
//			}
//			// cur λ�õ�ֵ�Ϸ���ȡcur�¸�λ�õ�ֵ
//			else if (++cur < len)
//				if (a[cur-1] == len)
//					a[cur] = 1;
//				else
//					a[cur] = a[cur-1]+1;
//
//		}
//
//		// ���
//		if (not_finished)
//		{
//			++count;
//			cout << count << ":";
//			for(long i = 0; i < len; i++)
//				cout << a[i];
//			cout << endl;
//
//			// ������һ������ֵ,�޸ĵ����ڶ�λ��ֵ
//			if (a[len-2] < len)
//				++a[len-2];
//			else
//				a[len-2] = 1;
//			cur = len - 2;
//		}
//	}
//	return 0;
//}
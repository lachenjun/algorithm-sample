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
//			// 同行检查
//			for (long i = 0; valid && i < cur; ++i)
//				if (a[i] == a[cur])
//					valid = false;
//
//			// 对角线检查
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
//						not_finished = false; // 此时结束
//					else
//						++a[cur];
//				}
//				else if (a[cur] == len)
//					a[cur] = 1;
//				else
//					++a[cur];
//
//			}
//			// cur 位置的值合法，取cur下个位置的值
//			else if (++cur < len)
//				if (a[cur-1] == len)
//					a[cur] = 1;
//				else
//					a[cur] = a[cur-1]+1;
//
//		}
//
//		// 输出
//		if (not_finished)
//		{
//			++count;
//			cout << count << ":";
//			for(long i = 0; i < len; i++)
//				cout << a[i];
//			cout << endl;
//
//			// 设置下一个可能值,修改倒数第二位的值
//			if (a[len-2] < len)
//				++a[len-2];
//			else
//				a[len-2] = 1;
//			cur = len - 2;
//		}
//	}
//	return 0;
//}
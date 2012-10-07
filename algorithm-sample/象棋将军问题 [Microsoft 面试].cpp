#include <stdlib.h>
#include <stdio.h>

#define LGET(b) ((b & 0xf0) >> 4)
#define RGET(b) (b & 0x0f)
#define LSET(b,n) (b = (b & 0x0f) + (n << 4))
#define RSET(b,n) (b = (b & 0xf0) + n)

void method1()
{
	unsigned char b;
	for (LSET(b, 1) ; LGET(b) <= 9; LSET(b, LGET(b)+1))
	{
		for (RSET(b, 1) ; RGET(b) <= 9; RSET(b, RGET(b)+1))
		{
			if (LGET(b) % 3 != RGET(b) % 3)
				printf ("A = %d, B = %d ", LGET(b), RGET(b));
		}
		printf("\n");
	}
}

void method2()
{
	unsigned char b = 81;
	while (b--)
	{
		if (b%9%3 != b/9%3)
			printf ("A = %d, B = %d\n", b%9+1, b/9+1);
	}
}

void method3()
{
	struct 
	{
		unsigned char a:4;
		unsigned char b:4;
	}i;

	for (i.a = 1; i.a <= 9; i.a++)
	{
		for (i.b = 1; i.b <= 9; i.b++)
		{
			if (i.a % 3 != i.b % 3)
				printf ("A = %d, B = %d ", i.a, i.b);
		}
		printf ("\n");
	}
}

int main()
{
	method3();
}
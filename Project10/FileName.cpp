#include <stdio.h>
#define NUM_PRINT 5

void PrintHelloworld(int nCount);

int main(void)
{
	int nCount = 0;
	PrintHelloworld(nCount);
	return 0;
}
void PrintHelloworld(int nCount)
{
	if (nCount == NUM_PRINT)
	{
		return;
	}
	printf(":Hello, World!(%d)\n", nCount);
	PrintHelloworld(++nCount);
	printf("jam\n");

	return;
}
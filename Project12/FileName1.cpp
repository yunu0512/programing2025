#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int num;
	int count = 0;

	printf("2 이상의 정수를 입력하세요 :");
	if (scanf_s("%d", &num) != 1)
	{
		printf("입력 오류가 발생했습니다.\n");
		return 1;
	}

	if (num < 2)
	{
		printf("2 이상의 정수를 입력해야 합니다.\n");
		return 1;
	}
	for (int i = 2; i <= num; i++)
	{
		bool is_prime = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				is_prime = false;
				break;
			}
		}

		if (is_prime)
		{
			if (count > 0 && count % 5 == 0)
			{
				printf("\n");
			}
			printf("%5d", i); 
			count++;
		}
	}

	printf("\n");
	return 0;
}
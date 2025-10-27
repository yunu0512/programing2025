#include <stdio.h>
int rec_func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + rec_func(n - 1);
    }
}

int main()
{
    int input_n = 10;
    int result = rec_func(input_n);

    printf("--- 실행 결과 ---\n");
    printf("입력 N: %d\n", input_n);
    printf("실행 결과 (1부터 %d까지의 합): %d\n", input_n, result);
    if (result == 55)
    {
        printf("계산이 성공적으로 완료되었습니다. (출력값 55)\n");
    }
    else
    {
        printf("계산에 오류가 있습니다.\n");
    }

    return 0;
}
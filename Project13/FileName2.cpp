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

    printf("--- ���� ��� ---\n");
    printf("�Է� N: %d\n", input_n);
    printf("���� ��� (1���� %d������ ��): %d\n", input_n, result);
    if (result == 55)
    {
        printf("����� ���������� �Ϸ�Ǿ����ϴ�. (��°� 55)\n");
    }
    else
    {
        printf("��꿡 ������ �ֽ��ϴ�.\n");
    }

    return 0;
}
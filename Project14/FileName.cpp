#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    double num1, num2;

    printf("�� ���ڸ� �Է��ϼ��� (��: 10 5): ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("�߸��� �Է� �����Դϴ�.\n");
        return 1;
    }

    printf("\n--- ��� ---\n");
    printf("����: %.2lf\n", num1 + num2);
    printf("����: %.2lf\n", num1 - num2);
    printf("����: %.2lf\n", num1 * num2);

    if (num2 != 0) {
        printf("������: %.2lf\n", num1 / num2);
    }
    else {
        printf("������: ���� (0���� ���� �� �����ϴ�)\n");
    }

    return 0;
}
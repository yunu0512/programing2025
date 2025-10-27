#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h> 
void calculate_gcd_lcm_while(int a, int b) {
    int num1 = abs(a);
    int num2 = abs(b);
    int temp_a = num1;
    int temp_b = num2;
    int temp;
    int gcd;
    long long lcm;

    if (num1 == 0 || num2 == 0) {
        printf("\n�ִ������� �ּҰ������ 0�� �ƴ� ����� ���� ���ǹ��մϴ�.\n");
        printf("�ִ����� (GCD): %d\n", (num1 == 0) ? num2 : num1);
        printf("�ּҰ���� (LCM): 0\n");
        return;
    }
    while (temp_b != 0) {
        temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    gcd = temp_a;

    lcm = (long long)num1 * num2 / gcd;

    printf("\n--- while �� ��� ---\n");
    printf("�Է��� �� ��: %d, %d\n", a, b);
    printf("�ִ����� (GCD): %d\n", gcd);
    printf("�ּҰ���� (LCM): %lld\n", lcm);
}

int main() { 
    int num1, num2;

    printf("�� ���� ������ �Է��ϼ��� (��: 12 18): ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    calculate_gcd_lcm_while(num1, num2);

    return 0;
}
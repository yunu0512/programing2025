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
        printf("\n최대공약수와 최소공배수는 0이 아닌 양수에 대해 유의미합니다.\n");
        printf("최대공약수 (GCD): %d\n", (num1 == 0) ? num2 : num1);
        printf("최소공배수 (LCM): 0\n");
        return;
    }
    while (temp_b != 0) {
        temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    gcd = temp_a;

    lcm = (long long)num1 * num2 / gcd;

    printf("\n--- while 문 결과 ---\n");
    printf("입력한 두 수: %d, %d\n", a, b);
    printf("최대공약수 (GCD): %d\n", gcd);
    printf("최소공배수 (LCM): %lld\n", lcm);
}

int main() { 
    int num1, num2;

    printf("두 개의 정수를 입력하세요 (예: 12 18): ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "잘못된 입력입니다.\n");
        return 1;
    }

    calculate_gcd_lcm_while(num1, num2);

    return 0;
}
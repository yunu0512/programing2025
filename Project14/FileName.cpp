#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    double num1, num2;

    printf("두 숫자를 입력하세요 (예: 10 5): ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("잘못된 입력 형식입니다.\n");
        return 1;
    }

    printf("\n--- 결과 ---\n");
    printf("덧셈: %.2lf\n", num1 + num2);
    printf("뺄셈: %.2lf\n", num1 - num2);
    printf("곱셈: %.2lf\n", num1 * num2);

    if (num2 != 0) {
        printf("나눗셈: %.2lf\n", num1 / num2);
    }
    else {
        printf("나눗셈: 오류 (0으로 나눌 수 없습니다)\n");
    }

    return 0;
}
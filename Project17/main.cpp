#define _CRT_SECURE_NO_WARNINGS // scanf_s 경고를 비활성화합니다.

#include <stdio.h>
#include <stdlib.h> // exit() 함수를 위해 필요

// --- 1. 계산 함수 구현 ---

void calculate_line_info(const double* x1_ptr, const double* y1_ptr,
    const double* x2_ptr, const double* y2_ptr,
    double* slope_ptr, double* bias_ptr) {

    double x1 = *x1_ptr;
    double y1 = *y1_ptr;
    double x2 = *x2_ptr;
    double y2 = *y2_ptr;

    double delta_x = x2 - x1;
    if (delta_x == 0.0) {
        printf("\n Error: x 좌표가 동일하여 기울기가 정의되지 않습니다.\n");
        exit(EXIT_FAILURE);
    }
    double m = (y2 - y1) / delta_x;

    double b = y1 - m * x1;

    *slope_ptr = m;
    *bias_ptr = b;
}

int main() {

    double x1, y1; 
    double x2, y2; 

    double final_slope;
    double final_bias;

    printf("--- 직선의 기울기와 절편 계산 (사용자 입력) ---\n");

    printf("\nInput 1st point (x1 y1): ");
    if (scanf_s("%lf %lf", &x1, &y1) != 2) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    printf("Input 2nd point (x2 y2): ");
    if (scanf_s("%lf %lf", &x2, &y2) != 2) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    calculate_line_info(&x1, &y1, &x2, &y2, &final_slope, &final_bias);

    printf("\nCalculated Output, line equation:\n");
    printf("slope: %.4f\n", final_slope);
    printf("bias: %.4f\n", final_bias);
    printf("--------------------------------------\n");

    return 0;
}
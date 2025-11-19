#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    double x;
    double y;
} Point;

void calculate_line_info(const Point* p1_ptr, const Point* p2_ptr,
    double* slope_ptr, double* bias_ptr) {

    double x1 = p1_ptr->x;
    double y1 = p1_ptr->y;
    double x2 = p2_ptr->x;
    double y2 = p2_ptr->y;

    double delta_x = x2 - x1;
    if (delta_x == 0.0) {
        printf("\n❌ Error: x 좌표가 동일하여 기울기가 정의되지 않습니다.\n");
        exit(EXIT_FAILURE);
    }
    double m = (y2 - y1) / delta_x;
    double b = y1 - m * x1;
    *slope_ptr = m;
    *bias_ptr = b;
}

int main() {
  
    Point p1;
    Point p2;

    double final_slope;
    double final_bias;  

    printf("--- 직선의 기울기와 절편 계산 (사용자 입력) ---\n");

    printf("\nInput 1st point information (x1 y1): ");
    if (scanf_s("%lf %lf", &p1.x, &p1.y) != 2) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    printf("Input 2nd point information (x2 y2): ");
    if (scanf_s("%lf %lf", &p2.x, &p2.y) != 2) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    calculate_line_info(&p1, &p2, &final_slope, &final_bias);
    printf("\nCalculated Output, line equation:\n");
    printf("slope: %.4f\n", final_slope);
    printf("bias: %.4f\n", final_bias);
    printf("--------------------------------------\n");

    return 0;
}
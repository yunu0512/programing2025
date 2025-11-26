#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIMENSION 3 
void input_vector(float* vec, int dim, const char* name)
{
    printf("--- 벡터 %s의 요소를 입력하세요 (x, y, z) ---\n", name);

    for (int i = 0; i < dim; i++) {
        char axis;
        if (i == 0) axis = 'x';
        else if (i == 1) axis = 'y';
        else axis = 'z';

        printf("%s[%c] 성분: ", name, axis);
        if (scanf_s("%f", vec + i) != 1) {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            exit(1);
        }
    }
    printf("\n");
}
float calculate_dot_product(const float* A, const float* B, int dim)
{
    float result = 0.0f;
    for (int i = 0; i < dim; i++) {
        result += (*(A + i) * *(B + i));
    }
    return result;
}
void calculate_cross_product(const float* A, const float* B, float* result)
{
    *(result + 0) = (*(A + 1) * *(B + 2)) - (*(A + 2) * *(B + 1));
    *(result + 1) = (*(A + 2) * *(B + 0)) - (*(A + 0) * *(B + 2));
    *(result + 2) = (*(A + 0) * *(B + 1)) - (*(A + 1) * *(B + 0));
}

int main(void)
{
    float vector_A[DIMENSION];
    float vector_B[DIMENSION];
    float cross_product_result[DIMENSION];
    input_vector(vector_A, DIMENSION, "A");
    input_vector(vector_B, DIMENSION, "B");
    float dot_product = calculate_dot_product(vector_A, vector_B, DIMENSION);

    printf("========================================\n");
    printf(" 벡터 연산 결과\n");
    printf("========================================\n");
    printf(" 내적 (Dot Product, A · B):\n");
    printf("   %.2f\n", dot_product);
    printf("----------------------------------------\n");
    calculate_cross_product(vector_A, vector_B, cross_product_result);
    printf(" 외적 (Cross Product, A x B):\n");
    printf("   (");
    for (int i = 0; i < DIMENSION; i++) {
        printf("%.2f", *(cross_product_result + i));
        if (i < DIMENSION - 1) {
            printf(", ");
        }
    }
    printf(")\n");
    printf("========================================\n");
    printf("\n이 결과를 공학용 계산기나 온라인 벡터 계산기와 비교하여\n");
    printf("   동일한 결과가 나오는지 확인하십시오.\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 3
#define TOLERANCE 1e-9

// --- 기본 유틸리티 함수 ---

// 특정 범위 정수 난수 생성
int get_rand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// 행렬 출력 (double 형으로 통일)
void print_matrix(const char* name, const double mat[N][N]) {
    printf("--- %s ---\n", name);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 소수점 4자리까지 출력
            printf("%8.4f", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 3x3 행렬의 행렬식 (Determinant) 계산
double determinant_3x3(const double mat[N][N]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
        mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
        mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// --- 행렬 연산 함수 ---

// 덧셈 (R = A + B)
void add_matrices(const double A[N][N], const double B[N][N], double R[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            R[i][j] = A[i][j] + B[i][j];
}

// 뺄셈 (R = A - B)
void subtract_matrices(const double A[N][N], const double B[N][N], double R[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            R[i][j] = A[i][j] - B[i][j];
}

// 스칼라 곱셈 (R = c * A)
void scalar_multiply(int c, const double A[N][N], double R[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            R[i][j] = (double)c * A[i][j];
}

// 행렬 곱셈 (R = A * B)
void multiply_matrices(const double A[N][N], const double B[N][N], double R[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                R[i][j] += A[i][k] * B[k][j]; // 행렬 곱 정의
            }
        }
    }
}

// --- 메인 함수 ---
int main() {
    srand((unsigned int)time(NULL));

    // double 타입으로 행렬 선언 (모든 연산 결과를 저장하기 용이함)
    double A[N][N];
    double B[N][N];
    double R[N][N];
    int c = get_rand(1, 5); // 스칼라

    // 1. 행렬 생성 (정수 난수 채우기)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)get_rand(-5, 5);
            B[i][j] = (double)get_rand(-5, 5);
        }
    }

    printf("========= C 언어 행렬 연산 (간결) =========\n");
    print_matrix("행렬 A", A);
    print_matrix("행렬 B", B);
    printf("스칼라 c: %d\n\n", c);

    // 2. 기본 연산 수행 및 출력
    add_matrices(A, B, R);
    print_matrix("A + B (덧셈)", R);

    subtract_matrices(A, B, R);
    print_matrix("A - B (뺄셈)", R);

    scalar_multiply(c, A, R);
    print_matrix("c * A (스칼라 곱셈)", R);

    multiply_matrices(A, B, R);
    print_matrix("A @ B (행렬 곱셈)", R);

    // 3. 역행렬 가능 여부 확인
    printf("--- 역행렬 가능 여부 확인 ---\n");

    double det_A = determinant_3x3(A);
    printf("행렬 A의 행렬식 (det(A)): %.4f\n", det_A);
    if (fabs(det_A) < TOLERANCE) {
        printf("⚠️ 행렬 A는 **특이 행렬**로, 역행렬이 존재하지 않습니다.\n\n");
    }
    else {
        printf("✅ 행렬 A는 **정칙 행렬**로, 역행렬 계산이 가능합니다.\n\n");
        // *참고: 역행렬 계산 로직(복잡)은 간결성을 위해 생략함*
    }

    double det_B = determinant_3x3(B);
    printf("행렬 B의 행렬식 (det(B)): %.4f\n", det_B);
    if (fabs(det_B) < TOLERANCE) {
        printf("⚠️ 행렬 B는 **특이 행렬**로, 역행렬이 존재하지 않습니다.\n");
    }
    else {
        printf("✅ 행렬 B는 **정칙 행렬**로, 역행렬 계산이 가능합니다.\n");
        // *참고: 역행렬 계산 로직(복잡)은 간결성을 위해 생략함*
    }

    return 0;
}
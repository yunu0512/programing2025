#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
#define MIN_VAL -100.0
#define MAX_VAL 100.0

typedef enum {
    ASCENDING,
    DESCENDING
} SortOrder;

#define FORMAT_DOUBLE(val) printf("%.2f", val)

void GenerateRandomArray(double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) = MIN_VAL + (MAX_VAL - MIN_VAL) * (rand() / (double)RAND_MAX);
    }
}

void swap_double(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void CalcSortArray(double arr[], int size, SortOrder order) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {

            double* current_ptr = arr + j;
            double* next_ptr = arr + j + 1;

            bool should_swap = false;

            if (order == ASCENDING) {
                if (*current_ptr > *next_ptr) {
                    should_swap = true;
                }
            }
            else if (order == DESCENDING) {
                if (*current_ptr < *next_ptr) {
                    should_swap = true;
                }
            }

            if (should_swap) {
                swap_double(current_ptr, next_ptr);
            }
        }
    }
}

void PrintArray(const char* label, const double* arr, int size) {
    printf("--- %s ---\n", label);
    printf("[ ");

    for (int i = 0; i < size; ++i) {
        FORMAT_DOUBLE(arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void PointerArrayExample() {
    printf("\n--- 다차원 배열 및 포인터 배열 예시 ---\n");

    int matrix[2][3] = { {10, 20, 30}, {40, 50, 60} };
    printf("1. 2차원 배열 (matrix[2][3]):\n");

    printf("   matrix[1][2] (배열 문법): %d\n", matrix[1][2]);
    printf("   *(*(matrix + 1) + 2) (포인터 연산): %d\n", *(*(matrix + 1) + 2));

    int a = 1, b = 2, c = 3;
    int* ptr_array[3] = { &a, &b, &c };
    printf("\n2. 포인터 배열 (int* ptr_array[3]):\n");

    printf("   *ptr_array[1]이 가리키는 값: %d\n", *ptr_array[1]);

    int** pptr = ptr_array;
    printf("   **pptr (첫 번째 요소가 가리키는 값): %d\n", **pptr);
}

int main() {
    srand((unsigned int)time(NULL));

    double data_array[ARRAY_SIZE];
    double* data_ptr = data_array;

    GenerateRandomArray(data_ptr, ARRAY_SIZE);
    PrintArray("랜덤 생성 상태", data_array, ARRAY_SIZE);

    printf("\n======================================\n");

    CalcSortArray(data_array, ARRAY_SIZE, ASCENDING);
    PrintArray("오름차순 정렬 상태", data_ptr, ARRAY_SIZE);

    printf("\n======================================\n");

    CalcSortArray(data_array, ARRAY_SIZE, DESCENDING);
    PrintArray("내림차순 정렬 상태", data_ptr, ARRAY_SIZE);

    PointerArrayExample();

    return 0;
}
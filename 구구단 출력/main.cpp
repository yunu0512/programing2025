#include <stdio.h>

int main() {
    int choice;

    // --- (1. 입력 안내 부분 복원) ---
    printf("===================================\n");
    printf("        구구단 출력 프로그램         \n");
    printf("===================================\n");
    printf("1. 특정 단만 출력 (2~9 사이 숫자 입력)\n");
    printf("2. 2단부터 9단까지 모두 출력 (0 입력)\n");
    printf("-----------------------------------\n");
    printf("출력할 구구단 단수 (2-9) 또는 전체 출력 (0)을 입력하세요: ");

    if (scanf("%d", &choice) != 1) {
        // --- (2. scanf 오류 처리 복원) ---
        printf("\n⚠️ 오류: 잘못된 입력 형식입니다. 숫자를 입력해 주세요.\n");
        return 1;
    }

    if (choice == 0) { // <--- 전체 출력 옵션 (0 입력)
        printf("\n[ 2단부터 9단까지 전체 구구단 출력 ]\n");

        // 외부 for 문: 단수를 반복 (2부터 9까지)
        for (int dan = 2; dan <= 9; dan++) {
            printf("\n--- %d단 ---\n", dan);

            // 내부 for 문: 곱해지는 수를 반복 (1부터 9까지)
            for (int i = 1; i <= 9; i++) { // <--- for문 사용
                printf("%d x %d = %d\n", dan, i, dan * i);
            }
        }

    }
    else if (choice >= 2 && choice <= 9) {
        // --- (3. 특정 단수 출력 로직 복원) ---
        int dan = choice;
        printf("\n[ %d단 출력 ]\n", dan);
        printf("\n--- %d단 ---\n", dan);

        // for 문을 사용하여 1부터 9까지 곱셈 반복
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", dan, i, dan * i);
        }

    }
    else {
        // --- (3. 잘못된 입력 처리 로직 복원) ---
        printf("\n⚠️ 오류: 입력 값이 유효하지 않습니다. 2부터 9 사이의 숫자나 '0'만 입력해 주세요.\n");
    }

    return 0;

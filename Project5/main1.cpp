#include <stdio.h>

int main() {
    int choice;

    // ... (입력 안내 부분 생략) ...
    printf("출력할 구구단 단수 (2-9) 또는 전체 출력 (0)을 입력하세요: ");

    if (scanf("%d", &choice) != 1) {
        // ...
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

        // ... (특정 단수 출력 및 오류 처리 부분 생략) ...

        return 0;
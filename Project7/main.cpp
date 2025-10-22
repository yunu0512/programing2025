#include <stdio.h>

int main() {
    int choice;
    char input_buffer[10]; 

    printf("===================================\n");
    printf("        구구단 출력 프로그램         \n");
    printf("===================================\n");
    printf("1. 특정 단만 출력 (2~9 사이 숫자 입력)\n");
    printf("2. 2단부터 9단까지 모두 출력 (0 입력)\n");
    printf("-----------------------------------\n");
    printf("출력할 구구단 단수 (2-9) 또는 전체 출력 (0)을 입력하세요: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        printf("\n오류: 입력 중 문제가 발생했습니다.\n");
        return 1;
    }

   
    if (sscanf_s(input_buffer, "%d", &choice) != 1) {
        printf("\n오류: 잘못된 입력 형식입니다. 숫자를 입력해 주세요.\n");
        return 1;
    }

    if (choice == 0) {
        printf("\n[ 2단부터 9단까지 전체 구구단 출력 ]\n");
        for (int dan = 2; dan <= 9; dan++) {
            printf("\n--- %d단 ---\n", dan);
            for (int i = 1; i <= 9; i++) {
                printf("%d x %d = %d\n", dan, i, dan * i);
            }
        }

    }
    else if (choice >= 2 && choice <= 9) {
        // 특정 단수 출력 로직
        int dan = choice;
        printf("\n[ %d단 출력 ]\n", dan);
        printf("\n--- %d단 ---\n", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", dan, i, dan * i);
        }
    }
    else {
        printf("\n오류: 입력 값이 유효하지 않습니다. 2부터 9 사이의 숫자나 '0'만 입력해 주세요.\n");
    }

    return 0;
}

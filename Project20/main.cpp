#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LOTTO_SIZE 6     
#define NUM_RANGE 45     

void GenRandSeed();
void generate_lotto_numbers(int* numbers);
void input_user_numbers(int* user_numbers);
void check_winning(const int* winning_numbers, int bonus_number, const int* user_numbers);

int main(void) {
    int winning_numbers[LOTTO_SIZE]; 
    int bonus_number;                
    int user_numbers[LOTTO_SIZE];    
    GenRandSeed();
    generate_lotto_numbers(winning_numbers);
    do {
        bonus_number = (rand() % NUM_RANGE) + 1;
        int is_duplicate = 0;
        for (int i = 0; i < LOTTO_SIZE; i++) {
            if (bonus_number == winning_numbers[i]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) break;
    } while (1);
    input_user_numbers(user_numbers);
    printf("\n========================================\n");
    printf("    로또 6/45 당첨 결과 \n");
    printf("========================================\n");
    printf(" 당첨 번호: ");
    for (int i = 0; i < LOTTO_SIZE; i++) {
        printf("%02d ", winning_numbers[i]);
    }
    printf(" (+ 보너스: %02d)\n", bonus_number);
    printf(" 사용자 번호: ");
    for (int i = 0; i < LOTTO_SIZE; i++) {
        printf("%02d ", user_numbers[i]);
    }
    printf("\n----------------------------------------\n");
    check_winning(winning_numbers, bonus_number, user_numbers);

    return 0;
}
void GenRandSeed() {
    srand((unsigned int)(time(NULL)));
}
void generate_lotto_numbers(int* numbers) {
    int i, j;
    int new_number;
    for (i = 0; i < LOTTO_SIZE; i++) {
        do {
            new_number = (rand() % NUM_RANGE) + 1;
            int is_duplicate = 0;
            for (j = 0; j < i; j++) {
                if (new_number == numbers[j]) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) break;
        } while (1);
        *(numbers + i) = new_number;
    }
}
void input_user_numbers(int* user_numbers) {
    printf("\n--- 로또 번호 6개를 입력해주세요 (1-45 범위) ---\n");
    int i, j;
    int input_val;

    for (i = 0; i < LOTTO_SIZE; i++) {
        do {
            printf("%d번째 번호: ", i + 1);
            if (scanf_s("%d", &input_val) != 1) {
                printf("오류: 정수만 입력해주세요.\n");
                while (getchar() != '\n');
                continue;
            }
            if (input_val < 1 || input_val > NUM_RANGE) {
                printf("오류: 번호는 1부터 %d 사이여야 합니다.\n", NUM_RANGE);
                continue;
            }
            int is_duplicate = 0;
            for (j = 0; j < i; j++) {
                if (input_val == user_numbers[j]) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (is_duplicate) {
                printf("오류: 이미 입력한 번호입니다. 중복되지 않게 입력해주세요.\n");
                continue;
            }
            break;
        } while (1);
        *(user_numbers + i) = input_val;
    }
}
void check_winning(const int* winning_numbers, int bonus_number, const int* user_numbers) {
    int match_count = 0;
    int bonus_match = 0;
    for (int i = 0; i < LOTTO_SIZE; i++) {
        for (int j = 0; j < LOTTO_SIZE; j++) {
            if (*(winning_numbers + i) == *(user_numbers + j)) {
                match_count++;
                break;
            }
        }
    }

    if (match_count == 5) {
        for (int i = 0; i < LOTTO_SIZE; i++) {
            if (*(user_numbers + i) == bonus_number) {
                bonus_match = 1;
                break;
            }
        }
    }

    printf("일치한 일반 번호 개수: %d개\n", match_count);

    switch (match_count) {
    case 6:
        printf(" 축하합니다! 1등에 당첨되었습니다! (6개 번호 일치)\n");
        break;
    case 5:
        if (bonus_match) {
            printf(" 축하합니다! 2등에 당첨되었습니다! (5개 번호 일치 + 보너스 번호 일치)\n");
        }
        else {
            printf(" 축하합니다! 3등에 당첨되었습니다! (5개 번호 일치)\n");
        }
        break;
    case 4:
        printf(" 축하합니다! 4등에 당첨되었습니다! (4개 번호 일치)\n");
        break;
    case 3:
        printf(" 축하합니다! 5등에 당첨되었습니다! (3개 번호 일치)\n");
        break;
    default:
        printf(" 아쉽지만 다음 기회에... (낙첨)\n");
        break;
    }
}
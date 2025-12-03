#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 
// 함수: 입력 버퍼 비우기
// 설명: scanf()와 같은 함수가 읽지 않고 남긴 개행 문자(\n) 또는 기타 문자를
//       입력 버퍼에서 모두 제거하여, 이후의 입력 함수(예: fgets())가
//       원치 않는 문자를 바로 읽어들이는 것을 방지합니다.
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // 버퍼의 모든 문자를 읽고 버림
    }
}

int main(void)
{
    char str1[100];
    char str2[100];
    char copy[100];
    char sentence[200];
    char temp[200];

    char* pos;
    char ch;

    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    printf("Enter first string (no spaces): ");
    scanf("%99s", p_str1);
    clear_input_buffer(); // scanf 후 버퍼 비우기

    printf("Enter second string (no spaces): ");
    scanf("%99s", p_str2);
    clear_input_buffer(); // scanf 후 버퍼 비우기

    printf("\n--- Printed strings (using puts) ---\n");
    puts(p_str1);
    puts(p_str2);

    // -------------------------------------------------------------------
    // // Practice #1: 문자열 복사 (strcpy)
    printf("\n--- Practice #1: String Copy (strcpy) ---\n");
    // 설명: str1의 문자열을 copy 배열로 복사합니다.
    strcpy(p_copy, p_str1);
    printf("copy = ");
    puts(p_copy);

    // -------------------------------------------------------------------
    // Practice #2: 문자열 길이 및 연결 (strlen, strcat)
    printf("\n--- Practice #2: String Length and Concatenation (strlen, strcat) ---\n");
    // 설명: strcat을 사용하여 str2의 문자열을 str1의 끝에 연결합니다.
    //       연결 전에 str1이 두 문자열을 모두 담을 수 있는지 확인하여 버퍼 오버플로우를 방지합니다.
    if (strlen(p_str1) + strlen(p_str2) < sizeof(str1)) {
        strcat(p_str1, p_str2);
        printf("After concatenation, str1 = ");
        puts(p_str1);
    }
    else {
        printf("str1 buffer is too small; cannot perform strcat!\n");
    }

    // -------------------------------------------------------------------
    // Practice #3: 문자열 비교 (strcmp)
    printf("\n--- Practice #3: String Comparison (strcmp) ---\n");
    // 설명: 두 문자열 str1과 str2를 사전적(lexicographical) 순서로 비교합니다.
    int cmp = strcmp(p_str1, p_str2);
    if (cmp == 0) {
        printf("str1 and str2 are equal.\n");
    }
    else if (cmp < 0) {
        printf("In lexicographical order, str1 comes before str2.\n");
    }
    else {
        printf("In lexicographical order, str1 comes after str2.\n");
    }

    // -------------------------------------------------------------------
    // Practice: 문자열 길이 (strlen)
    printf("\n--- strlen practice ---\n");
    // 설명: 현재 str1과 str2의 문자열 길이를 출력합니다 (널 문자 제외).
    printf("Length of str1: %zu\n", strlen(p_str1));
    printf("Length of str2: %zu\n", strlen(p_str2));

    // -------------------------------------------------------------------
    // 왜 여기에 이 함수를 넣었는지 작성:
    // fgets()를 사용하기 전에 버퍼를 비워야 합니다.
    // 이전의 scanf("%s") 호출은 개행 문자(\n)를 버퍼에 남겼을 수 있으며,
    // 이 문자가 fgets()에 의해 읽히는 것을 방지하기 위함입니다.
    printf("\n--- Practice: Reading a Sentence (fgets) ---\n");
    printf("\nEnter one sentence (can include spaces): ");
    fgets(p_sentence, sizeof(sentence), stdin);
    printf("\nYou entered (sentence) = ");
    puts(p_sentence);

    // -------------------------------------------------------------------
    // Practice #4: 문자 검색 (strchr)
    printf("\n--- Practice #4: Character Search (strchr) ---\n");
    // 설명: str1에서 사용자가 입력한 문자가 처음 나타나는 위치를 찾습니다.
    printf("\nEnter a character to search for: ");
    // clear_input_buffer()는 이미 fgets()가 개행문자를 읽었으므로 필요하지 않음.
    // 하지만, 만약 이전에 scanf("%c", ...)가 있었다면 필요했을 것임.
    scanf(" %c", &ch); // %c 앞에 공백을 두어 이전 입력의 남아있는 공백 문자를 무시
    clear_input_buffer();

    pos = strchr(p_str1, ch);
    if (pos != NULL) {
        // (long)(pos - p_str1)은 포인터 뺄셈을 통해 0-기반 인덱스를 계산합니다.
        printf("'%c' is at index %ld (0-based) in str1.\n",
            ch, (long)(pos - p_str1));
    }
    else {
        printf("'%c' is not found in str1.\n", ch);
    }

    // -------------------------------------------------------------------
    // Practice #5: 부분 문자열 검색 (strstr)
    printf("\n--- Practice #5: Substring Search (strstr) ---\n");
    // 설명: str2의 문자열이 sentence 내에서 처음 나타나는 위치를 찾습니다.
    pos = strstr(p_sentence, p_str2);
    if (pos != NULL) {
        printf("Found \"%s\" inside sentence.\n",
            p_str2);
        printf("Substring starting from the found position: ");
        puts(pos); // 발견된 위치부터 끝까지 출력
    }
    else {
        printf("Could not find \"%s\" in sentence.\n", p_str2);
    }

    // -------------------------------------------------------------------
    // Practice #6: 문자열 토큰화 (strtok)
    printf("\n--- Practice #6: String Tokenization (strtok) ---\n");
    printf("\n--- strtok practice: split sentence by spaces ---\n");

    // 왜 이 실습에서는 temp에 문자열을 복사하는가?
    // 설명: strtok() 함수는 원본 문자열을 수정합니다 (토큰 구분자를 널 문자(\0)로 대체).
    //       따라서 원본 sentence 배열의 내용을 보존하기 위해, 복사본인 temp 배열에
    //       복사한 후 strtok()을 사용합니다.
    strcpy(p_temp, p_sentence);

    // 설명: temp의 문자열을 공백(" ")을 기준으로 토큰(단어)으로 분리합니다.
    char* token = strtok(p_temp, " \n"); // 공백 및 개행 문자를 구분자로 사용
    int i = 1;
    while (token != NULL) {
        printf("Token %d: ", i++);
        puts(token);
        token = strtok(NULL, " \n"); // 다음 토큰을 얻기 위해 NULL을 전달
    }
    // -------------------------------------------------------------------

    printf("\nProgram finished.\n");
    return 0;
}
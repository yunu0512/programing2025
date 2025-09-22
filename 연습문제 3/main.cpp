#include <stdio.h>

int main() {
    printf("=== Char/String & Escapes ===\n");
    printf("Char : %c, code: %d\n", 'A', 65);
    printf("Message:\n%s\n", "First line\n\tIndented second line\nThird line");
    printf("Quotes: \"double quotes\" and 'single quotes'\n");
    printf("Backslash: \\\n");
    printf("Average: [%8.2f]\n", 87.35f);

    return 0;
}
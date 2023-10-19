#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char c;
    int startOfWord = 1;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        if (startOfWord && isalpha(c)) {
            c = toupper(c);
            startOfWord = 0;
        } else if (c == ' ' || c == '\n') {
            startOfWord = 1;
        }
        putchar(c);
    }

    fclose(file);
    return 0;
}

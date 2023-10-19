#include <stdio.h>

int main() {
    FILE *file;
    char c;
    int wordCount = 0, charCount = 0;

    printf("Input the file name to be opened: ");
    char filename[100];
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        charCount++;
        if (c == ' ' || c == '\n' || c == '\t') {
            wordCount++;
        }
    }

    fclose(file);

    printf("The content of the file %s is:\n", filename);
    file = fopen(filename, "r");
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);

    printf("\nThe number of words in the file %s is: %d\n", filename, wordCount + 1);
    printf("The number of characters in the file %s is: %d\n", filename, charCount);

    return 0;
}

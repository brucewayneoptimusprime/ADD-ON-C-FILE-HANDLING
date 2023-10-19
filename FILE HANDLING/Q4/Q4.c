#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char line[100];
    int lineNum, numLines;

    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    // Count the number of lines in the file
    numLines = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        numLines++;
    }

    fclose(file);

    printf("Enter the line number to replace (1-%d): ", numLines);
    scanf("%d", &lineNum);

    if (lineNum < 1 || lineNum > numLines) {
        printf("Invalid line number.\n");
        return 1;
    }

    printf("Enter the new line: ");
    getchar(); // Consume the newline left by scanf
    fgets(line, sizeof(line), stdin);

    file = fopen("test.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    for (int i = 1; i <= numLines; i++) {
        if (i == lineNum) {
            fprintf(tempFile, "%s", line);
        } else {
            fgets(line, sizeof(line), file);
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Rename the temp file to the original file
    remove("test.txt");
    rename("temp.txt", "test.txt");

    printf("Line %d replaced successfully.\n", lineNum);

    return 0;
}

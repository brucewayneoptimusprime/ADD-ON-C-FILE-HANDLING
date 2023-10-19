#include <stdio.h>

int main() {
    FILE *file;
    char line[100];
    int lineCount = 0;

    printf("Input the file name to be opened: ");
    char filename[100];
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        lineCount++;
    }

    fclose(file);

    printf("The lines in the file %s are: %d\n", filename, lineCount);

    return 0;
}

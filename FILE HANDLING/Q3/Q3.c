#include <stdio.h>

int main() {
    FILE *file;
    char line[100];
    int numLines;

    printf("Input the number of lines to be written: ");
    scanf("%d", &numLines);

    file = fopen("test.txt", "w");

    for (int i = 0; i < numLines; i++) {
        printf("Enter line %d: ", i + 1);
        getchar(); // Consume the newline left by scanf
        fgets(line, sizeof(line), stdin);
        fprintf(file, "%s", line);
    }

    fclose(file);
    return 0;
}

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
};

int main() {
    FILE *file;
    struct Student students[3];
    
    // Initialize the array of structures
    strcpy(students[0].name, "Alice");
    students[0].roll = 101;
    strcpy(students[1].name, "Bob");
    students[1].roll = 102;
    strcpy(students[2].name, "Charlie");
    students[2].roll = 103;

    // Write the array of structures to a file
    file = fopen("students.dat", "wb");
    fwrite(students, sizeof(struct Student), 3, file);
    fclose(file);

    // Read from the file and display on the screen
    file = fopen("students.dat", "rb");
    fread(students, sizeof(struct Student), 3, file);
    fclose(file);

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Roll: %d\n", students[i].name, students[i].roll);
    }

    return 0;
}


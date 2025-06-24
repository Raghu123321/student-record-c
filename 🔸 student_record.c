#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    struct Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student record added!\n");
}

void viewStudents() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;
    printf("\n--- Student Records ---\n");
    while(fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Student\n2. View Students\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 3);
    return 0;
}

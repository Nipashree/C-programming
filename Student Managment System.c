#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[100];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    getchar(); // to consume newline
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully.\n");
}

void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if (!fp) {
        printf("No student records found.\n");
        return;
    }

    printf("\nAll Student Records:\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll No: %d\nName: %s\nMarks: %.2f\n\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if (!fp) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\nStudent Found:\nRoll No: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}

void modifyStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb+");

    if (!fp) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter Roll Number to modify: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
            printf("Enter new name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            printf("Student record updated.\n");
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}

void deleteStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Student record deleted successfully.\n");
    else
        printf("Student not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

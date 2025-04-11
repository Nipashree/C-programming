#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
};

void addPatient() {
    struct Patient p;
    FILE *fp = fopen("patients.dat", "ab");

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    getchar(); // flush newline
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Disease: ");
    getchar();
    fgets(p.disease, sizeof(p.disease), stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("Patient added successfully.\n");
}

void viewPatients() {
    struct Patient p;
    FILE *fp = fopen("patients.dat", "rb");

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("\nAll Patient Records:\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("ID: %d\nName: %s\nAge: %d\nDisease: %s\n\n", p.id, p.name, p.age, p.disease);
    }

    fclose(fp);
}

void searchPatient() {
    int id, found = 0;
    struct Patient p;
    FILE *fp = fopen("patients.dat", "rb");

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\nPatient Found:\nID: %d\nName: %s\nAge: %d\nDisease: %s\n", p.id, p.name, p.age, p.disease);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");

    fclose(fp);
}

void modifyPatient() {
    int id, found = 0;
    struct Patient p;
    FILE *fp = fopen("patients.dat", "rb+");

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("Enter Patient ID to modify: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            printf("Enter new name: ");
            getchar();
            fgets(p.name, sizeof(p.name), stdin);
            p.name[strcspn(p.name, "\n")] = 0;
            printf("Enter new age: ");
            scanf("%d", &p.age);
            printf("Enter new disease: ");
            getchar();
            fgets(p.disease, sizeof(p.disease), stdin);
            p.disease[strcspn(p.disease, "\n")] = 0;

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            printf("Patient record updated.\n");
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");

    fclose(fp);
}

void deletePatient() {
    int id, found = 0;
    struct Patient p;
    FILE *fp = fopen("patients.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            continue;
        }
        fwrite(&p, sizeof(p), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found)
        printf("Patient deleted successfully.\n");
    else
        printf("Patient not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Modify Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: modifyPatient(); break;
            case 5: deletePatient(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

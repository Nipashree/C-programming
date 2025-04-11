#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vehicle {
    char regNumber[20];
    char type[20]; // car, bike, truck
    char owner[100];
    char time[20]; // entry time (e.g., 10:30AM)
};

void addVehicle() {
    struct Vehicle v;
    FILE *fp = fopen("vehicles.dat", "ab");

    printf("Enter Vehicle Registration Number: ");
    scanf("%s", v.regNumber);
    printf("Enter Vehicle Type (Car/Bike/Truck): ");
    scanf("%s", v.type);
    printf("Enter Owner Name: ");
    getchar(); // to remove newline
    fgets(v.owner, sizeof(v.owner), stdin);
    v.owner[strcspn(v.owner, "\n")] = 0;
    printf("Enter Entry Time (e.g., 10:30AM): ");
    scanf("%s", v.time);

    fwrite(&v, sizeof(v), 1, fp);
    fclose(fp);
    printf("Vehicle entry recorded.\n");
}

void viewVehicles() {
    struct Vehicle v;
    FILE *fp = fopen("vehicles.dat", "rb");

    if (!fp) {
        printf("No vehicle records found.\n");
        return;
    }

    printf("\n--- Vehicle Records ---\n");
    while (fread(&v, sizeof(v), 1, fp)) {
        printf("Reg No: %s\nType: %s\nOwner: %s\nTime: %s\n\n", v.regNumber, v.type, v.owner, v.time);
    }

    fclose(fp);
}

void searchVehicle() {
    char reg[20];
    int found = 0;
    struct Vehicle v;
    FILE *fp = fopen("vehicles.dat", "rb");

    if (!fp) {
        printf("No vehicle records found.\n");
        return;
    }

    printf("Enter Registration Number to search: ");
    scanf("%s", reg);

    while (fread(&v, sizeof(v), 1, fp)) {
        if (strcmp(v.regNumber, reg) == 0) {
            printf("\nVehicle Found:\nReg No: %s\nType: %s\nOwner: %s\nTime: %s\n", v.regNumber, v.type, v.owner, v.time);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Vehicle not found.\n");

    fclose(fp);
}

void countByType() {
    struct Vehicle v;
    FILE *fp = fopen("vehicles.dat", "rb");
    int cars = 0, bikes = 0, trucks = 0;

    if (!fp) {
        printf("No vehicle records found.\n");
        return;
    }

    while (fread(&v, sizeof(v), 1, fp)) {
        if (strcmpi(v.type, "car") == 0)
            cars++;
        else if (strcmpi(v.type, "bike") == 0)
            bikes++;
        else if (strcmpi(v.type, "truck") == 0)
            trucks++;
    }

    fclose(fp);
    printf("\n--- Vehicle Count ---\nCars: %d\nBikes: %d\nTrucks: %d\n", cars, bikes, trucks);
}

void deleteVehicle() {
    char reg[20];
    int found = 0;
    struct Vehicle v;
    FILE *fp = fopen("vehicles.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp) {
        printf("No vehicle records found.\n");
        return;
    }

    printf("Enter Registration Number to delete: ");
    scanf("%s", reg);

    while (fread(&v, sizeof(v), 1, fp)) {
        if (strcmp(v.regNumber, reg) == 0) {
            found = 1;
            continue;
        }
        fwrite(&v, sizeof(v), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("vehicles.dat");
    rename("temp.dat", "vehicles.dat");

    if (found)
        printf("Vehicle record deleted.\n");
    else
        printf("Vehicle not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Traffic Management System ---\n");
        printf("1. Add Vehicle Entry\n");
        printf("2. View All Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Count by Type\n");
        printf("5. Delete Vehicle\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: viewVehicles(); break;
            case 3: searchVehicle(); break;
            case 4: countByType(); break;
            case 5: deleteVehicle(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNumber;
    char name[100];
    float balance;
};

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "ab");

    printf("Enter account number: ");
    scanf("%d", &acc.accNumber);
    printf("Enter account holder name: ");
    getchar(); // clear newline
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0; // remove newline
    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);
    printf("Account created successfully.\n");
}

void viewAccounts() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    if (!fp) {
        printf("No accounts found.\n");
        return;
    }

    printf("\nAll Accounts:\n");
    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("Account No: %d\nName: %s\nBalance: %.2f\n\n", acc.accNumber, acc.name, acc.balance);
    }
    fclose(fp);
}

void searchAccount() {
    int accNum, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    if (!fp) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter account number to search: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNumber == accNum) {
            printf("\nAccount Found:\nAccount No: %d\nName: %s\nBalance: %.2f\n", acc.accNumber, acc.name, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void depositWithdraw(int type) {
    int accNum, found = 0;
    float amount;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb+");

    if (!fp) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNumber == accNum) {
            found = 1;
            printf("Current Balance: %.2f\n", acc.balance);
            printf("Enter amount to %s: ", type == 1 ? "deposit" : "withdraw");
            scanf("%f", &amount);

            if (type == 1)
                acc.balance += amount;
            else {
                if (amount > acc.balance) {
                    printf("Insufficient balance.\n");
                    fclose(fp);
                    return;
                }
                acc.balance -= amount;
            }

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            printf("Transaction successful. New Balance: %.2f\n", acc.balance);
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void deleteAccount() {
    int accNum, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter account number to delete: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNumber == accNum) {
            found = 1;
            continue;
        }
        fwrite(&acc, sizeof(acc), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        printf("Account deleted successfully.\n");
    else
        printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccounts(); break;
            case 3: searchAccount(); break;
            case 4: depositWithdraw(1); break;
            case 5: depositWithdraw(0); break;
            case 6: deleteAccount(); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function prototypes
bool login(void);
void displayMenu(void);
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);

// Global variables
const int CORRECT_PIN = 1234;  // Default PIN
float accountBalance = 5000.00;  // Starting balance

int main() {
    int choice;
    float amount;
    bool loggedIn = false;

    printf("=========================================\n");
    printf("     WELCOME TO ATM SIMULATION SYSTEM\n");
    printf("=========================================\n\n");

    // Login verification
    loggedIn = login();

    if (!loggedIn) {
        printf("\nMaximum login attempts exceeded. Access denied!\n");
        printf("Please contact your bank for assistance.\n");
        return 0;
    }

    printf("\nLogin successful! Welcome to your account.\n");

    // Main transaction loop
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkBalance(accountBalance);
                break;

            case 2:
                accountBalance = deposit(accountBalance);
                break;

            case 3:
                accountBalance = withdraw(accountBalance);
                break;

            case 4:
                printf("\nThank you for banking with us!\n");
                printf("Please take your card.\n");
                printf("=========================================\n");
                break;

            default:
                printf("\nInvalid choice! Please select a valid option (1-4).\n");
        }

        if (choice != 4) {
            printf("\nPress Enter to continue...");
            getchar();  // Clear buffer
            getchar();  // Wait for Enter key
        }

    } while (choice != 4);

    return 0;
}

bool login(void) {
    int enteredPin;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == CORRECT_PIN) {
            return true;
        } else {
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;

            if (remaining > 0) {
                printf("Invalid PIN! %d attempt(s) remaining.\n", remaining);
            }
        }
    }

    return false;
}

void displayMenu(void) {
    system("clear");

    printf("=========================================\n");
    printf("             ATM MAIN MENU\n");
    printf("=========================================\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("=========================================\n");
}


void checkBalance(float balance) {
    printf("\n=========================================\n");
    printf("          ACCOUNT BALANCE\n");
    printf("=========================================\n");
    printf("Current Balance: $%.2f\n", balance);
    printf("=========================================\n");
}

float deposit(float balance) {
    float amount;

    printf("\n=========================================\n");
    printf("             DEPOSIT MONEY\n");
    printf("=========================================\n");

    printf("Enter amount to deposit: $");
    scanf("%f", &amount);

    // Validate deposit amount
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return balance;
    }

    balance += amount;
    printf("Deposit successful!\n");
    printf("New balance: $%.2f\n", balance);

    return balance;
}

float withdraw(float balance) {
    float amount;

    printf("\n=========================================\n");
    printf("            WITHDRAW MONEY\n");
    printf("=========================================\n");

    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);

    // Validate withdrawal amount
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return balance;
    }

    // Check sufficient balance
    if (amount > balance) {
        printf("Insufficient balance!\n");
        printf("Your current balance: $%.2f\n", balance);
        printf("Withdrawal amount: $%.2f\n", amount);
        return balance;
    }

    balance -= amount;
    printf("Withdrawal successful!\n");
    printf("Please take your cash: $%.2f\n", amount);
    printf("Remaining balance: $%.2f\n", balance);

    return balance;
}


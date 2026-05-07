#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORY 50
#define FILE_NAME "transactions.txt"

// Structure for a transaction
typedef struct {
    char type[10];      // "Income" or "Expense"
    char category[MAX_CATEGORY];
    float amount;
    char date[12];      // DD-MM-YYYY
} Transaction;

// Dynamic array to store transactions
Transaction *transactions = NULL;
int count = 0;

// Function prototypes
void addTransaction();
void viewTransactions();
void saveTransactions();
void loadTransactions();
void analytics();

int main() {
    int choice;
    loadTransactions();
    
   printf("Welcome to Personal Finance Management System!\n");
    while(1) {
        printf("\n=== Personal Finance Management System ===\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Analytics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1: addTransaction(); break;
            case 2: viewTransactions(); break;
            case 3: analytics(); break;
            case 4: saveTransactions(); free(transactions); printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Add a new transaction
void addTransaction() {
    transactions = (Transaction*)realloc(transactions, (count+1)*sizeof(Transaction));
    printf("Enter type (Income/Expense): ");
    scanf("%s", transactions[count].type);
    getchar();
    printf("Enter category: ");
    fgets(transactions[count].category, MAX_CATEGORY, stdin);
    transactions[count].category[strcspn(transactions[count].category, "\n")] = 0; // remove newline
    printf("Enter amount: ");
    scanf("%f", &transactions[count].amount);
    getchar();
    printf("Enter date (DD-MM-YYYY): ");
    fgets(transactions[count].date, 12, stdin);
    transactions[count].date[strcspn(transactions[count].date, "\n")] = 0; // remove newline
    count++;
    printf("Transaction added successfully!\n");
}

// View all transactions
void viewTransactions() {
    if(count == 0) { printf("No transactions found!\n"); return; }

    printf("\n--- Transactions ---\n");
    printf("%-10s %-20s %-10s %-12s\n", "Type", "Category", "Amount", "Date");
    for(int i=0; i<count; i++) {
        printf("%-10s %-20s %-10.2f %-12s\n", transactions[i].type, transactions[i].category, transactions[i].amount, transactions[i].date);
    }
}

// Save transactions to file
void saveTransactions() {
    FILE *fp = fopen(FILE_NAME, "w");
    if(!fp) { printf("Error saving file!\n"); return; }
    for(int i=0; i<count; i++) {
        fprintf(fp, "%s|%s|%.2f|%s\n", transactions[i].type, transactions[i].category, transactions[i].amount, transactions[i].date);
    }
    fclose(fp);
}

// Load transactions from file
void loadTransactions() {
    FILE *fp = fopen(FILE_NAME, "r");
    if(!fp) return; // No file yet

    char line[100];
    while(fgets(line, sizeof(line), fp)) {
        transactions = (Transaction*)realloc(transactions, (count+1)*sizeof(Transaction));
        sscanf(line, "%[^|]|%[^|]|%f|%s", transactions[count].type, transactions[count].category, &transactions[count].amount, transactions[count].date);
        count++;
    }
    fclose(fp);
}

// Show basic analytics
void analytics() {
    if(count == 0) { printf("No transactions to analyze!\n"); return; }

    float totalIncome = 0, totalExpense = 0;
    char topCategory[MAX_CATEGORY];
    float maxExpense = 0;

    // Count expense per category
    for(int i=0; i<count; i++) {
        if(strcmp(transactions[i].type, "Income")==0) totalIncome += transactions[i].amount;
        else {
            totalExpense += transactions[i].amount;
            if(transactions[i].amount > maxExpense) {
                maxExpense = transactions[i].amount;
                strcpy(topCategory, transactions[i].category);
            }
        }
    }

    printf("\n--- Analytics ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Savings: %.2f\n", totalIncome - totalExpense);
    if(maxExpense > 0) printf("Top Spending Category: %s\n", topCategory);
}

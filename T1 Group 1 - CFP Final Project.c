// Declaration of header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declaration of modularized functions
void setBudgetGoals();
void saveBudgetsToFile();
void loadBudgetsFromFile();
void addExpenses();
void saveExpensesToFile();
void loadExpensesFromFile();
void viewBudgetExpenses();
void deleteBudgetExpenses();
void viewTrends();

typedef struct { // Labels the given data types as Budget
    int category;
    char categoryName[15];
    int amount;
} Budget;

typedef struct { // Labels the given data types as Expense
    int category;
    char categoryName[15];
    int expenseAmount;
} Expense;

Budget budgets[100];   // Array to store budgets
Expense expenses[100]; // Array to store expenses
int budgetCount = 0;   // Count for number of budgets
int expenseCount = 0;  // Count for number of expenses
int totalBudget = 0;   // Total budget
int totalExpenses = 0; // Total expenses
int categoryBudgetCount[5] = {0};  // Number of budget categories
int categoryExpenseCount[5] = {0}; // Number of expense categories

//Main Menu
int main() {
	// Load data from files at program start
    loadBudgetsFromFile();
    loadExpensesFromFile();
    
    int select; // Declaration of variable

	// Output a list of functions user can select from
    while (1) {
        printf("\nWelcome to ExpenseSync's Expense Tracker and Budget Planner!\n");
        printf("Select which function you would like to do (Enter a number from 1-6):\n");
        printf("1.) Set Budget Goals\n");
        printf("2.) Add Expenses\n");
        printf("3.) View Budgets and Expenses\n");
        printf("4.) Delete Budgets/Expenses\n");
        printf("5.) View Trends\n");
        printf("6.) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &select);

	// Switch statement for the list of functions user selects
        switch (select) {
            case 1:
                setBudgetGoals();
                break;
            case 2:
                addExpenses();
                break;
            case 3:
                viewBudgetExpenses(); //  
                break;
            case 4:
                deleteBudgetExpenses(); // 
                break;
            case 5:
                viewTrends();
                break;                                                       
            case 6:  // The program ends if 6 is inputted
                printf("Thank you for using ExpenseSync!\n");
                exit(0);
                break;
            default:  // Error message will be given otherwise
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}



// Function to set budget goals
void setBudgetGoals() {
    int category, amount;
    char ynchoice; // Declaration of variables
    int i, found = 0; // Variable to track if the category is already set
	
	// Ensure budget data is loaded from the file
    loadBudgetsFromFile();
    
    // User selects category
    while (1) { 
        printf("\nSet a budget goal for a category:\n");
        printf("1.) Food\n");
        printf("2.) Rent\n");
        printf("3.) Entertainment\n");
        printf("4.) Projects\n");
        printf("5.) Utilities\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &category);

        // Error message if user input is not between 1-5
        if (category < 1 || category > 5) {
            printf("Invalid category. Please try again.\n");
            continue;
        }

        // User inputs amount
        printf("Input the total amount you want to set in this category (in Php): "); 
        scanf("%d", &amount);
        
        if (amount < 1 || amount > 1000000) {
        	printf("Invalid amount.\n");
        	continue;
		}
		
		
        // Check if category already exists and overwrite if so
        found = 0; // Reset found variable
        for (i = 0; i < budgetCount; i++) {
            if (budgets[i].category == category) {
                totalBudget -= budgets[i].amount;  // Subtract old amount from totalBudget
                budgets[i].amount = amount;  // Overwrite amount if category found
                totalBudget += amount;  // Add new amount to totalBudget
                printf("Budget for %s updated successfully.\n", budgets[i].categoryName);
                found = 1;
                break;
            }
        } 

        // If category not found, add a new budget goal
        if (!found) {
            budgets[budgetCount].category = category;
            budgets[budgetCount].amount = amount;
            totalBudget += amount;

            // Assign category name
            switch (category) {
                case 1:
                    strcpy(budgets[budgetCount].categoryName, "Food");
                    break;
                case 2:
                    strcpy(budgets[budgetCount].categoryName, "Rent");
                    break;
                case 3:
                    strcpy(budgets[budgetCount].categoryName, "Entertainment");
                    break;
                case 4:
                    strcpy(budgets[budgetCount].categoryName, "Projects");
                    break;
                case 5:
                    strcpy(budgets[budgetCount].categoryName, "Utilities");
                    break;
            }
            budgetCount++; // Increment to budget count
        }
		

        // Ask user if they will add more budget goals
        printf("Would you like to set more budget goals? (Y/N): ");
        scanf(" %c", &ynchoice); // Space before %c to consume newline
        if (ynchoice == 'N' || ynchoice == 'n') { // Data saves and goes back to main menu if No
            saveBudgetsToFile();
            printf("Budget goals saved successfully.\n");
            break;
        } else if (ynchoice != 'Y' && ynchoice != 'y') { // Go back to main menu if user doesn't input Yes or No
            printf("Invalid input. Returning to main menu.\n");
            break;
        }
    }
}



// Function to save budgets to "budget_data.txt"
void saveBudgetsToFile() {
    int i; // Declaration of loop counter
    const char *filename = "budget_data.txt";  // Declaration of hardcoded filename
    
    FILE *file = fopen(filename, "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file for saving budgets!\n");
        return;
    }

    // Write each budget category and its amount to the file
    for (i = 0; i < budgetCount; i++) {
        fprintf(file, "%s %d\n", budgets[i].categoryName, budgets[i].amount);
    }

    fclose(file);  // Close the file after writing
    printf("Budgets saved to %s successfully!\n", filename);
}



// Function to load budgets from "budget_data.txt"
void loadBudgetsFromFile() {
    const char *filename = "budget_data.txt";  // Hardcoded filename
    
    FILE *file = fopen(filename, "r");  // Open the file in read mode
    if (file == NULL) {
        printf("No existing budget file found. Starting fresh.\n");
        return;
    }

    budgetCount = 0; // Reset budget count
    totalBudget = 0; // Reset total budget

    // Read each line and store the budget category and amount
    while (fscanf(file, "%s %d", budgets[budgetCount].categoryName, &budgets[budgetCount].amount) == 2) {
        if (strcmp(budgets[budgetCount].categoryName, "Food") == 0){
        	budgets[budgetCount].category = 1;
		} else if (strcmp(budgets[budgetCount].categoryName, "Rent") == 0){
        	budgets[budgetCount].category = 2;
		} else if (strcmp(budgets[budgetCount].categoryName, "Entertainment") == 0){
        	budgets[budgetCount].category = 3;
		} else if (strcmp(budgets[budgetCount].categoryName, "Projects") == 0){
        	budgets[budgetCount].category = 4;
		} else {
        	budgets[budgetCount].category = 5;
		} 
		totalBudget += budgets[budgetCount].amount;  // Add the amount to the total budget
        budgetCount++;  // Increment the count of budget categories
    }

    fclose(file);  // Close the file after reading
    printf("Budgets loaded successfully from %s.\n", filename);
}



// Function to add expenses
void addExpenses() {
    int category, expenseAmount;
    char ynchoice; // Declaration of variables
    int i, found; // Variable to track if the category already exists
	
	// Ensure budget data is loaded from the file
    loadExpensesFromFile();
    
    // User inputs category
    while (1) {
        printf("\nAdd an expense to a category:\n");
        printf("1.) Food\n");
        printf("2.) Rent\n");
        printf("3.) Entertainment\n");
        printf("4.) Projects\n");
        printf("5.) Utilities\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &category);

        // Error message if input is not between 1-5
        if (category < 1 || category > 5) {
            printf("Invalid category. Please try again.\n");
            continue;
        }
        
        // User inputs amount
        printf("Input the total expense amount for this category (in Php): "); 
        scanf("%d", &expenseAmount);

		if ((expenseAmount < 1) || (expenseAmount > 1000000)) {
        	printf("Invalid amount.\n");
        	continue;
		}
		
		
        // Check if category already exists and overwrite if so
        found = 0; // Reset found variable
        for (i = 0; i < expenseCount; i++) {
            if (expenses[i].category == category) {
                totalExpenses -= expenses[i].expenseAmount;  // Subtract old expense
                expenses[i].expenseAmount = expenseAmount;  // Overwrite expense
                totalExpenses += expenseAmount;  // Add new expense amount
                printf("Expense for %s updated successfully.\n", expenses[i].categoryName);
                found = 1;
                break;
            }
        }

        // If category not found, add new expense
        if (!found) {
            expenses[expenseCount].category = category;
            expenses[expenseCount].expenseAmount = expenseAmount;
            totalExpenses += expenseAmount;

            // Assign category name
            switch (category) {
                case 1:
                    strcpy(expenses[expenseCount].categoryName, "Food");
                    break;
                case 2:
                    strcpy(expenses[expenseCount].categoryName, "Rent");
                    break;
                case 3:
                    strcpy(expenses[expenseCount].categoryName, "Entertainment");
                    break;
                case 4:
                    strcpy(expenses[expenseCount].categoryName, "Projects");
                    break;
                case 5:
                    strcpy(expenses[expenseCount].categoryName, "Utilities");
                    break;
            }
            expenseCount++; // Increment to expenses count
        }

        // Ask user if they want to add more expenses
        printf("Would you like to add more expenses? (Y/N): ");
        scanf(" %c", &ynchoice); // Space before %c to consume newline
        if (ynchoice == 'N' || ynchoice == 'n') { // Saves data and goes back to main menu if No
            saveExpensesToFile();
            printf("Expenses saved successfully.\n");
            break;
        } else if (ynchoice != 'Y' && ynchoice != 'y') { // Go back to main menu if user doesn't input Yes or No
            printf("Invalid input. Returning to main menu.\n");
            break;
        }
    }
}




// Function to save expenses to "expenses_data.txt"
void saveExpensesToFile() {
    int i; // Declaration of loop counter
    const char *filename = "expenses_data.txt";  // Declaration of hardcoded filename
    
    FILE *file = fopen(filename, "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file for saving expenses!\n");
        return;
    }

    // Write each expense category and its amount to the file
    for (i = 0; i < expenseCount; i++) {
        fprintf(file, "%s %d\n", expenses[i].categoryName, expenses[i].expenseAmount);
    }

    fclose(file);  // Close the file after writing
    printf("Expenses saved to %s successfully!\n", filename);
}



// Function to load expenses from "expenses_data.txt"
void loadExpensesFromFile() {
    const char *filename = "expenses_data.txt";  // Hardcoded filename
    
    FILE *file = fopen(filename, "r");  // Open the file in read mode
    if (file == NULL) {
        printf("No existing expense file found. Starting fresh.\n");
        return;
    }

    expenseCount = 0; // Reset expense count
    totalExpenses = 0; // Reset total expenses

    // Read each line and store the expenses category and amount
    while (fscanf(file, "%s %d", expenses[expenseCount].categoryName, &expenses[expenseCount].expenseAmount) == 2) {
    	if (strcmp(expenses[expenseCount].categoryName, "Food") == 0){
        	expenses[expenseCount].category = 1;
		} else if (strcmp(expenses[expenseCount].categoryName, "Rent") == 0){
        	expenses[expenseCount].category = 2;
		} else if (strcmp(expenses[expenseCount].categoryName, "Entertainment") == 0){
        	expenses[expenseCount].category = 3;
		} else if (strcmp(expenses[expenseCount].categoryName, "Projects") == 0){
        	expenses[expenseCount].category = 4;
		} else {
        	expenses[expenseCount].category = 5;
		} 
        totalExpenses += expenses[expenseCount].expenseAmount;  // Add the amount to the total expenses
        expenseCount++;  // Increment the count of expense categories
    }

    fclose(file);  // Close the file after reading
    printf("Expenses loaded successfully from %s.\n", filename);
}



// Function to display all the available budgets and expenses saved
void viewBudgetExpenses() {
    int i; // Declaration of loop counter

    printf("\n------------- Budgets ------------\n");
    if (budgetCount == 0) { // Check if budgets exist
        printf("No budgets to display.\n"); // Prints if there are no budget inputs
    } else {
        printf("----------------------------------\n");
        printf("| %-15s | %-10s |\n", "Category", "Amount (Php)");
        printf("----------------------------------\n");
        for (i = 0; i < budgetCount; i++) { // Loop through budget inputs while printing table
            printf("| %-15s | %-12d |\n", budgets[i].categoryName, budgets[i].amount);
        }
        printf("----------------------------------\n");
        printf("Total Budget:       %-1d Php\n", totalBudget);
    }

    printf("\n-------------- Expenses ----------\n");
    if (expenseCount == 0) { // Check if expenses exist
        printf("No expenses to display.\n"); // Prints if there are no expense inputs
    } else {
        printf("----------------------------------\n");
        printf("| %-15s | %-10s |\n", "Category", "Amount (Php)");
        printf("----------------------------------\n");
        for (i = 0; i < expenseCount; i++) { // Loop through expense inputs while printing table
            printf("| %-15s | %-12d |\n", expenses[i].categoryName, expenses[i].expenseAmount);
        }
        printf("----------------------------------\n");
        printf("Total Expenses:     %-1d Php\n", totalExpenses);
    }
}



// Function to delete budgets or expenses from files
void deleteBudgetExpenses() {
    int choice, index, i; // Declaration of variables and loop counter

    // User selects category to delete
    printf("\nWhat would you like to delete?\n");
    printf("1.) A budget\n");
    printf("2.) An expense\n");
    printf("3.) None of the above\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

	// If user wishes to delete budgets:
    if (choice == 1) { // Delete a budget
        if (budgetCount == 0) { // Display if there are no budgets
            printf("\nNo budgets available to delete.\n");
            return;
        }

        // Print table of budgets for user to view
        printf("\nList of Budgets:\n");
        printf("--------------------------------------\n");
        printf("| %-20s | %-10s |\n", "Category", "Amount (Php)");
        printf("--------------------------------------\n");
        for (i = 0; i < budgetCount; i++) {
            printf("| %-20s | %-10d |\n", budgets[i].categoryName, budgets[i].amount);
        }
        printf("--------------------------------------\n");

        // User selects index of budget to delete
        printf("\nEnter the number corresponding to the budget you want to delete (1-%d): ", budgetCount);
        scanf("%d", &index);
        index--; // Convert user's 1-based index to 0-based index

        if (index >= 0 && index < budgetCount) {
            // Subtract deleted budget from total budget
            totalBudget -= budgets[index].amount;

            // Shift remaining budgets 
            for (i = index; i < budgetCount - 1; i++) {
                budgets[i] = budgets[i + 1];
            }
            budgetCount--; // Decrement to budget count

            saveBudgetsToFile(); // Save changes to file
            printf("\nBudget deleted successfully.\n");
        } else {
            printf("\nInvalid index.\n"); // Error message for invalid input
        }

	// If user wishes to delete expenses:
    } else if (choice == 2) { // Delete an expense
        if (expenseCount == 0) { // Display if there are no expenses
            printf("\nNo expenses available to delete.\n");
            return;
        }

        // Print table of expenses for user to view
        printf("\nList of Expenses:\n");
        printf("--------------------------------------\n");
        printf("| %-20s | %-10s |\n", "Category", "Amount (Php)");
        printf("--------------------------------------\n");
        for (i = 0; i < expenseCount; i++) {
            printf("| %-20s | %-10d |\n", expenses[i].categoryName, expenses[i].expenseAmount);
        }
        printf("--------------------------------------\n");

        // User selects index of expense to delete
        printf("\nEnter the number corresponding to the expense you want to delete (1-%d): ", expenseCount);
        scanf("%d", &index);
        index--; // Convert user's 1-based index to 0-based index

        if (index >= 0 && index < expenseCount) {
            // Subtract deleted expense from total expenses
            totalExpenses -= expenses[index].expenseAmount;

            // Shift remaining expenses 
            for (i = index; i < expenseCount - 1; i++) {
                expenses[i] = expenses[i + 1];
            }
            expenseCount--; // Decrement to expense count

            saveExpensesToFile(); // Save changes to file
            printf("\nExpense deleted successfully.\n");
        } else {
            printf("\nInvalid index.\n"); // Error message for invalid input
        }

	// If user wishes to not delete:
    } else if (choice == 3) { // Return to main menu
        printf("\nReturning to main menu.\n");
    } else { 
        printf("\nInvalid choice. Returning to main menu.\n"); // Error message for invalid input
    }
}



void viewTrends() {
    int i, j; // Declaration of variables

    // Load budgets and expenses from files
    loadBudgetsFromFile("budget_data.txt");
    loadExpensesFromFile("expenses_data.txt");

    // Display total budgets and expenses
    printf("\n============================ Trends ============================\n");
    printf("Total Budgets: %d Php\n", totalBudget);
    printf("Total Expenses: %d Php\n", totalExpenses);

    // Print table showing budgets split into percentages of total budget
    printf("\n-- Budget Distribution by Category ---\n");
    if (budgetCount == 0) {  // Check if there are no budgets
        printf("No budgets to display.\n");
    } else {
        printf("| %-20s | %-12s |\n", "Category", "Percentage");
        printf("--------------------------------------\n");
        for (i = 0; i < budgetCount; i++) {
            double percentage = ((double)budgets[i].amount / totalBudget) * 100;
            printf("| %-20s | %-12.2f |\n", budgets[i].categoryName, percentage);
        }
        printf("--------------------------------------\n");
    }

    // Print table showing expenses split into percentages of total expenses
    printf("\n-- Expense Distribution by Category --\n");
    if (expenseCount == 0) {  // Check if there are no expenses
        printf("No expenses to display.\n");
    } else {
        printf("| %-20s | %-12s |\n", "Category", "Percentage");
        printf("--------------------------------------\n");
        for (i = 0; i < expenseCount; i++) {
            double percentage = ((double)expenses[i].expenseAmount / totalExpenses) * 100;
            printf("| %-20s | %-12.2f |\n", expenses[i].categoryName, percentage);
        }
        printf("--------------------------------------\n");
    }
    
	printf("\n--------------------------- Comparison: Budgets vs Expenses ---------------------------\n");
    
	if ((budgetCount == 0) || (expenseCount == 0)){  // Check if there are no budgets or expenses 
        printf("No comparisons to display.\n");
	} else {
		// Print table comparing budgets to expenses and giving notification
	    printf("| %-20s | %-10s | %-10s | %-35s |\n", "Category", "Budget", "Expense", "Notification");
	    printf("---------------------------------------------------------------------------------------\n");

		// For statement to match budget count with expense count
	    for (i = 0; i < budgetCount; i++) {
	        int budgetAmount = budgets[i].amount;
	        int expenseAmount = 0;
	
	        // Find matching expense category for budget
	        for (j = 0; j < expenseCount; j++) {
	            if (strcmp(budgets[i].categoryName, expenses[j].categoryName) == 0) {
	                expenseAmount += expenses[j].expenseAmount;  // Add expenses for the same category
	            }
	        }
	
	        // Output of notifications depending on difference between budgets and expenses
	        char notification[30];
	        if (expenseAmount > budgetAmount) {  // Prints if expenses are greater than budget
	            strcpy(notification, "Warning! Expenses exceed budget.");
	        } else {  // Prints if expenses are below budget
	            strcpy(notification, "Your expenses are below budget.");
	        }
	
	        // Prints the category, budget, expense, and notification per input in table
	        printf("| %-20s | %-10d | %-10d | %-35s |\n", budgets[i].categoryName, budgetAmount, expenseAmount, notification);
		}	
	    printf("---------------------------------------------------------------------------------------\n");
	}
}

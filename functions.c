#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to transfer money between two customers.
bool transfer_money(struct customer *sender, struct customer *receiver, double amount){

    // Making sure that the customers are invalid.
    if (sender == NULL || receiver == NULL){
        printf("Error: Invalid sender or receiver.\n");
        return 0;
    }

    // Making sure that the amount is > 0.
    if (amount <= 0){
        printf("Error: Transfer amount must be positive.\n");
        return 0;
    }

    // Making sure that the sender have an enough money.
    if (amount > sender->balance){
        printf("Error: You don't have enough money.\n");
        return 0;
    }

    // Making sure that the customer isn't a child.
    if (sender->id == receiver->id) {
        printf("Error: Cannot transfer to the same person.\n");
        return 0;
    }
    
    // If all of these doesn't exist, transfer the money.
    sender->balance -= amount;
    receiver->balance += amount;

    // Printing transfer details.
    printf("Transfer sucsessful.\n");
    printf("From: %s (ID: %d)\n", sender->name, sender->id);
    printf("To: %s (ID: %d)\n", receiver->name, receiver->id);
    printf("Amount: $%.2f\n", amount);
    printf("New balance - %s: $%.2f\n", sender->name, sender->balance);
    printf("New balance - %s: $%.2f\n", receiver->name, receiver->balance);

    return 1;
}

// Function to withdraw money from a customer's account.
bool withdrawMoney(struct customer *drawer, double amount) {
    // Making sure that the customer is invalid.
    if (drawer == NULL) {
        printf("Error: Invalid customer\n");
        return 0;
    }
    // Making sure that the amount is > 0.
    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive\n");
        return 0;
    }
    // Making sure that the sender have an enough money.
    if (drawer->balance < amount) {
        printf("Error: You don't have enough money.\n");
        return 0;
    }
    
    // If all of these doesn't exist, transfer the money, Perform the withdrawal.
    drawer->balance -= amount;
    
    // Print withdrawal details.
    printf("Withdrawal successful!\n");
    printf("From: %s (ID: %d)\n", drawer->name, drawer->id);
    printf("Amount withdrawn: $%.2f\n", amount);
    printf("New balance: $%.2f\n", drawer->balance);
    
    return 1;
}
